//  SpaceDetectorConstruction.cc

#include "globals.hh"
#include "SpaceDetectorConstruction.hh"
//#include "SpaceDetectorConstructionMessenger.hh"

#include "G4Element.hh"
#include "G4Material.hh"

#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4Polycone.hh"
#include "G4EllipticalTube.hh"
#include "G4Torus.hh"
#include "G4VSolid.hh"
#include "G4UnionSolid.hh"
#include "G4IntersectionSolid.hh"
#include "G4SubtractionSolid.hh"
#include "G4MultiUnion.hh"

#include <string>
#include <sstream>
using namespace std;

 
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4PVReplica.hh"

#include "G4GeometryTolerance.hh"
#include "G4GeometryManager.hh"
#include "G4NistManager.hh"

#include "G4VisAttributes.hh"
#include "G4Colour.hh"

#include "G4SDManager.hh"
//#include "SpaceSD.hh"    //for sensitive detector

#include "G4RunManager.hh"
#include "G4VPhysicalVolume.hh"
#include "G4SystemOfUnits.hh"
#include "G4PhysicalConstants.hh"

// GDML parser include
//
#include "G4GDMLParser.hh"


SpaceDetectorConstruction::SpaceDetectorConstruction()
{
	G4cout << "In  SpaceDetectorConstruction::SpaceDetectorConstruction()" << G4endl ; 

	//  SD = new SpaceSD("DirDetector");

	CheckOverlaps = true; 

	//theRunManager = G4RunManager::GetRunManager();
	//DetectConstMessenger= new SpaceDetectorConstructionMessenger(this);

	// Class defaults (may be changed via messenger)
	ObtainSpectrum = false;  
	useIonDetector    = false  ;
	useDirDetector    = false  ;
	useSingleAbsorber = false;
	useEllipticalSensors = 0;
	writeGDML = false;
	readGDML = true;  
	// Detector Parts
	useAnyAbsorber = false;
	DetectorBase = false;
	DetectorBox = false;
	DetectorShadow = true;
	ShieldDirDetector =false;
	BottomPlane = false;
	AbsorberDisk = false;
	LSensors = false;
	bb = false;
	DefineMaterials();

	fWriteFile="GDMLtest.gdml";        

}

SpaceDetectorConstruction::~SpaceDetectorConstruction()
{
	//delete DetectConstMessenger; 

}


