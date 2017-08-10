//Patryk Socha
//17.05.2017

#include "JMCEventAction.hh"
#include "JMCRunAction.hh"
#include "JMCDetectorConstruction.hh"
#include "JMCPrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "TTree.h"

JMCEventAction::JMCEventAction(JMCRunAction* runAction) : G4UserEventAction(), fRunAction(runAction), fEdep(0.0), fHits(0), fNIEL(0.0)//, fEnergy(0.0)//to
{}

JMCEventAction::~JMCEventAction()
{}

void JMCEventAction::BeginOfEventAction(const G4Event*)
{
	fEdep = 0.0;
	fHits = 0;
	fNIEL = 0.0;
//	fEnergy = 0.0; //i to
}

void JMCEventAction::EndOfEventAction(const G4Event*)
{
	const JMCDetectorConstruction* detectorConstruction = static_cast<const JMCDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());

	G4double mass = detectorConstruction->GetScoringVolume()->GetMass();	const JMCPrimaryGeneratorAction* generatorAction = static_cast<const JMCPrimaryGeneratorAction*>(G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
	const G4GeneralParticleSource* particleGun = generatorAction->GetParticleGun();

	G4float dose = fEdep/mass;
	G4float iniEnergy = particleGun->GetParticleEnergy();

	fRunAction->AddEdep(fEdep);
	if(fHits > 0)
		fRunAction->AddHits();
	fRunAction->AddNIEL(fNIEL);
	TTree* tree = fRunAction->GetTree();
	tree->Branch("Edep", &fEdep, "Edep");
	tree->Branch("Dose", &dose, "Dose");
	tree->Branch("IniEnergy", &iniEnergy, "IniEnergy");
	tree->Fill();
//	G4double lost = 100*MeV-fEnergy;	
//std::cout << "AAAAAAAAA!!!! Initial energy = " << G4BestUnit(iniEnergy,"Energy") << " , without units:" << iniEnergy << std::endl;//i to tez
}
