/***************************************************************
 * descriptions of AnalysisManager
 * Author  : Hualin Xiao (hualin.xiao@psi.ch)
 * Date    : May., 2016
 * Version : 1.10
 ***************************************************************/
#include <fstream>
#include "TFile.h"
#include "TTree.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TString.h"
#include "TNamed.h"

#include "G4ThreeVector.hh"
#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4RunManager.hh"
#include "G4Event.hh"
#include "G4Run.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4UnitsTable.hh"

#include "G4SystemOfUnits.hh"


#include "PrimaryGeneratorAction.hh"

#include "AnalysisManager.hh"
#include "AnalysisMessenger.hh"

AnalysisManager* AnalysisManager::fManager = 0;
AnalysisManager* AnalysisManager::GetInstance()
{
    if(!fManager) {
        fManager = new AnalysisManager();
    }
    return fManager;
}	
AnalysisManager::AnalysisManager() 
{
    fStoreTree=true;
    fStoreHist=true;
    fStoreTrack=true;
    fNbSD=0;

    fAnalysisMessenger=new AnalysisMessenger(this);
}
void AnalysisManager::BookTree()
{
    G4cout<<"Booking Tree: event"<<G4endl;

    fTree=new TTree("event","event");
    fTree->Branch("event_id",&fEventID,"event_id/I");
    fTree->Branch("source_pos",source_pos,"source_pos[3]/D");    
    fTree->Branch("source_dir",source_dir,"source_dir[3]/D");    
    fTree->Branch("source_kine",&source_kine,"source_kine/D");    

    for(int i=0;i<fNbSD;i++)
    {
        G4cout<<"Booking leaf for Sensitive Volume:"<<fSDNameList[i].Data()<<G4endl;
        char *str_var=Form("%s",fSDNameList[i].Data());
        char *str_var2=Form("%s/D",fSDNameList[i].Data());
        fTree->Branch(str_var,&fEdepSum[i],str_var2);
    }
    fTree->SetAutoSave(10000);
    fStoreTree=true;
}
void AnalysisManager::SetLeavesForTracks()
{
    if(!fStoreTrack||!fStoreTree)return;
    fTree->Branch("ntrack",&ntrack,"ntrack/I");    
    fTree->Branch("x",x,"x[ntrack]/D");    
    fTree->Branch("y",y,"y[ntrack]/D");    
    fTree->Branch("z",z,"z[ntrack]/D");    
    fTree->Branch("dx",dx,"dx[ntrack]/D");    
    fTree->Branch("dy",dy,"dy[ntrack]/D");    
    fTree->Branch("dz",dz,"dz[ntrack]/D");   
    fTree->Branch("pdg",pdg,"pdg[ntrack]/I");    
    fTree->Branch("energy",energy,"energy[ntrack]/D");    
    fTree->Branch("enter",enter,"enter[ntrack]/I");    
    fTree->Branch("escape",escape,"escape[ntrack]/I");    
    fTree->Branch("SD_id",SD_id,"SD_id[ntrack]/I");    
    fTree->Branch("parent_id",parent_id,"parent_id[ntrack]/I");    
    fTree->Branch("time",time,"time[ntrack]/D");    
    fStoreTrack=true;

}
void AnalysisManager::BookHistograms()
{
    h_source_kine=new TH1F("h_source_kine",
            "kinetic energy of primary particles; kinetic energy (MeV); counts ",100,0,1);
    //h_source_kine->SetBit(TH1::kCanRebin);
    G4cout<<"Booking histograms"<<G4endl;

    char *axis[3]={"x","y","z"};
    for(int i=0;i<3;i++)
    {
        h_source_pos[i]=new TH1F(Form("h_source_pos%d",i),Form("source %s axis; %s (mm);  Counts",axis[i],axis[i]),100,-1,1);
        h_source_dir[i]=new TH1F(Form("h_source_dir%d",i),Form("source momentum direction (%s) ; %s; Counts",
                    axis[i],axis[i]),100,-1,1);
     //   h_source_pos[i]->SetBit(TH1::kCanRebin);
      //  h_source_dir[i]->SetBit(TH1::kCanRebin);
    }

    if(fNbSD==0)return;
   // h_edep=new TH1F *[fNbSD];
    for(int i=0;i<fNbSD;i++)
    {
        
        
        h_edep[i]=new TH1F(Form("h_edep_%s",fSDNameList[i].Data()),
                Form("h_edep_%d; Edep (keV); Entries;",i), 200, 0, 200);
       // h_edep[i]->SetBit(TH1::kCanRebin);
    }
    fStoreHist=true;

}

