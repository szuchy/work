//Patryk Socha
//17.05.2017

#include "JMCPrimaryGeneratorAction.hh"

#include "G4RunManager.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

JMCPrimaryGeneratorAction::JMCPrimaryGeneratorAction() : G4VUserPrimaryGeneratorAction(), fParticleGun(0)
{
	fParticleGun = new G4GeneralParticleSource();
//	G4int nofParticle = 1;
//	fParticleGun = new G4ParticleGun(nofParticle);

//	G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
//	G4String particleName = "proton";
//	G4ParticleDefinition* particle = particleTable->FindParticle(particleName);
//	fParticleGun->SetParticleDefinition(particle);
//	fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0, 0, 1));
//	fParticleGun->SetParticleEnergy(6*MeV);
}

JMCPrimaryGeneratorAction::~JMCPrimaryGeneratorAction()
{}

void JMCPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{
	fParticleGun->GeneratePrimaryVertex(anEvent);
//	fParticleGun->SetParticlePosition(G4ThreeVector(0, 0, -0.5*m));
//	fParticleGun->GeneratePrimaryVertex(anEvent);
}
