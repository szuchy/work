// DetectorConstruction.hh 
#ifndef SpaceDetectorConstruction_h
#define SpaceDetectorConstruction_h 1


#include "globals.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4ThreeVector.hh"
#include "G4RotationMatrix.hh"

#include "G4GDMLParser.hh"

//class SpaceDetectorConstructionMessenger;
class G4Tubs;
class G4SDManager;
class G4LogicalVolume;
class G4VisAtributes;
class G4VPhysicalVolume;
class G4Material;
class G4RunManager;
//class SpaceSD;

class SpaceDetectorConstruction : public G4VUserDetectorConstruction
{

public:

  SpaceDetectorConstruction();
 
  ~SpaceDetectorConstruction();



public:

  G4VPhysicalVolume* Construct();
  void ConstructGeometry();

	void SetVisAttrib(G4LogicalVolume *log, G4double red, G4double green, G4double blue, G4double alpha);
	void SetInvisible(G4LogicalVolume *log);
  //SpaceDetectorConstructionMessenger * DetectConstMessenger;

  // get member functions
  std::vector<G4double> GetDetectorID();
  const G4double GetWorldSizeZ() ;
  const G4double GetWorldSizeY() ;


  // set Messenger interacting member functions  

  inline void SetShieldDirThick(G4double Thick) { ShieldDirThick = Thick ;}
  inline void SetSingleAbsorber(const G4bool useSingle) { useSingleAbsorber= useSingle ;}
  inline void SetEllipticalSensors(const G4int useElliptical) { useEllipticalSensors = useElliptical  ;}
  inline void WriteGDML(const G4bool writefile ) { writeGDML = writefile;}

  void UseIonDetectorWithShielding(const G4double, const G4double);
  void UseDirDetectorWithShielding(const G4double, const G4double);

  void SetDirDetNPinHolesPhi(G4double);
  void SetDirDetNPinHolesTheta(G4double);
  void SetDirDetPinHoleMaterial(G4String);
  void SetSthick(G4double);

private:

  void DefineMaterials();
  void MyIonDetector();
  void MyDirDetector();
  void SiSensor();
  void AlAbsorber();

  void ASICsensor();



public:

  G4RunManager * theRunManager;


private:

  G4double WorldZ; 
  G4double WorldY;
  G4bool   ObtainSpectrum ;
  G4bool   useIonDetector ;
  G4bool   useDirDetector ;
  G4bool   useSingleAbsorber ;
  G4int    useEllipticalSensors ;
  G4bool   readGDML;
  G4bool   writeGDML;
  G4bool   useAnyAbsorber;
  
  G4double ShieldDirThick;
  G4double ShieldIonThick;
  G4double shthick;

  G4int NphPH;
  G4int NthPH;

  G4double world_x;
  G4double world_y;
  G4double world_z;

  G4Material* phMaterial;
  G4Material* AbsorberDiskMaterial;

  G4Material* HMaterial;
  G4Material* CMaterial;
  G4Material* OMaterial;
  G4Material* SiMaterial;
  G4Material* AlMaterial;
  G4Material* CuMaterial;
  G4Material* FeMaterial;
  G4Material* PbMaterial;
  G4Material* HeMaterial;
  G4Material* NiMaterial;
  G4Material* CoMaterial;
  G4Material* TaMaterial;
  G4Material* CrMaterial;
  G4Material* MnMaterial;
  G4Material* TiMaterial;

  G4Material* RPCGlass;
  G4Material* Concrete;
  G4Material* Kapton;
  G4Material* Teflon;
  G4Material* Air;
  G4Material* Water;
  G4Material* Vacuum;
  G4Material* LiMaterial;
  G4Material* SCMaterial;
  G4Material* SiO2;
  G4Material* FRA4;
  G4Material* kovar;
  G4Material* Al2O3;
  G4Material* Al2O3_2;
  G4Material* PtMaterial;
  G4Material* PDMS;
  G4Material* Chotherm;
  G4Material* Epoxy;
  G4Material* Steel;
  G4Material* Polyimide1;
  G4Material* Polyimide2;
  G4Material* Plastic;

  G4double Sensor_diam;
  G4double Sensor_thick;
  
  std::vector < G4LogicalVolume* > SiSensors_log;
  std::vector < G4VPhysicalVolume* > SiSensors_phys;
  std::vector < G4int > number;
  float *names;
  std::vector < G4Material*> AlO;


  G4double Absorber_thick;


  std::vector< G4double > DetectorID;
  
  //SpaceSD* SD; //  pointer to the sensitive detector

  G4LogicalVolume * world_box_log;
  G4VPhysicalVolume* world_box_phys;

  G4LogicalVolume * GenerationSphere_log;
  G4VPhysicalVolume* GenerationSphere_phys;

  G4LogicalVolume * IonDetectorWindow_log;
  G4VPhysicalVolume* IonDetectorWindow_phys;

  G4Tubs * Sensor_geo;
  G4LogicalVolume * Sensor_log;
//  std::vector < G4LogicalVolume* > SiSensors_log;

