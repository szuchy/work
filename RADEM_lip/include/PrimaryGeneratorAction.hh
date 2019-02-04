//
/// \file PrimaryGeneratorAction.hh
/// \brief Definition of the PrimaryGeneratorAction class

#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ThreeVector.hh"
#include "globals.hh"

class G4Event;

class G4GeneralParticleSource;
class G4ParticleGun;
class G4ParticleTable;

class TTree;
class TFile;
class t2sim;
//class PrimaryGeneratorMessenger;
class PrimaryGeneratorAction: public G4VUserPrimaryGeneratorAction
{
   public:
    	PrimaryGeneratorAction();
    	virtual ~PrimaryGeneratorAction();

    	virtual void GeneratePrimaries(G4Event* event);

	void SetParticleSourceFile(G4String val){particleSourceFilename=val;}
	G4bool InitFile();
    void GetGPS(G4ThreeVector &position, G4ThreeVector &direction, G4double &energy);

   private:
    	G4GeneralParticleSource*  fParticleSource;
	G4ParticleGun*  fParticleGun;
    //	PrimaryGeneratorMessenger* fParticleGunMessenger;

	G4int sourceType; //0: use particle source ; else use particle gun
	G4String particleSourceFilename;
	G4int iEntry; //entry read
	G4int nEntries; //total entries

	TTree *fTree;
	TFile *fFile;
	t2sim *ts;
	G4ParticleTable *particleTable;

	
};

#endif
