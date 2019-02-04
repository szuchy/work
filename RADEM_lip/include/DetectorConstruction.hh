

#ifndef DetectorConstruction_H
#define DetectorConstruction_H 1

// STL //
#include <string>

// GEANT4 //
class G4VSolid;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4UserLimits;
#include "DetectorMessenger.hh"

#include "G4ThreeVector.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4RotationMatrix.hh"


class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:

    DetectorConstruction(G4String );
    ~DetectorConstruction();

    G4VPhysicalVolume* Construct();

    void SetVisAttrib(G4LogicalVolume *log, G4double red, G4double green, G4double blue, G4double alpha);

    void SetGDMLFile(G4String filen){fReadFile=filen;}

    void SetInvisible(G4LogicalVolume *log);
    void SetWorld(G4String var){fWorldName=var;}

  private:
    G4VPhysicalVolume* world_physical;
    
    G4String fReadFile;
    G4String fWorldName;
    DetectorMessenger *det_msg;
    G4UserLimits *stepLimit;
};

#endif