void AnalysisManager::BeginOfRunAction(const G4Run *run)
{

    OpenFile();

    fNbSD=fSDNameList.size();
    G4cout<<"Number of SD:"<<fNbSD<<G4endl;
    for(int i=0;i<fNbSD;i++)
    {
        G4cout<<"Sensitive Volume :"<<i<<" "<<fSDNameList[i].Data()<<G4endl;
    }
    if(fStoreHist)BookHistograms();
    if(fStoreTree)
    {
        BookTree();
        if(fStoreTrack)SetLeavesForTracks();
    }
    G4cout<<"start simulation"<<G4endl;
}

void AnalysisManager::EndOfRunAction(const G4Run *run)
{
    Dump();
}

void AnalysisManager::BeginOfEventAction(const G4Event *event)
{
    is_effective=false;
    for (G4int i=0; i<fNbSD; i++) fEdepSum[i] = 0.0;
    if(!fStoreTrack)return;
    ntrack=0;
    for(int i=0;i<kMaxTracks;i++)
    {
        x[i]=y[i]=z[i]=-1000;
        dx[i]=dy[i]=dz[i]=-1000;
        pdg[i]=0;
        SD_id[i]=-1;
        parent_id[i]=-1;
        time[i]=0;
    }
}
void AnalysisManager::EndOfEventAction(const G4Event *event)
{

    fEventID=event->GetEventID();
    if(fEventID%10000==0)G4cout<<"End of Event: "<<fEventID<<G4endl;

    //write particle information to the tree

    G4RunManager* runManager = G4RunManager::GetRunManager();
    PrimaryGeneratorAction* primaryAction = (PrimaryGeneratorAction*) runManager->GetUserPrimaryGeneratorAction();
    G4ThreeVector position,direction;
    G4double energy;

    primaryAction->GetGPS(position,direction,energy);
    source_pos[0]=position.getX();
    source_pos[1]=position.getY();
    source_pos[2]=position.getZ();
    source_dir[0]=direction.getX();
    source_dir[1]=direction.getY();
    source_dir[2]=direction.getZ();
    source_kine=energy/1000.;

    if(fTree&&fStoreTree&&is_effective)fTree->Fill();
    if(!fStoreHist)return;

    h_source_kine->Fill(energy/1000.);
    //keV to MeV
    h_source_pos[0]->Fill(source_pos[0]);
    h_source_pos[1]->Fill(source_pos[1]);
    h_source_pos[2]->Fill(source_pos[2]);
    h_source_dir[0]->Fill(source_dir[0]);
    h_source_dir[1]->Fill(source_dir[1]);
    h_source_dir[2]->Fill(source_dir[2]);

    //only store 10k events to verify the information of primary particles

    for(int i=0;i<fNbSD;i++)
    {
        if(fEdepSum[i]>0&&h_edep[i]) h_edep[i]->Fill(fEdepSum[i]);
    }

}
//Stepping Action

void AnalysisManager::SteppingAction(const G4Step *aStep)
{

    if(fNbSD==0)return;
    //nothing to do

    const G4Track* track = aStep->GetTrack();
    G4String volName; 

    if (track->GetVolume()) volName =  track->GetVolume()->GetName(); 

    int det_id=-1;


    for(int i=0;i<fNbSD;i++)
    {
        if(volName==fSDNameList[i].Data())det_id=i;
    }
    if(det_id<0)return;
    //nothing to do

    G4double edep=aStep->GetTotalEnergyDeposit()/keV;
    if (edep > 0.0)AddEnergy(det_id, edep);

    if(!fStoreTrack)return;

    G4StepPoint* point1 = aStep->GetPreStepPoint();
    G4StepPoint* point2 = aStep->GetPostStepPoint();

    G4int parent=track->GetParentID(); //

    bool is_crossing_boundary=false;
	enter[ntrack]=0;
	escape[ntrack]=0;
    if (point1->GetStepStatus() == fGeomBoundary) 
    {
        //leave MCP0 or MCP1
        if(det_id>=0)
        {
            is_crossing_boundary=true;
            enter[ntrack]=1;
        }

    }
    if (point2->GetStepStatus() == fGeomBoundary) 
    {
        //leave MCP0 or MCP1
        if(det_id>=0)
        {
            is_crossing_boundary=true;
            escape[ntrack]=-1;
        }
    }

    if(is_crossing_boundary)
    {

        //cross boundary
        //track 
        x[ntrack]=track->GetPosition().x()/mm;
        y[ntrack]=track->GetPosition().y()/mm;
        z[ntrack]=track->GetPosition().z()/mm;

        dx[ntrack]=track->GetMomentumDirection().x();
        dy[ntrack]=track->GetMomentumDirection().y();
        dz[ntrack]=track->GetMomentumDirection().z();

        pdg[ntrack]=track->GetDefinition()->GetPDGEncoding();
        energy[ntrack]=track->GetKineticEnergy()/MeV;
        SD_id[ntrack]=det_id;
        parent_id[ntrack]=parent;
        time[ntrack]=track->GetGlobalTime()/ns;
        ntrack++;
    }

}



