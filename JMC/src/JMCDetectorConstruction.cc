//Patryk Socha
//16.05.2017

#include "JMCDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"

JMCDetectorConstruction::JMCDetectorConstruction() : G4VUserDetectorConstruction(), fScoringVolume(0) {}

JMCDetectorConstruction::~JMCDetectorConstruction() {}

G4VPhysicalVolume* JMCDetectorConstruction::Construct()
{
	G4NistManager* nist = G4NistManager::Instance();

	G4bool checkOverlaps = true;

	G4Material* world_mat = nist->FindOrBuildMaterial("G4_Galactic");
	G4Material* det_mat = nist->FindOrBuildMaterial("G4_Si");

	G4double world_size = 1*m;
	G4double det_size = 1*cm;
	G4double det_z = 1*um;

	G4Box* solidWorld = new G4Box("World", 0.5*world_size, 0.5*world_size, 0.5*world_size);
	G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, world_mat, "World");
	G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, 0, checkOverlaps);

	G4Box* solidDet = new G4Box("Det", 0.5*det_size, 0.5*det_size, 0.5*det_z);
	G4LogicalVolume* logicDet = new G4LogicalVolume(solidDet, det_mat, "Det");
	new G4PVPlacement(0, G4ThreeVector(), logicDet, "Det", logicWorld, false, 0, checkOverlaps);

	fScoringVolume = logicDet;
	logicWorld->SetVisAttributes(G4VisAttributes::GetInvisible());

	return physWorld;
}
