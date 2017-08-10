//Patryk Socha
//17.05.2017

#ifndef JMCSteppingAction_h
#define JMCSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class JMCEventAction;

class G4LogicalVolume;

class JMCSteppingAction : public G4UserSteppingAction
{
	public:
		JMCSteppingAction(JMCEventAction* eventAction);
		virtual ~JMCSteppingAction();
		virtual void UserSteppingAction(const G4Step*);

	private:
		JMCEventAction* fEventAction;
		G4LogicalVolume* fScoringVolume;
};

#endif