void SpaceDetectorConstruction::DefineMaterials() 
{ 

	// DefineMaterials

	G4NistManager* NIST_manager = G4NistManager::Instance();


	NIST_manager->SetVerbose(1);

	//   elNi  = manager->FindOrBuildElement(28);

	// Define pure materials
	HMaterial  = NIST_manager->FindOrBuildMaterial("G4_H");
	CMaterial  = NIST_manager->FindOrBuildMaterial("G4_C");
	OMaterial  = NIST_manager->FindOrBuildMaterial("G4_O");
	SiMaterial = NIST_manager->FindOrBuildMaterial("G4_Si");  
	AlMaterial = NIST_manager->FindOrBuildMaterial("G4_Al");
	FeMaterial = NIST_manager->FindOrBuildMaterial("G4_Fe");  
	CuMaterial = NIST_manager->FindOrBuildMaterial("G4_Cu");  
	PbMaterial = NIST_manager->FindOrBuildMaterial("G4_Pb");  
	HeMaterial = NIST_manager->FindOrBuildMaterial("G4_He");
	LiMaterial = NIST_manager->FindOrBuildMaterial("G4_Li");
	NiMaterial = NIST_manager->FindOrBuildMaterial("G4_Ni");
	CoMaterial = NIST_manager->FindOrBuildMaterial("G4_Co");
	TaMaterial = NIST_manager->FindOrBuildMaterial("G4_Ta");
	PtMaterial= NIST_manager->FindOrBuildMaterial("G4_Pt");
	CrMaterial= NIST_manager->FindOrBuildMaterial("G4_Cr");
	MnMaterial= NIST_manager->FindOrBuildMaterial("G4_Mn");
	TiMaterial= NIST_manager->FindOrBuildMaterial("G4_Ti");


	// Define compound materials
	Air      = NIST_manager->FindOrBuildMaterial("G4_AIR");  
	Water    = NIST_manager->FindOrBuildMaterial("G4_WATER");  
	Concrete = NIST_manager->FindOrBuildMaterial("G4_CONCRETE");
	RPCGlass = NIST_manager->FindOrBuildMaterial("G4_GLASS_PLATE");  
	Kapton   = NIST_manager->FindOrBuildMaterial("G4_KAPTON");  
	Plastic  = NIST_manager->FindOrBuildMaterial("G4_Polyvinyl_Chloride");

	// Polyimide1   = NIST_manager->FindOrBuildMaterialWithNewDensity("Poly1","G4_KAPTON",3.4*g/cm3);
	// Polyimide2   = NIST_manager->FindOrBuildMaterialWithNewDensity("Poly2","G4_KAPTON",1.6*g/cm3);

	// Vacuum

	G4double a;         //atomic mass
	G4double z;         //atomic number
	G4double density;   //density
	G4String name;      //material name
	G4String symbol;    //material symbol
	G4double temperature;
	G4double pressure;


	temperature = 2.73 * kelvin;
	pressure = 1.e-8 * bar;

	Vacuum = 
		new G4Material(name="Vacuum",
				z= 1.,
				a = 1.008 * g/mole,
				density= 1.e-25 * g/cm3,
				kStateGas,
				temperature,
				pressure);

	//Define Spacecraft material 
	G4int ncomp=2;  
	G4int fractionmass=4*perCent;

	SCMaterial = new G4Material("SCMaterial",0.064*g/cm3, 2);
	SCMaterial->AddMaterial(Air, 97.6*perCent);
	SCMaterial->AddMaterial(AlMaterial, 2.4*perCent); 

	//Define PCB Material
	a = 16.00*g/mole;
	G4Element* elO = new G4Element("Oxygen",symbol="O",z=8.,a);
	a = 28.09*g/mole;
	G4Element* elSi = new G4Element("Silicon",symbol="Si",z=14.,a);

	density = 2.200 * g/cm3;
	SiO2 = new G4Material ("SiO2", density,2);
	SiO2->AddElement (elSi, 1);
	SiO2->AddElement (elO, 2);

	//FRA
	density = 1.92 * g/cm3;
	FRA4 = new G4Material ( name = "FRA4", density, 2);
	FRA4->AddMaterial (SiO2, 99.986 * perCent);
	FRA4->AddMaterial (CuMaterial, 0.014 * perCent);

	//Kovar
	density = 8.0 * g/cm3;
	kovar = new G4Material ( name = "Kovar", density,3);
	kovar->AddMaterial (FeMaterial, 54. * perCent);
	kovar->AddMaterial (NiMaterial, 29. * perCent);
	kovar->AddMaterial (CoMaterial, 17. * perCent);

	//Aluminum Oxide
	density = 4.0* g/cm3;
	Al2O3 = new G4Material("ceramics", density,2);
	Al2O3->AddMaterial (AlMaterial, 0.4);
	Al2O3->AddElement (elO, 0.6);

	density = 2.397392* g/cm3;
	Al2O3_2 = new G4Material("ceramics", density,2);
	Al2O3_2->AddMaterial (AlMaterial, 0.4);
	Al2O3_2->AddElement (elO, 0.6);

	//Stainless Steel
	density=7.80 * g/cm3;
	Steel = new G4Material("Steel",density,6);
	Steel->AddMaterial(CMaterial,0.001);
	Steel->AddMaterial(SiMaterial,0.007);
	Steel->AddMaterial(CrMaterial,0.18);
	Steel->AddMaterial(MnMaterial,0.01);
	Steel->AddMaterial(FeMaterial,0.712);
	Steel->AddMaterial(NiMaterial,0.09);

	//Polyimide 1
	density=3.4 * g/cm3;
	Polyimide1 = new G4Material("Poly1", density,1);
	Polyimide1->AddMaterial(Kapton,1);

	//Polyimide 2
	density=1.6 * g/cm3;
	Polyimide2 = new G4Material("Poly2", density,1);
	Polyimide2->AddMaterial(Kapton,1);
	G4cout << "new mats"<< G4endl;
	//Polydimethylsiloxane
	density=0.965*g/cm3;
	PDMS = new G4Material("PDMS", density,4);
	PDMS->AddMaterial(SiMaterial,0.1);
	PDMS->AddMaterial(CMaterial,0.2);
	PDMS->AddMaterial(OMaterial,0.1);
	PDMS->AddMaterial(HMaterial,0.6);

	//Chotherm
	density=3.08*g/cm3;
	Chotherm= new G4Material("Chotherm",density,2);
	Chotherm->AddMaterial(Al2O3,0.7);
	Chotherm->AddMaterial(PDMS,0.3);



	// default for Pin hole material
	phMaterial=Vacuum;


	float dens[]={7.781044771*g/cm3,9.620728112*g/cm3,6.06589405*g/cm3,4.279575613*g/cm3,3.815187101*g/cm3,5.815644083*g/cm3,4.637267312*g/cm3,4.461124959*g/cm3,4.905646417*g/cm3,5.304801289*g/cm3,3.907579267*g/cm3,4.87374988*g/cm3,4*g/cm3,4.85687535*g/cm3,4*g/cm3,4*g/cm3,5.221864484*g/cm3};

	//vector <G4Material*>  AlO;
	for (int i=0;i<17;i++)
	{
		char *name1="Al2O3";
		stringstream ss;
		ss <<name1<<i+1;
		string fin=ss.str();
		char *name2=(char *) fin.c_str();

		Al2O3 = new G4Material(name2, dens[i],2);
		Al2O3->AddMaterial (AlMaterial, 0.4);
		Al2O3->AddElement (elO, 0.6);
		AlO.push_back(Al2O3);
	}

	//Print the material table
	//  G4cout<< *(G4Material::GetMaterialTable()) <<G4endl;

}