AnalysisManager::~AnalysisManager()
{
    /*
    if(fTree)delete fTree;
    if(fStoreHist)
    {
        for(int i=0;i<fNbSD;i++)if(h_edep[i]) delete h_edep[i];

        if(h_source_kine)delete h_source_kine;
        for(int i=0;i<3;i++)
        {
            if(h_source_dir[i])delete h_source_dir[i];
            if(h_source_pos[i]) delete h_source_pos[i];
        }
    }
    if(fTFile)delete fTFile;
    if(fManager)delete fManager;
    fManager = 0;
    */

}
void AnalysisManager::OpenFile()
{
    fTFile = new TFile(outputFilename.Data(),"recreate");
}
void AnalysisManager::Dump() 
{
    fTFile->cd();

    if(fTree)fTree->Write();

    if(!fStoreHist)return;
    //direction and position of primary particles
    h_source_pos[0]->Write();
    h_source_pos[1]->Write();
    h_source_pos[2]->Write();
    h_source_dir[0]->Write();
    h_source_dir[1]->Write();
    h_source_dir[2]->Write();
    h_source_kine->Write();
    for(int i=0;i<fNbSD;i++)
    {
        if(h_edep[i]) h_edep[i]->Write();
    }


}


void AnalysisManager::WriteMacros(G4String macfilename)
{
  /*  if(macfilename=="")return;
    ifstream infile(macfilename.data()); 

    if(!infile.good())
    { 
        G4cout<<"can not open file..."<<G4endl; 
        return ;
    } 
    G4String macros;
    std::string line;
    while(std::getline(infile,line))
    {
        macros+=line+"\n";
    }
    TNamed cmd;
    cmd.SetTitle(macros);
    if(fTFile)
    {
        fTFile->cd();
        cmd.Write("macfile");
    }
    infile.close(); 
	*/
}
/*

  case 1   : return 22;       // photon
      case 25  : return -2112;    // anti-neutron
      case 2   : return -11;      // e+
      case 26  : return -3122;    // anti-Lambda
      case 3   : return 11;       // e-
      case 27  : return -3222;    // Sigma-
      case 4   : return 12;       // e-neutrino (NB: flavour undefined by Geant)
      case 28  : return -3212;    // Sigma0
      case 5   : return -13;      // mu+
      case 29  : return -3112;    // Sigma+ (PB)
      case 6   : return 13;       // mu-
      case 30  : return -3322;    // Xi0
      case 7   : return 111;      // pi0
      case 31  : return -3312;    // Xi+
      case 8   : return 211;      // pi+
      case 32  : return -3334;    // Omega+ (PB)
      case 9   : return -211;     // pi-
      case 33  : return -15;      // tau+
      case 10  : return 130;      // K long
      case 34  : return 15;       // tau-
      case 11  : return 321;      // K+
      case 35  : return 411;      // D+
      case 12  : return -321;     // K-
      case 36  : return -411;     // D-
      case 13  : return 2112;     // n
      case 37  : return 421;      // D0
      case 14  : return 2212;     // p
      case 38  : return -421;     // D0
      case 15  : return -2212;    // anti-proton
      case 39  : return 431;      // Ds+
      case 16  : return 310;      // K short
      case 40  : return -431;     // anti Ds-
      case 17  : return 221;      // eta
      case 41  : return 4122;     // Lamba_c+
      case 18  : return 3122;     // Lambda
      case 42  : return 24;       // W+
      case 19  : return 3222;     // Sigma+
      case 43  : return -24;      // W-
      case 20  : return 3212;     // Sigma0
      case 44  : return 23;       // Z
      case 21  : return 3112;     // Sigma-
      case 45  : return 0;        // deuteron
      case 22  : return 3322;     // Xi0
      case 46  : return 0;        // triton
      case 23  : return 3312;     // Xi-
      case 47  : return 0;        // alpha
      case 24  : return 3334;     // Omega- (PB)
      case 48  : return 0; 
	  */
