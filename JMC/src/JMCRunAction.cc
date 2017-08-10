//Patryk Socha
//16.05.2017

#include "JMCRunAction.hh"
#include "JMCPrimaryGeneratorAction.hh"
#include "JMCDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "TFile.h"
#include "TSystem.h"
#include "TThread.h"

JMCRunAction::JMCRunAction() : G4UserRunAction(), fEdep(0.0), fHits(0), fNIEL(0.0), tree(0)
{
	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->RegisterAccumulable(fEdep);
	accumulableManager->RegisterAccumulable(fHits);
	accumulableManager->RegisterAccumulable(fNIEL);
	tree = new TTree("Tree", "Tree");
}

JMCRunAction::~JMCRunAction()
{}

void JMCRunAction::BeginOfRunAction(const G4Run*)
{
	G4RunManager::GetRunManager()->SetRandomNumberStore(false);

	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Reset();
}

void JMCRunAction::EndOfRunAction(const G4Run* run)
{
	gROOT->Reset();
//	ROOT::EnableThreadSafety();
//	TThread::Initialize();

	G4int nofEvents = run->GetNumberOfEvent();
	if(nofEvents == 0)
		return;

	G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
	accumulableManager->Merge();

	G4double edep = fEdep.GetValue();
	G4int hits = fHits.GetValue();
	G4double niel = fNIEL.GetValue();

	const JMCDetectorConstruction* detectorConstruction = static_cast<const JMCDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
	G4double mass = detectorConstruction->GetScoringVolume()->GetMass();
	G4double dose = edep/mass;
	G4double nielDose = niel/mass;

	const JMCPrimaryGeneratorAction* generatorAction = static_cast<const JMCPrimaryGeneratorAction*>(G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
	G4String runCondition;
	if(generatorAction)
	{
		const G4GeneralParticleSource* particleGun = generatorAction->GetParticleGun();
		runCondition += particleGun->GetParticleDefinition()->GetParticleName();
		runCondition += " of ";
//		G4double particleEnergy = particleGun->GetParticleEnergy();
//		runCondition += G4BestUnit(particleEnergy, "Energy");
	}

	if(IsMaster()) 
	{
		G4cout << G4endl << "--------------------End of Global Run-----------------------";
	}
  	else
	{
		G4cout << G4endl << "--------------------End of Local Run------------------------";
	}
	G4cout
     << G4endl
     << " The run consists of " << nofEvents << " "<< runCondition
     << G4endl
     << " Cumulated dose per run, in scoring volume : " 
     << G4BestUnit(dose,"Dose") << " in " << hits << " number of hits."
     << G4endl
     << " Cumulated NIEL dose per run, in scoring volume : " << G4BestUnit(nielDose, "Dose")
     << G4endl
     << "------------------------------------------------------------"
     << G4endl
     << G4endl;
	double rdose = dose;
	G4cout << dose << " " << rdose << G4endl;

	TFile* file = new TFile("JMC.root", "RECREATE");
//	tree->Branch("Dose", &rdose, "Dose");
//	tree->Fill();
	file->cd();
	tree->Write();
	file->Close();

}

void JMCRunAction::AddEdep(G4double edep)
{
	fEdep += edep;
}

void JMCRunAction::AddHits()
{
	fHits += 1;
}

void JMCRunAction::AddNIEL(G4double niel)
{
	fNIEL += niel;
}

/*TTree* JMCRunAction::GetTree()
{
	if(tree == 0)
	{
		tree = new TTree("Tree", "Tree", 99);
	}
	return tree;
}*/
