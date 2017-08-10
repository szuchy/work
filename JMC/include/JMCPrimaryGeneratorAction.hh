//Patryk Socha
//17.05.2017

#ifndef JMCPrimaryGeneratorAction_h
#define JMCPrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"
#include "globals.hh"

class G4ParticleGun;
class G4GeneralParticleSource;
class G4Event;

class JMCPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
	public:
		JMCPrimaryGeneratorAction();
	virtual ~JMCPrimaryGeneratorAction();
	virtual void GeneratePrimaries(G4Event*);

	const G4GeneralParticleSource* GetParticleGun() const {return fParticleGun;}

	private:
		G4GeneralParticleSource* fParticleGun;
};

#endif
