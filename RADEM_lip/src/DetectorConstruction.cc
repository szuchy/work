
#include "DetectorConstruction.hh"
#include "globals.hh"
#include <G4ThreeVector.hh>
#include <G4Transform3D.hh>

#include <G4Element.hh>
#include <G4Material.hh>
#include <G4Box.hh>
#include <G4Tubs.hh>
#include <G4Cons.hh>
#include <G4Sphere.hh>
#include <G4LogicalVolume.hh>
#include <G4Polycone.hh>
#include <G4PVReplica.hh>
#include <G4PVPlacement.hh>
#include <G4ThreeVector.hh>
#include <G4RotationMatrix.hh>
#include <G4AssemblyVolume.hh>
#include <G4UnionSolid.hh>
#include <G4SubtractionSolid.hh>
#include <G4Trd.hh>

#include <G4MaterialTable.hh>
#include <G4NistManager.hh>
#include <G4ElementTable.hh>
#include <G4RotationMatrix.hh>
#include <G4Transform3D.hh>
#include <G4VisAttributes.hh>
#include <G4Colour.hh>

#include <G4UImanager.hh>
#include <G4RunManager.hh>
#include <G4GeometryManager.hh>
#include <G4SolidStore.hh>
#include <G4LogicalVolumeStore.hh>
#include <G4PhysicalVolumeStore.hh>

#include <G4Sphere.hh>
#include <G4GDMLParser.hh>

#include "G4NistManager.hh"
#include "G4VisAttributes.hh"
#include "G4UserLimits.hh"


#include "G4SystemOfUnits.hh"


DetectorConstruction::DetectorConstruction(G4String gdmlFile)
{
    fReadFile=gdmlFile;
    det_msg=new DetectorMessenger(this);
}

DetectorConstruction::~DetectorConstruction()
{
    delete det_msg;
    delete stepLimit;
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{

    G4cout<<"#Read geometry from file:"<<fReadFile<<G4endl;
    G4GDMLParser fParser;
    fParser.Read(fReadFile);
    world_physical= fParser.GetWorldVolume();     

    G4LogicalVolumeStore* lvs = G4LogicalVolumeStore::GetInstance();
    std::vector<G4LogicalVolume*>::const_iterator lvciter;
    G4double maxStep = 0.2*0.61*mm;
    stepLimit=new G4UserLimits(maxStep);
    for( lvciter = lvs->begin(); lvciter != lvs->end(); lvciter++ )
    {
        G4double red= G4UniformRand();
        G4double green= G4UniformRand();
        G4double blue= G4UniformRand();
        G4double alpha=1;
        SetVisAttrib(*lvciter,red,green,blue,alpha);
        //randomize color
        G4String volumeName=(*lvciter)->GetName();
        if(volumeName.contains("sensitive"))(*lvciter)->SetUserLimits(stepLimit);
    }

    G4LogicalVolume* world_log= world_physical->GetLogicalVolume();
    SetVisAttrib(world_log, 0, 0, 0,0);
    SetInvisible(world_log);



    return world_physical;

}
void DetectorConstruction::SetVisAttrib(G4LogicalVolume *log, G4double red, G4double green, G4double blue, G4double alpha)
{
    if(!log)return;
    G4VisAttributes *visAttrib=new G4VisAttributes(G4Colour(red,green, blue,alpha));
    visAttrib->SetForceWireframe(true);
    visAttrib->SetForceSolid(true);
    log->SetVisAttributes(visAttrib);
}

void DetectorConstruction::SetInvisible(G4LogicalVolume *log)
{
    if(!log)return;
    log->SetVisAttributes(G4VisAttributes::Invisible);
}

