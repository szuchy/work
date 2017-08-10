//Patryk Socha
//17.05.2017

#ifndef JMCEventAction_h
#define JMCEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class JMCRunAction;

class JMCEventAction : public G4UserEventAction
{
	public:
		JMCEventAction(JMCRunAction* runAction);
		virtual ~JMCEventAction();
		virtual void BeginOfEventAction(const G4Event* event);
		virtual void EndOfEventAction(const G4Event* event);
		void AddEdep(G4double edep) {fEdep += edep;}
		void AddHits() {fHits += 1;}
		void AddNIEL(G4double niel) {fNIEL += niel;}
//		void AddEnergy(G4double energy) {fEnergy = energy;}//to

	private:
		JMCRunAction* fRunAction;
		G4float fEdep;
		G4int fHits;
		G4double fNIEL;
//		G4double fEnergy;//i to
};

#endif
