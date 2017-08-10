//Patryk Socha
//16.05.2017

#ifndef JMCDetectorConstruction_h
#define JMCDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

class JMCDetectorConstruction : public G4VUserDetectorConstruction
{
	public:
		JMCDetectorConstruction();
		virtual ~JMCDetectorConstruction();
		virtual G4VPhysicalVolume* Construct();
		G4LogicalVolume* GetScoringVolume() const {return fScoringVolume;}

	protected:
		G4LogicalVolume* fScoringVolume;
};

#endif