G4VPhysicalVolume* SpaceDetectorConstruction::Construct()
{
	G4cout << "so it starts" << G4endl;

	string names[]={"RDM_3500005","RDM_3534005","RDM_3700005","RDM_3700007","RDM_3709005","RDM_3734005","RDM_3734007","RDM_3734009","RDM_3734019","RDM_3734021","RDM_3734023","RDM_3734025","RDM_3734027","RDM_3734029","RDM_3737005","RDM_3737007","RDM_3737009"};

	int true_ind=0;

	// World

	G4VisAttributes* SensorVisAttributes = new G4VisAttributes(G4Colour::Green());

	G4VisAttributes* AluVisAttributes = new G4VisAttributes(G4Colour::Red());

	G4VisAttributes* GrayVisAttributes = new G4VisAttributes(G4Colour::Gray());

	G4VisAttributes* CopVisAttributes = new G4VisAttributes(G4Colour::Blue());

	G4VisAttributes* EEEVisAttributes = new G4VisAttributes(G4Colour::Magenta());

	G4VisAttributes* BlackVisAttributes = new G4VisAttributes(G4Colour::Black());
	G4VisAttributes* YellowVisAttributes = new G4VisAttributes(G4Colour::Yellow());


	G4VisAttributes* SCVisAttributes = new G4VisAttributes(G4Colour::Black());
	SCVisAttributes->SetForceWireframe(true);

	parser.Read("mother.gdml",false);
	G4VPhysicalVolume* W = parser.GetWorldVolume(); //world volume
	G4cout << W->GetName()<<G4endl;
	G4LogicalVolume* W_log = W->GetLogicalVolume();
	W_log->SetMaterial(Vacuum);
	W_log->SetVisAttributes(SCVisAttributes);

	//Sensitive Detector
/*	G4SDManager* SDmanager = G4SDManager::GetSDMpointer();
	if(!SD){
		G4cout << "Adding SD" << G4endl;
		SD = new SpaceSD("DirDetector");
		SDmanager->AddNewDetector(SD);
	}
	*/


	G4Box * try1 = new G4Box("try1",0.5*mm,0.5*mm,0.5*mm); 
	G4LogicalVolume * try1LV = new G4LogicalVolume(try1,SiMaterial,"try1LV",0,0,0);

	G4int DD_detectors[31] = {0,1,2,4,6,7,8,9,13,14,19,20,21,23,24,28,30,32,34,35,38,40,41,42,43,53,54,59,63,64,67};
	int tot=88+4+11-1+49;
	int count=0;
	//tot = 88+4-1;
	for (G4int i=0;i<=tot;i++)
	{
		//G4cout << i << G4endl;
		G4VPhysicalVolume* daughter = W_log->GetDaughter(i);
		daughter->SetCopyNo(i);
		G4LogicalVolume* daughter_log = daughter->GetLogicalVolume();

		G4cout << daughter->CheckOverlaps() << G4endl;


		std::string daughter_name = daughter->GetName();
		std::string short_daughter_name = daughter_name.substr(0,3);

		G4cout << short_daughter_name << G4endl;
		int d = i-44;
		//daughter_log->SetVisAttributes(SCVisAttributes);
		//if (d==0||d==1||d==6||d==8||d==11||d==14||d==21||d==23||d==26||d==31||d==35||d==37||d==39) daughter_log->SetVisAttributes(EEEVisAttributes);
		//if (d==2||d==3||d==4||d==5||d==7||d==9||d==11||d==13||d==15||d==16||d==17||d==18||d==19||d==20||d==22||d==24||d==25||d==26||d==27||d==28||d==29||d==30||d==32||d==33||d==34||d==36||d==38||d==39||d==40||d==41||d==42||d==43) daughter_log->SetVisAttributes(EEEVisAttributes);
		//if(d==10) daughter_log->SetVisAttributes(EEEVisAttributes);
		if (short_daughter_name=="Sil")
		{
			G4cout << "Sil " << daughter->GetName() << G4endl;
			daughter_log->SetMaterial(SiMaterial);
			//daughter_log->SetSensitiveDetector(SD);
			daughter_log->SetVisAttributes(SensorVisAttributes);
		}
		if (short_daughter_name=="Ion")
		{
			G4cout << " AAHHHHHHHHHHH " << G4endl;
			G4cout << "Ion " << daughter->GetName() << G4endl;
			daughter_log->SetMaterial(SiMaterial);
			//daughter_log->SetSensitiveDetector(SD);
			daughter_log->SetVisAttributes(SensorVisAttributes);
		}

		else if (short_daughter_name=="Kap")
		{
			G4cout << "Kap " << daughter->GetName() << G4endl;

			daughter_log->SetMaterial(Kapton);
		}
		else if (short_daughter_name=="Alu")
		{
			G4cout << "Alu " << daughter->GetName() << G4endl;

			daughter_log->SetMaterial(AlMaterial);
			daughter_log->SetVisAttributes(GrayVisAttributes);
		}
		else if (short_daughter_name=="Cho")
		{
			G4cout << "Cho " << daughter->GetName() << G4endl;
			daughter_log->SetMaterial(Chotherm);
			daughter_log->SetVisAttributes(SCVisAttributes);
		}
		else if (short_daughter_name=="Cop")
		{
			G4cout << "Cop " << daughter->GetName() << G4endl;

			daughter_log->SetMaterial(CuMaterial);
			daughter_log->SetVisAttributes(CopVisAttributes);
		}

		else if (short_daughter_name=="RDM")
		{
			std::string disc_daughter_name = daughter_name.substr(15,1);
			std::string code_daughter_name = daughter_name.substr(0,11);
			G4cout << code_daughter_name <<" " << i <<" "<<disc_daughter_name<< G4endl;
			//daughter_log->SetSensitiveDetector(SD);

			if (disc_daughter_name=="d")
			{
				//		G4cout << " "<< G4endl;
				daughter_log->SetMaterial(SiMaterial);
				//           daughter_log->SetVisAttributes(SensorVisAttributes);
				//	G4cout << daughter_name << endl;
			}
			else
			{
				for (int ind=0;ind<17;ind++)
				{
					if(names[ind]==code_daughter_name) 
					{
						true_ind=ind;
						//G4cout << code_daughter_name << G4endl;	
					}
				}
				//G4cout << "hey" << G4endl;
				daughter_log->SetMaterial(AlO[true_ind]);
				//             daughter_log->SetVisAttributes(EEEVisAttributes);

			}
		}
		else if (short_daughter_name=="EEE")
		{
			count+=1;
			G4cout << daughter_name << G4endl;
			if(count<4){
				//daughter_log->SetSensitiveDetector(SD);
				daughter_log->SetMaterial(Al2O3);
				G4cout << " EEE!" << G4endl;
				//	 daughter_log->SetVisAttributes(EEEVisAttributes);
			}
			else if(daughter_name=="EEE_PV"){
				daughter_log->SetMaterial(Al2O3);
				//daughter_log->SetVisAttributes(CopVisAttributes);
			}
			else
			{
				G4cout << "still here" << G4endl; 
				//daughter_log->SetSensitiveDetector(SD);
				daughter_log->SetMaterial(Al2O3_2);
				//        daughter_log->SetVisAttributes(EEEVisAttributes);

			}

		}
		else if (short_daughter_name=="Ep")
		{
			G4cout << "Ep" << daughter->GetName() << G4endl;

			if (daughter_name=="Ep1_PV") daughter_log->SetMaterial(Polyimide1); //cables
			if (daughter_name=="Ep2_PV") daughter_log->SetMaterial(FRA4); 
			if (daughter_name=="Ep3_PV") daughter_log->SetMaterial(Polyimide2); //PCBs
			daughter_log->SetVisAttributes(YellowVisAttributes);

		}
		else if (short_daughter_name=="Pla")
		{
			G4cout << "Pla " << daughter->GetName() << G4endl;

			daughter_log->SetMaterial(PtMaterial);
			//daughter_log->SetVisAttributes(EEEVisAttributes);
		}
		else if (short_daughter_name=="Ste")
		{
			G4cout << "Ste "<< daughter->GetName() << G4endl;
			daughter_log->SetVisAttributes(BlackVisAttributes);
			daughter_log->SetMaterial(Steel);
		}
		else if (short_daughter_name=="Tan")
		{
			G4cout << "Tan " << daughter->GetName() << G4endl;
			//	daughter_log->SetVisAttributes(AluVisAttributes);
			daughter_log->SetMaterial(TaMaterial);
		}
		else if (short_daughter_name=="Tit")
		{
			G4cout << "Tit " << daughter->GetName() << G4endl;
			daughter_log->SetMaterial(TiMaterial);
			daughter_log->SetVisAttributes(BlackVisAttributes);
		}
		//if(d==5||d==8||d==10||d==15) daughter_log->SetVisAttributes(EEEVisAttributes);//transistors
		//if(d==18||d==19||d==20) daughter_log->SetVisAttributes(SensorVisAttributes);//ADCs
		//if(d==0||d==1||d==16||d==32||d==33||d==34) daughter_log->SetVisAttributes(EEEVisAttributes);//Others

	}

	//////////////////Equivalent Shielding///////////
	G4double height = 99.8*mm;
	G4double bigside = 221.5*mm;
	G4double smallside = 160*mm;
	G4double thick_xplus=3*mm;
	G4double thick_xminus=1*mm;
	G4double thick_yplus=10.*mm;
	G4double thick_yminus=0.01*mm;
	G4double thick_zplus=0.01*mm;
	G4double thick_zminus=0.5*mm;


	G4double bots_thick_al=9.44*mm;
	G4double bots_thick_pb=bots_thick_al/0.95*mm-bots_thick_al*mm;
	G4double bots_side1=199*mm;
	G4double bots_side2=138*mm;
	G4Box * als = new G4Box("als",bots_side1/2,bots_thick_al/2,bots_side2/2);
	G4Box * pbs = new G4Box("pbs",bots_side1/2,bots_thick_pb/2,bots_side2/2);

	// G4Box * yplus = new G4Box("xplus",bigside/2+thick_zminus/2,height/2+thick_xplus/2-21.5/2,thick_yplus/2);
	G4Box * yplus = new G4Box("xplus",bigside/2,height/2+thick_xplus/2-21.5/2,thick_yplus/2);

	G4Box * yminus = new G4Box("xminus",bigside/2,height/2,thick_yminus/2);
	G4Box * zplus = new G4Box("yplus",thick_zplus/2,height/2-21.5/2,smallside/2);
	G4Box * zminus = new G4Box("yminus",thick_zminus/2,height/2-21.5/2+thick_xplus/2,smallside/2);
	G4Box * xplus = new G4Box("zplus",bigside/2,thick_xplus/2,smallside/2);
	G4Box * xminus = new G4Box("zminus",bigside/2,thick_xminus/2,smallside/2);


	G4LogicalVolume * als_lv = new G4LogicalVolume(als,
			AlMaterial,
			"als_lv", 0,0,0);
	G4LogicalVolume * pbs_lv = new G4LogicalVolume(pbs,
			PbMaterial,
			"pbs_lv", 0,0,0);

	G4LogicalVolume * yplus_lv = new G4LogicalVolume(yplus,
			AlMaterial,
			"yplux_lv", 0,0,0);

	G4LogicalVolume * zminus_lv = new G4LogicalVolume(zminus,
			AlMaterial,
			"zplux_lv", 0,0,0);

	/////////////////////////X slab holes//////////////////////
	G4RotationMatrix * rotm  = new G4RotationMatrix();


	//esd collimator
	G4double esd_diam = 29.*mm;
	G4Tubs * esd_tube = new G4Tubs("esd_tube",0*mm, esd_diam/2, thick_xplus/2,0,twopi);

	//P&I collimator

	G4double pi_diam = 33.*mm;
	G4double bridge_length = 30.0*mm;
	G4Tubs * pi_col_1 = new G4Tubs("pi_col_1",0*mm, pi_diam/2, thick_xplus/2,0,twopi);
	G4Tubs * pi_col_2 = new G4Tubs("pi_col_2",0*mm, pi_diam/2, thick_xplus/2,0,twopi);
	G4Box * bridge = new G4Box("bridge", bridge_length/2,thick_xplus/2,bridge_length/2);
	G4UnionSolid * pi_colls = new G4UnionSolid("pi_colls", pi_col_1, pi_col_2, rotm, G4ThreeVector(0,-30,0.));
	G4UnionSolid * pi_comp  = new G4UnionSolid("pi_comp", pi_colls, bridge, rotm, G4ThreeVector(0,-15,0.));

	//small screws
	G4double ss_diam = 5.6*mm;
	G4Tubs * ss_tube = new G4Tubs("ss_tube", 0*mm, ss_diam/2, thick_xplus/2,0,twopi);
	//big screws
	G4double bs_diam = 5.5*mm;
	G4Tubs * bs_tube = new G4Tubs("bs_tube",0*mm, bs_diam/2, thick_xplus/2,0,twopi);

	//ddbox
	G4double ddbox_xlength = 120*mm;
	G4double ddbox_zlength = 98.5*mm;
	G4Box * ddbox = new G4Box("ddbox",ddbox_xlength/2,thick_xplus/2,ddbox_zlength/2);


	//cut placement
	G4RotationMatrix * rotm_screws = new G4RotationMatrix();
	rotm_screws->rotateX(90*deg); 

	/*      G4ThreeVector position1 = G4ThreeVector(47.,0.,-71.25);
			G4ThreeVector position2 = G4ThreeVector(-47.,0.,-71.25);
			G4Transform3D tr1 = G4Transform3D(rotm,position1);
			G4Transform3D tr2 = G4Transform3D(rotm,position2);

			G4MultiUnion * x_cut = new G4MultiUnion("x_cut");
			x_cut->AddNode(*ss_tube,tr1);
			x_cut->AddNode(*bs_tube,tr2);
			*/
	G4SubtractionSolid * xcutted_1 = new G4SubtractionSolid("xcutted_1", xplus, ddbox, rotm, G4ThreeVector(-bigside/2+(bigside/2-88)+120/2,0.,-smallside/2+(smallside/2-62.6)+98.5/2));

	G4SubtractionSolid * xcutted_2 = new G4SubtractionSolid("xcutted_2", xcutted_1, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2-102),0.,-smallside/2+(smallside/2-52.5)));

	G4SubtractionSolid * xcutted_3 = new G4SubtractionSolid("xcutted_3", xcutted_2, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2-47),0.,-smallside/2+(smallside/2-71.25)));

	G4SubtractionSolid * xcutted_4 = new G4SubtractionSolid("xcutted_4", xcutted_3, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+47),0.,-smallside/2+(smallside/2-71.25)));

	G4SubtractionSolid * xcutted_5 = new G4SubtractionSolid("xcutted_5", xcutted_4, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+102),0.,-smallside/2+(smallside/2-52.5)));

	G4SubtractionSolid * xcutted_6 = new G4SubtractionSolid("xcutted_6", xcutted_5, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2-102),0.,-smallside/2+(smallside/2+52.5)));

	G4SubtractionSolid * xcutted_7 = new G4SubtractionSolid("xcutted_7", xcutted_6, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2-47),0.,-smallside/2+(smallside/2+71.25)));

	G4SubtractionSolid * xcutted_8 = new G4SubtractionSolid("xcutted_8", xcutted_7, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+47),0.,-smallside/2+(smallside/2+71.25)));

	G4SubtractionSolid * xcutted_9 = new G4SubtractionSolid("xcutted_9", xcutted_8, bs_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+102),0.,-smallside/2+(smallside/2+52.5)));

	G4SubtractionSolid * xcutted_10 = new G4SubtractionSolid("xcutted_10", xcutted_9, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+83.754),0.,-smallside/2+(smallside/2+46.75)));

	G4SubtractionSolid * xcutted_11 = new G4SubtractionSolid("xcutted_11", xcutted_10, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+48.246),0.,-smallside/2+(smallside/2+46.75)));

	G4SubtractionSolid * xcutted_12 = new G4SubtractionSolid("xcutted_12", xcutted_11, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+39.32),0.,-smallside/2+(smallside/2+18)));

	G4SubtractionSolid * xcutted_13 = new G4SubtractionSolid("xcutted_13", xcutted_12, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+39.32),0.,-smallside/2+(smallside/2-22)));

	G4SubtractionSolid * xcutted_14 = new G4SubtractionSolid("xcutted_14", xcutted_13, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+48.5),0.,-smallside/2+(smallside/2-36.5)));

	G4SubtractionSolid * xcutted_15 = new G4SubtractionSolid("xcutted_15", xcutted_14, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+66),0.,-smallside/2+(smallside/2-14)));

	G4SubtractionSolid * xcutted_16 = new G4SubtractionSolid("xcutted_16", xcutted_15, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+77.75),0.,-smallside/2+(smallside/2-19.612)));

	G4SubtractionSolid * xcutted_17 = new G4SubtractionSolid("xcutted_17", xcutted_16, ss_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+77.75),0.,-smallside/2+(smallside/2-53.387)));

	G4SubtractionSolid * xcutted_18 = new G4SubtractionSolid("xcutter_18", xcutted_17, esd_tube, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+68),0.,-smallside/2+(smallside/2-36.5)));

	G4SubtractionSolid * xcutted_19 = new G4SubtractionSolid("x_cutter_19", xcutted_18, pi_comp, rotm_screws, G4ThreeVector(-bigside/2+(bigside/2+66),0., -smallside/2+(smallside/2+6.5)));

	G4LogicalVolume * xplus_lv = new G4LogicalVolume(xcutted_19,
			AlMaterial,
			"xplus_lv", 0,0,0);




	als_lv->SetVisAttributes(AluVisAttributes);
	xplus_lv->SetVisAttributes(AluVisAttributes);
	yplus_lv->SetVisAttributes(AluVisAttributes);
	zminus_lv->SetVisAttributes(AluVisAttributes);
	/////////////////////////slab placement/////////////////// 
	G4RotationMatrix* rotm1 =  new G4RotationMatrix();

	/* G4PVPlacement * xcut_pv = new G4PVPlacement(rotm1,
	   G4ThreeVector(200,0,0),
	   xcut_lv,
	   "xcut_ov",
	   W_log,
	   0,
	   true);
	   */ 



	/*
	   G4PVPlacement *als_pv = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200,41.50-height/2-bots_thick_al/2,0.),
	   als_lv,
	   "als_pv",
	   W_log,
	   0,
	   true);
	   */
	/*
	   G4PVPlacement *pbs_pv = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200,41.50-height/2-bots_thick_al-bots_thick_pb/2,0.),
	   pbs_lv,
	   "pbs_pv",
	   W_log,
	   0,
	   true);
	   */
	pbs_lv->SetVisAttributes(EEEVisAttributes);
	///DESCOMENTAR

	G4PVPlacement * xplus_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200,41.50+height/2+thick_xplus/2-21.5,0.),
			xplus_lv,
			"xplus_lv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement * yplus_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200,41.50-21.5/2+thick_xplus/2,-smallside/2.-thick_yplus/2),
			yplus_lv,
			"yplus_lv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement * zminus_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-bigside/2-thick_zminus/2,41.50-21.5/2+thick_xplus/2,0.),
			zminus_lv,
			"zplus_lv",
			W_log,
			false,
			0,
			true);




	///side shielding

	//boxes

	G4double side_1_x = 186*mm;
	G4double side_1_y = 68.3*mm;
	G4double side_1_z = 4*mm;

	G4double side_2_x = 4*mm;
	G4double side_2_y = 68.3*mm;
	G4double side_2_z = 125*mm;
	G4double cut_x = 20*mm;
	G4double cut_y = 18*mm;
	G4double cut_z = 20*mm;

	G4Box * side1_box = new G4Box("side1_box",side_1_x/2,side_1_y/2,side_1_z/2);
	G4Box * side2_box = new G4Box("side2_box",side_2_x/2,side_2_y/2,side_2_z/2);

	//cut volumes
	//for side 1
	G4Box * s1_cut1_box = new G4Box("s1_cut1_box",11/2*mm,5/2*mm,4/2*mm);
	G4Box * s1_cut2_box = new G4Box("s1_cut2_box",4.5/2*mm,18/2*mm, 4/2*mm);




	G4SubtractionSolid * side1_cutted_1 = new G4SubtractionSolid("side1_cutted_1", side1_box, s1_cut1_box, rotm, G4ThreeVector(47.,31.65,0));
	G4SubtractionSolid * side1_cutted_2 = new G4SubtractionSolid("side1_cutted_2", side1_cutted_1, s1_cut1_box, rotm, G4ThreeVector(-47.,31.65,0));
	G4SubtractionSolid * side1_cutted_3 = new G4SubtractionSolid("side1_cutted_3", side1_cutted_2, s1_cut2_box,rotm, G4ThreeVector(54.75,25.15,0));
	G4SubtractionSolid * side1_cutted_4 = new G4SubtractionSolid("side1_cutted_4", side1_cutted_3, s1_cut2_box,rotm, G4ThreeVector(-54.75,25.15,0));
	G4SubtractionSolid * side1_cutted_5 = new G4SubtractionSolid("side1_cutted_5", side1_cutted_4, s1_cut2_box,rotm, G4ThreeVector(39.25,25.15,0));
	G4SubtractionSolid * side1_cutted_6 = new G4SubtractionSolid("side1_cutted_6", side1_cutted_5, s1_cut2_box,rotm, G4ThreeVector(-39.25,25.15,0));

	//for side 2
	G4Box * s2_cut1_box = new G4Box("s2_cut1_box",4/2*mm,5/2*mm,11/2*mm);
	G4Box * s2_cut2_box = new G4Box("s2_cut2_box",4/2*mm,18/2*mm, 4.5/2*mm);

	G4SubtractionSolid * side2_cutted_1 = new G4SubtractionSolid("side2_cutted_1", side2_box, s2_cut1_box, rotm, G4ThreeVector(0,31.65,52.55));
	G4SubtractionSolid * side2_cutted_2 = new G4SubtractionSolid("side2_cutted_2", side2_cutted_1, s2_cut1_box, rotm, G4ThreeVector(0.25,31.65,52.55));
	G4SubtractionSolid * side2_cutted_3 = new G4SubtractionSolid("side2_cutted_3", side2_cutted_2, s2_cut2_box,rotm, G4ThreeVector(0,25.15,60.25));
	G4SubtractionSolid * side2_cutted_4 = new G4SubtractionSolid("side2_cutted_4", side2_cutted_3, s2_cut2_box,rotm, G4ThreeVector(0,25.15,-60.25));
	G4SubtractionSolid * side2_cutted_5 = new G4SubtractionSolid("side2_cutted_5", side2_cutted_4, s2_cut2_box,rotm, G4ThreeVector(0,25.15,44.75));
	G4SubtractionSolid * side2_cutted_6 = new G4SubtractionSolid("side2_cutted_6", side2_cutted_5, s2_cut2_box,rotm, G4ThreeVector(0,25.15,-44.75));

	//for side 3 (connectors)
	G4Box * s3_cut1_box = new G4Box("s3_cut1_box",4/2*mm,18/2*mm,4.5/2*mm);
	G4Box * s3_cut2_box = new G4Box("s3_cut2_box",4/2*mm,5/2*mm, 13.5/2*mm);
	G4Box * s3_cut3_box = new G4Box("s3_cut3_box",4/2*mm,5/2*mm,8.5/2*mm);
	G4Box * s3_cut4_box = new G4Box("s3_cut4_box",4/2*mm,4/2*mm, 4/2*mm);

	G4SubtractionSolid * side3_cutted_1 = new G4SubtractionSolid("side3_cutted_1", side2_box, s3_cut1_box, rotm, G4ThreeVector(0,25.15,60.25));
	G4SubtractionSolid * side3_cutted_2 = new G4SubtractionSolid("side3_cutted_2", side3_cutted_1, s3_cut1_box, rotm, G4ThreeVector(0,25.15,-60.25));
	G4SubtractionSolid * side3_cutted_3 = new G4SubtractionSolid("side3_cutted_3", side3_cutted_2, s3_cut2_box,rotm, G4ThreeVector(0,31.65,51.25));
	G4SubtractionSolid * side3_cutted_4 = new G4SubtractionSolid("side3_cutted_4", side3_cutted_3, s3_cut2_box,rotm, G4ThreeVector(0,31.65,-51.25));
	G4SubtractionSolid * side3_cutted_5 = new G4SubtractionSolid("side3_cutted_5", side3_cutted_4, s3_cut3_box,rotm, G4ThreeVector(0,26.65,51.25));
	G4SubtractionSolid * side3_cutted_6 = new G4SubtractionSolid("side3_cutted_6", side3_cutted_5, s3_cut3_box,rotm, G4ThreeVector(0,26.65,-51.25));
	G4SubtractionSolid * side3_cutted_7 = new G4SubtractionSolid("side3_cutted_7", side3_cutted_6, s3_cut4_box,rotm, G4ThreeVector(0,18.9,9.5));


	G4LogicalVolume * side3_lv = new G4LogicalVolume(side3_cutted_7,
			AlMaterial,
			"side1_lv", 0,0,0);

	//logical volumes

	G4LogicalVolume * side1_lv = new G4LogicalVolume(side1_cutted_6,
			AlMaterial,
			"side1_lv", 0,0,0);
	G4LogicalVolume * side2_lv = new G4LogicalVolume(side2_cutted_6,
			AlMaterial,
			"side2_lv", 0,0,0);
	/*

	   G4PVPlacement * side1_pv_1 = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200,41.50+height/2-21.5-side_1_y/2,-side_2_z/2.-side_1_z/2),
	   side1_lv,
	   "side1_pv_1",
	   W_log,
	   0,
	   true);

	   G4PVPlacement * side1_pv_2 = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200,41.50+height/2-21.5-side_1_y/2,+side_2_z/2.+side_1_z/2),
	   side1_lv,
	   "side1_pv_2",
	   W_log,
	   0,
	   true);

	   G4PVPlacement * side2_pv_1 = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200+side_1_x/2+side_2_x/2,41.50+height/2-21.5-side_1_y/2,0.),
	   side2_lv,
	   "side2_pv_1",
	   W_log,
	   0,
	   true);


	   G4PVPlacement * side2_pv_2 = new G4PVPlacement(rotm1,
	   G4ThreeVector(-200-side_1_x/2-side_2_x/2-17.75+11.25,41.50+height/2-21.5-side_1_y/2,0.),
	   side3_lv,
	   "side2_pv_2",
	   W_log,
	   0,
	   true);

*/
	//Local Shielding ////////////
	G4Box * TaBox = new G4Box("TaBox",3.6089/2*cm,2/2*mm,0.685/2*cm);

	G4Box * TaBox1 = new G4Box("TaBox1",0.325/2*cm,3/2*mm,0.325/2*cm);
	G4Box * TaBox2 = new G4Box("TaBox2",0.635/2*cm,3/2*mm,0.635/2*cm);

	G4Box * TaBox4 = new G4Box("TaBox3",1.1418/2*cm,3/2*mm,2.472/2*cm);

	G4Box * TaBox3 = new G4Box("TaBox4",0.325*cm,3/2*mm,0.325*cm);

	//14+16 bot
	G4Box * TaBox5 = new G4Box("TaBox5",0.635/2*cm,2/2*mm,0.635/2*cm);

	//little side
	G4Box * TaBox6_full = new G4Box("TaBox6_full",0.585/2*cm,1.8/2*mm,0.625/2*cm);
	G4Box * TaBox6_cut = new G4Box("TaBox6_cut",0.385/2*cm,1.8/2*mm,0.425/2*cm);
	G4SubtractionSolid * TaBox6 = new G4SubtractionSolid("Tabox6", TaBox6_full, TaBox6_cut, rotm, G4ThreeVector(0,0,0));
	//component 1 and 2  
	G4Box * TaBox7 = new G4Box("TaBox7",1.384/2*cm,1./2*mm,2.032/2*cm);
	//component 34 and 35
	G4Box * AlBox8 = new G4Box("AlBox8",0.2/2*cm,18/2*mm,1.4/2*cm);
	G4Box * TaBox8 = new G4Box("TaBox8",0.2/2*cm,18/2*mm,1.4/2*cm);
	//component 17 (oscillator
	G4Box * TaBox9_full = new G4Box("TaBox9_full",1.383/2*cm,2./2*mm,1.08/2*cm);
	G4Box * TaBox9_cut = new G4Box("TaBox9_cut",1.283/2*cm,2./2*mm,0.98/2*cm);
	G4SubtractionSolid * TaBox9 = new G4SubtractionSolid("Tabox9", TaBox9_full, TaBox9_cut, rotm, G4ThreeVector(0,0,0));

	//component 33
	G4Box * TaBox10_full = new G4Box("TaBox10_full",0.761/2*cm,2./2*mm,0.761/2*cm);
	G4Box * TaBox10_cut = new G4Box("TaBox10_cut",0.661/2*cm,2./2*mm,0.661/2*cm);
	G4SubtractionSolid * TaBox10 = new G4SubtractionSolid("Tabox10", TaBox10_full, TaBox10_cut, rotm, G4ThreeVector(0,0,0));


	G4LogicalVolume * Ta_lv = new G4LogicalVolume(TaBox,
			TaMaterial,
			"Ta_lv", 0,0,0);

	G4LogicalVolume * Ta1_lv = new G4LogicalVolume(TaBox1,
			TaMaterial,
			"Ta1_lv", 0,0,0);

	G4LogicalVolume * Ta2_lv = new G4LogicalVolume(TaBox2,
			TaMaterial,
			"Ta2_lv", 0,0,0);
	G4LogicalVolume * Ta3_lv = new G4LogicalVolume(TaBox3,
			TaMaterial,
			"Ta3_lv", 0,0,0);
	G4LogicalVolume * Ta4_lv = new G4LogicalVolume(TaBox4,
			TaMaterial,
			"Ta4_lv", 0,0,0);
	G4LogicalVolume * Ta5_lv = new G4LogicalVolume(TaBox5,
			TaMaterial,
			"Ta5_lv", 0,0,0);
	G4LogicalVolume * Ta6_lv = new G4LogicalVolume(TaBox6,
			TaMaterial,
			"Ta6_lv", 0,0,0);
	G4LogicalVolume * Ta7_lv = new G4LogicalVolume(TaBox7,
			TaMaterial,
			"Ta7_lv", 0,0,0);
	G4LogicalVolume * Al8_lv = new G4LogicalVolume(AlBox8,
			AlMaterial,
			"Al8_lv", 0,0,0);
	G4LogicalVolume * Ta8_lv = new G4LogicalVolume(TaBox8,
			TaMaterial,
			"Ta8_lv", 0,0,0);
	G4LogicalVolume * Ta9_lv = new G4LogicalVolume(TaBox9,
			TaMaterial,
			"Ta9_lv", 0,0,0);
	G4LogicalVolume * Ta10_lv = new G4LogicalVolume(TaBox10,
			TaMaterial,
			"Ta10_lv", 0,0,0);


	Ta_lv->SetVisAttributes(CopVisAttributes);
	Ta1_lv->SetVisAttributes(CopVisAttributes);
	Ta2_lv->SetVisAttributes(CopVisAttributes);
	Ta3_lv->SetVisAttributes(CopVisAttributes);
	Ta4_lv->SetVisAttributes(CopVisAttributes);
	Ta5_lv->SetVisAttributes(CopVisAttributes);
	Ta6_lv->SetVisAttributes(CopVisAttributes);
	Ta7_lv->SetVisAttributes(CopVisAttributes);
	Al8_lv->SetVisAttributes(AluVisAttributes);
	Ta8_lv->SetVisAttributes(CopVisAttributes);
	Ta9_lv->SetVisAttributes(CopVisAttributes);
	Ta10_lv->SetVisAttributes(CopVisAttributes);


	//ADCs
	G4PVPlacement *TaADCtop_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-42.68,41.50-height/2+64.05+1,21.81),
			Ta_lv,
			"TaADCtop_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *TaADCbot_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-42.68,41.50-height/2+64.05-4.765,21.81),
			Ta_lv,
			"TaADCbot_pv",
			W_log,
			false,
			0,
			true);


	//transistores
	G4PVPlacement *Ta11_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+27.49,41.50-height/2+5+13.20+1,12.18),
			Ta1_lv,
			"Ta11_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta12_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+28.94,41.50-height/2+5+13.20+1,29.13),
			Ta1_lv,
			"Ta12_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta13_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-69.07,41.50-height/2+5+5.3+0.5,-10.05),
			Ta3_lv,
			"Ta13_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta14_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-19.05,41.50-height/2+5+5.3+0.5,-17.72),
			Ta3_lv,
			"Ta14_pv",
			W_log,
			false,
			0,
			true);


	G4PVPlacement *Ta21_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+19.25,41.50-height/2+5+5.3+0.5,-44.61),
			Ta2_lv,
			"Ta21_pv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement *Ta22_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+19.32,41.50-height/2+5+5.3+0.5,-35.95),
			Ta2_lv,
			"Ta22_pv",
			W_log,
			false,
			0,
			true);

	//Transistores perto dos ADCs
	G4PVPlacement *Ta31_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-69.68+11.418/2-3,41.50-height/2+64.05+1,34.86-24.72/2+3),
			Ta4_lv,
			"Ta31_pv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement *Ta32_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-64.70,41.50-height/2+64.05+1.5-7.975,34.86),
			Ta5_lv,
			"Ta31_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta33_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-69.68,41.50-height/2+64.05+1.5-7.975,21.14),
			Ta5_lv,
			"Ta31_pv",
			W_log,
			false,
			0,
			true);

	//ladex
	G4PVPlacement *Ta41_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+60.14,41.50-height/2+64.05+1-28.70,-6.03),
			Ta6_lv,
			"Ta41_pv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement *Ta42_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200+47.13,41.50-height/2+64.05+1-28.70,-5.96),
			Ta6_lv,
			"Ta42_pv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement *Ta43_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-69.07,41.50-height/2+9+5.3+0.5,-10.05),
			Ta6_lv,
			"Ta43_pv",
			W_log,
			false,
			0,
			true);
	//component 1 and 2
	G4PVPlacement *Ta51_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-52.63,41.50-height/2+5+5.3+0.5,-37.98),
			Ta7_lv,
			"Ta51_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta52_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-34.94,41.50-height/2+5+5.3+0.5,-38.18),
			Ta7_lv,
			"Ta52_pv",
			W_log,
			false,
			0,
			true);
	//component 34 e 35
	G4PVPlacement *Al61_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-80.58-2-3.1,41.50-height/2+7.5+31.89,-13.52),
			Al8_lv,
			"Al61_pv",
			W_log,
			false,
			0,
			true);

	G4PVPlacement *Al62_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-80.58-2-3.1,41.50-height/2+7.5+31.89,40.08),
			Al8_lv,
			"Al62_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta61_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-80.58-2.6,41.50-height/2+7.5+31.89,-13.52),
			Ta8_lv,
			"Ta61_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta62_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-80.58-2.6,41.50-height/2+7.5+31.89,40.08),
			Ta8_lv,
			"Ta62_pv",
			W_log,
			false,
			0,
			true);
	//component 17 and 33

	G4PVPlacement *Ta71_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-49.64,41.50-height/2+7.5+52.10,-22.82),
			Ta9_lv,
			"Ta71_pv",
			W_log,
			false,
			0,
			true);
	G4PVPlacement *Ta72_pv = new G4PVPlacement(rotm1,
			G4ThreeVector(-200-50.01,41.50-height/2+7.5+52.10,-8.33),
			Ta10_lv,
			"Ta72_pv",
			W_log,
			false,
			0,
			true);

 G4LogicalVolumeStore* lvs = G4LogicalVolumeStore::GetInstance();
    std::vector<G4LogicalVolume*>::const_iterator lvciter;
    for( lvciter = lvs->begin(); lvciter != lvs->end(); lvciter++ )
    {
        G4double red= G4UniformRand();
        G4double green= G4UniformRand();
        G4double blue= G4UniformRand();
        G4double alpha=1;
        SetVisAttrib(*lvciter,red,green,blue,alpha);
        //randomize color
    }

