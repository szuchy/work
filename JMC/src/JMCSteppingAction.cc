//Patryk Socha
//17.05.2017

#include "JMCSteppingAction.hh"
#include "JMCEventAction.hh"
#include "JMCDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"

JMCSteppingAction::JMCSteppingAction(JMCEventAction* eventAction) : G4UserSteppingAction(), fEventAction(eventAction), fScoringVolume(0)
{}

JMCSteppingAction::~JMCSteppingAction()
{}

void JMCSteppingAction::UserSteppingAction(const G4Step* step)
{
	if(!fScoringVolume)
	{
		const JMCDetectorConstruction* detectorConstruction = static_cast<const JMCDetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
		fScoringVolume = detectorConstruction->GetScoringVolume();
	}

	G4LogicalVolume* volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

//	G4double partEnergy = step->GetPostStepPoint()->GetKineticEnergy();
//	fEventAction->AddEnergy(partEnergy);//te dwie do wywalenia

	if(volume != fScoringVolume)
		return;

	G4double edepStep = step->GetTotalEnergyDeposit();
	G4double nielStep = step->GetNonIonizingEnergyDeposit();
	fEventAction->AddEdep(edepStep);
	fEventAction->AddHits();
	fEventAction->AddNIEL(nielStep);
}
