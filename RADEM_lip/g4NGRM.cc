//
/// \file g4
/// \brief Main program for g4RADEM
//   author: Hualin Xiao (hualin.xiao@psi.ch)
//   History:
//
//   Jan. 01st, 2016:
//   version 1.0
//
//   modification history:
//
//   2017.05.28: replace the mass model with the gdml files from Marco
//
//
//   
//

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"

#include "G4UImanager.hh"
#include "G4VUserPhysicsList.hh"
#include "FTFP_BERT.hh"
#include "QGSP_BIC.hh"
//#include "FTFP_BERT.hh"
//FTFP_BERT.hh"
#include "time.h"

#include "G4PhysListFactory.hh"

//#include "DetectorConstruction.hh"
#include "SpaceDetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "AnalysisManager.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

#ifdef G4VIS_USE
#include "G4VisExecutive.hh"
#endif

#ifdef G4UI_USE
#include "G4UIExecutive.hh"
#endif





void Help() 
{
    G4cout<<"MCP GEANT4 Simulation package"<<G4endl;
        G4cout<<"Usage:"<<G4endl
        <<"./g4MCP [OPTIONS] -gdml <gdml file> -m run.mac  -o OUTPUT"<<G4endl;
    G4cout<<"Options:"<<G4endl
        <<" -i                  <input.root> "<<G4endl
        <<"                     Read incident particle information from input.root."<<G4endl
        <<"                     The structure of the root file is defined in t2sim.h ."<<G4endl
        <<" -h                  print help information"<<G4endl;
}

int main(int argc,char **argv) 
{

    G4String outputFilename="run0.root";
    G4String macFilename;
    G4String inputFilename;
    G4String gdmlFile="GDML_mcp/Setup.gdml";

    if(argc==1)Help();
    
    int s=0;
    G4String sel;
    while(s<argc-1)
    {

        sel=argv[++s];
        if(sel=="-h"||sel=="--help"||sel=="--h")
        {
            Help();
            return 0;

        }
        else if(sel=="-o")
        {
            outputFilename=argv[++s];
            if(!outputFilename.contains(".root"))
            {
                Help();
                return 0;
            }
        }
        else if(sel=="-m")
        {
            macFilename=argv[++s];
            if(!macFilename.contains(".mac"))
            {
                Help();
                return 0;
            }
        }
        else if(sel=="-gdml")
        {

            gdmlFile=argv[++s];
            if(!gdmlFile.contains(".gdml"))
            {
                Help();
                return 0;
            }
        }
        else if(sel=="-i")
        {
            inputFilename=argv[++s];
            if(!inputFilename.contains(".root"))
            {
                Help();
                return 0;
            }
        }

    }

    time_t DateTime = time( NULL );
    CLHEP::HepRandom::setTheSeed( DateTime );

    AnalysisManager* analysisManager = AnalysisManager::GetInstance();
    //CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);	
    analysisManager->SetOutputFileName(outputFilename);

#ifdef G4MULTITHREADED  
    G4MTRunManager * runManager = new G4MTRunManager();
    G4int nThreads = G4Threading::G4GetNumberOfCores()-1;
    runManager->SetNumberOfThreads(nThreads);
#else
    G4RunManager * runManager = new G4RunManager(); 
#endif


    G4cout<<"Gdml file: "<<gdmlFile<<G4endl;

    //DetectorConstruction* detConstruction = new DetectorConstruction(gdmlFile);
    SpaceDetectorConstruction* detConstruction = new SpaceDetectorConstruction();


    G4cout<<"Initializing detector"<<G4endl;
    runManager->SetUserInitialization(detConstruction);



    G4cout<<"Initializing physicslist"<<G4endl;
//    G4VUserPhysicsList* physlist = new QGSP_BIC;
    //choose of physics model: http://ivana.home.cern.ch/ivana/ED-Geant4-2014/presentations/X-1-physics_lists.pdf
    //G4VUserPhysicsList* physics = new FTFP_BERT;

   G4String plname = "QGSP_BIC_EMY";  // set however you like ...
   G4PhysListFactory factory;
   G4VModularPhysicsList* physlist = factory.GetReferencePhysList(plname);

//    polarPhysicsList *physlist=new polarPhysicsList();
    runManager->SetUserInitialization(physlist);


    G4cout<<"Initializing primary generation"<<G4endl;
    PrimaryGeneratorAction *primarygen=new PrimaryGeneratorAction();
    runManager->SetUserAction(primarygen);
    if(inputFilename!="")primarygen->SetParticleSourceFile(inputFilename);

    G4cout<<"Initializing run action"<<G4endl;
    runManager->SetUserAction(new RunAction());
    EventAction* evtAction = new EventAction();
    G4cout<<"Initializing event action"<<G4endl;
    runManager->SetUserAction(evtAction);
    G4cout<<"Initializing stepping action"<<G4endl;
    runManager->SetUserAction(new SteppingAction());


#ifdef G4VIS_USE
    G4VisManager* visManager = new G4VisExecutive;
    visManager->Initialize();
#endif


    if (macFilename=="") 
    {
#ifdef G4UI_USE
        G4UIExecutive * ui = new G4UIExecutive(argc,argv,"qt");
        ui->SessionStart();
        delete ui;
#endif
    } else {      
          G4UIExecutive * ui = new G4UIExecutive(argc,argv,"tcsh");

        G4UImanager* UImanager = G4UImanager::GetUIpointer();
        G4String command = "/control/execute "; 
        G4String fileName = macFilename; 
        G4cout<<"Applying command: "<<command+fileName<<G4endl;
        UImanager->ApplyCommand(command+fileName);
        delete ui;

    }


#ifdef G4VIS_USE
    delete visManager;
#endif
    analysisManager->WriteMacros(macFilename);

    delete runManager;
    G4cout<<"Output filename: "<<outputFilename<<G4endl;

    return 0;
}