  std::vector < G4double > SiSensors_diam_max;
  std::vector < G4double > AlAbsorber_thick_var;

  std::vector < G4LogicalVolume* > LSiSensors_log;
  //std::vector < G4double > LSi_x;
  //std::vector < G4double > LSi_y;

  G4Tubs * Absorber_geo;
  G4LogicalVolume * Absorber_log;
  G4LogicalVolume * AlAbsorberDisk_log;
  G4VPhysicalVolume*  AlAbsorberDisk_phys;
  G4LogicalVolume * slit_log;
  G4VPhysicalVolume*  slit_phys;
  G4LogicalVolume * slit_hole_log;
  G4VPhysicalVolume*  slit_hole_phys;

  G4LogicalVolume * AlAbsorberDisk45_log;

  G4LogicalVolume * ShieldExtra_log;
  G4VPhysicalVolume * ShieldExtra_phys;
  G4LogicalVolume * ShieldExtraBot_log;
  G4VPhysicalVolume * ShieldExtraBot_phys;

  std::vector < G4LogicalVolume* > AlAbsorbers_log;


  //  G4LogicalVolume * IonDetector_log;

  static const int nDetectors=2;
  G4VPhysicalVolume* IonDetector_phys;

  G4LogicalVolume * DetectorBase_log;
  G4VPhysicalVolume* DetectorBase_phys;

  G4LogicalVolume * DetectorBase2_log;
  G4VPhysicalVolume* DetectorBase_physA;
 
  G4LogicalVolume * DetectorSC_log;
  G4VPhysicalVolume * DetectorSC_phys;

  G4LogicalVolume * DetectorBox_log;
  G4VPhysicalVolume * DetectorBox_phys;

  G4LogicalVolume * BN_log;
  G4VPhysicalVolume * BN_phys;

  G4LogicalVolume * AI_log;
  G4VPhysicalVolume * AI_phys;
 
  G4LogicalVolume * BI_log;
  G4VPhysicalVolume * BI_phys;
 
  G4LogicalVolume * DetectorOT_log;
  G4VPhysicalVolume * DetectorOT_phys;

  G4LogicalVolume * DetectorScrews_log;
  G4VPhysicalVolume * DetectorScrews_phys;

  G4LogicalVolume * ShieldDirDetector_log;
  G4VPhysicalVolume* ShieldDirDetector_phys;

  G4LogicalVolume * ShieldDirDetector2_log;
  G4VPhysicalVolume* ShieldDirDetector2_phys;

  G4LogicalVolume * ShieldDirDetectorPH_log;
  G4VPhysicalVolume* ShieldDirDetectorPH_phys;

  G4LogicalVolume * BottomPlane_log;
  G4VPhysicalVolume* BottomPlane_phys;

  G4LogicalVolume * ddasicbox_log; 
  G4VPhysicalVolume* ddasicbox_phys;
  G4LogicalVolume * ASIC_log;

  G4LogicalVolume * albox1_log;
  G4VPhysicalVolume* albox1_phys;
  G4LogicalVolume * albox1_in1_log;
  G4VPhysicalVolume* albox1_in1_phys;
  G4LogicalVolume * albox1_in2_log;
  G4VPhysicalVolume* albox1_in2_phys;
  G4LogicalVolume * albox1_in3_log;
  G4VPhysicalVolume* albox1_in3_phys;

  G4LogicalVolume * alplate_log;
  G4VPhysicalVolume* alplate_phys;

  G4LogicalVolume * patas_log;
  G4VPhysicalVolume* patas_phys;

  G4LogicalVolume * PCB11_log;
  G4VPhysicalVolume* PCB11_phys;
  G4LogicalVolume * PCB12_log;
  G4VPhysicalVolume* PCB12_phys;
  G4LogicalVolume * PCB2_log;
  G4VPhysicalVolume* PCB2_phys;
 
  G4LogicalVolume * OTBox_log;
  G4LogicalVolume * OTBox_in_log;
  G4LogicalVolume * OTBoxPCB_log;
  G4VPhysicalVolume* OTBox_in_phys;
  G4VPhysicalVolume* OTBoxPCB_phys;

  G4LogicalVolume * BottomPlane2_log;
  G4VPhysicalVolume* BottomPlane2_phys;
//  G4LogicalVolume * LSi_log;
//  G4VPhysicalVolume* LSi_phys;


  G4LogicalVolume * TaBox_log;
  G4VPhysicalVolume* TaBox_phys;
  G4bool CheckOverlaps;
  G4bool DetectorBase  ;
  G4bool DetectorBox ;
  G4bool DetectorShadow ;
  G4bool ShieldDirDetector ;
  G4bool BottomPlane ;
  G4bool AbsorberDisk ;
  G4bool LSensors ;
  G4bool bb ;
// GDMLparser
//
   G4GDMLParser parser;

// Reading and Writing Settings
//
   G4String fWriteFile;

  G4VisAttributes* InvVisAttributes;




};

#endif
