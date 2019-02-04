/***************************************************************
 * descriptions of partcile gun
 * Author  : Hualin Xiao
 * Date    : Feb., 2015
 * Version : 1.10
 ***************************************************************/

#include "TFile.h"
#include "TTree.h"
#include "t2sim.h"

#include "PrimaryGeneratorAction.hh"
// For Random Generator
#include "Randomize.hh"
#include <CLHEP/Random/RandFlat.h>
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4UImanager.hh"

PrimaryGeneratorAction::PrimaryGeneratorAction():
    sourceType(0),fTree(NULL),fFile(NULL),nEntries(0),iEntry(0)
{
    //fParticleGunMessenger = new PrimaryGeneratorMessenger(this);



    //particle source
    G4int n_particle = 1;
    fParticleGun  = new G4ParticleGun(n_particle);     
    // default particle kinematic
    particleTable = G4ParticleTable::GetParticleTable();
    G4String particleName;
    G4ParticleDefinition* particle
        = particleTable->FindParticle(particleName="proton");
    fParticleGun->SetParticleDefinition(particle);
    fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,-1.));
    fParticleGun->SetParticleEnergy(30.*MeV);
    fParticleGun->SetParticlePosition(G4ThreeVector(0.*cm,0.*cm,15*cm));
    //particle source
    fParticleSource  = new G4GeneralParticleSource();

}
PrimaryGeneratorAction::~PrimaryGeneratorAction() 
{
    delete fParticleSource;
    //delete fParticleGunMessenger;
    delete fParticleGun;
}

void PrimaryGeneratorAction::GetGPS(G4ThreeVector &position, G4ThreeVector &direction, G4double &energy)
{
    if(particleSourceFilename=="")
    {
        position=fParticleSource->GetParticlePosition(); 
        direction=fParticleSource->GetParticleMomentumDirection();
        energy=fParticleSource->GetParticleEnergy()/keV;
    }
    else
    {
        position=fParticleGun->GetParticlePosition(); 
        direction=fParticleGun->GetParticleMomentumDirection();
        energy=fParticleGun->GetParticleEnergy()/keV;
    }
}

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent) 
{
    if(particleSourceFilename=="")
    {
        fParticleSource->GeneratePrimaryVertex(anEvent); 
    }
    else
    {
        if(!InitFile())
        {
            G4UImanager* UImanager = G4UImanager::GetUIpointer();
            UImanager->ApplyCommand("exit"); 
            return;
            //terminate the program in case of any problems
        }
        //generate multiple particles
        ts->GetEntry(iEntry);
        G4String partiName(ts->particle_name);
        /*	G4cout<<"#Particle Information:"<<G4endl;
            G4cout<<"--->particle Name:"<<ts->particle_name<<G4endl;
            G4cout<<"--->Energy: "<<ts->energy<<G4endl;
            G4cout<<"--->position(cm): "<<ts->position[0]<<" "<<ts->position[1]<<" "<<ts->position[2]<<G4endl;
            G4cout<<"--->direction: "<<ts->direction[0]<<" "<<ts->direction[1]<<" "<<ts->direction[2]<<G4endl;
            */
        fParticleGun->SetParticleDefinition(particleTable->FindParticle(partiName));
        fParticleGun->SetParticleEnergy(ts->energy*keV);
        fParticleGun->SetParticlePosition(G4ThreeVector(ts->position[0]*cm, ts->position[1]*cm, ts->position[2]*cm));
        fParticleGun->SetParticleMomentumDirection(G4ThreeVector(ts->direction[0], ts->direction[1], ts->direction[2]));
        fParticleGun->GeneratePrimaryVertex(anEvent); 
        iEntry++;

    }

}

G4bool PrimaryGeneratorAction::InitFile()
{
    if(ts!=NULL&&(iEntry<nEntries))return true;
    //do not initialize it again

    fFile =TFile::Open(particleSourceFilename);
    if(!fFile)return false;
    fTree = (TTree*) fFile->Get("t2sim");
    if(!fTree)return false;
    ts=new t2sim(fTree);
    nEntries= fTree->GetEntries();
    G4cout<<"Number of events in the ROOT file:"<<nEntries<<G4endl;
    if(nEntries==0)return false;
    if(ts)return true;
    else
    {
        G4cout<<"can not load events"<<G4endl;
        return false;
    }
}

