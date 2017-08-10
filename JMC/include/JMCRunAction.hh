//Patryk Socha
//16.05.2017

#ifndef JMCRunAction_h
#define JMCRunAction_h 1

#include "G4UserRunAction.hh"
#include "G4Accumulable.hh"
#include "globals.hh"

#include "TROOT.h"
#include "TTree.h"

class G4Run;
class TTree;

class JMCRunAction : public G4UserRunAction
{
	public:
		JMCRunAction();
		virtual ~JMCRunAction();
		virtual void BeginOfRunAction(const G4Run*);
		virtual void EndOfRunAction(const G4Run*);
		void AddEdep (G4double edep);
		void AddHits ();
		void AddNIEL (G4double niel);
		TTree* GetTree() {return tree;}
	private:
		G4Accumulable<G4double> fEdep;
		G4Accumulable<G4int> fHits;
		G4Accumulable<G4double> fNIEL;
		TTree* tree;
};

#endif