//	parser.Write("space_detector.gdml",W_log);
	return W;



}


void SpaceDetectorConstruction::ConstructGeometry()
{


}
const G4double SpaceDetectorConstruction::GetWorldSizeZ() {
	return WorldZ;

}
const G4double SpaceDetectorConstruction::GetWorldSizeY() {
	return WorldY;


}

void SpaceDetectorConstruction::UseDirDetectorWithShielding(const G4double Thick, const G4double Unit) {

	useDirDetector = true;

	G4cout << " ShieldIonThick " <<   Thick << " Unit " << Unit << G4endl;

	ShieldDirThick=Thick;

}


void SpaceDetectorConstruction::SetDirDetNPinHolesPhi(G4double nphi=10){

	NphPH = nphi;
}


void SpaceDetectorConstruction::SetDirDetNPinHolesTheta(G4double ntheta=3) {

	NthPH = ntheta;
}


void SpaceDetectorConstruction::SetDirDetPinHoleMaterial(G4String PhMat="Vacuum") {



	G4cout << " SpaceDetectorConstruction: Pin hole material " << PhMat.c_str() << G4endl;

	if (PhMat == "Copper") phMaterial = CuMaterial;

}

void SpaceDetectorConstruction::UseIonDetectorWithShielding(const G4double Thick, const G4double Unit) {
	useIonDetector = true;

	G4cout << " ShieldIonThick " <<   Thick << " Unit " << Unit << G4endl;
	ShieldIonThick=Thick;
}

void SpaceDetectorConstruction::SetSthick(G4double shieldingthickness=0.)
{
	shthick=shieldingthickness;
}





std::vector<G4double> SpaceDetectorConstruction::GetDetectorID() {

	return DetectorID ;
}


void SpaceDetectorConstruction::SetVisAttrib(G4LogicalVolume *log, G4double red, G4double green, G4double blue, G4double alpha)
{
    if(!log)return;
    G4VisAttributes *visAttrib=new G4VisAttributes(G4Colour(red,green, blue,alpha));
    visAttrib->SetForceWireframe(true);
    visAttrib->SetForceSolid(true);
    log->SetVisAttributes(visAttrib);
}

void SpaceDetectorConstruction::SetInvisible(G4LogicalVolume *log)
{
    if(!log)return;
    log->SetVisAttributes(G4VisAttributes::Invisible);
}

