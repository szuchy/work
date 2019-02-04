/***************************************************************
 * Class to define detector messeger.
 * Author  : Hualin Xiao
 * Date    : Jan, 2015
 * Version : 1.10
 *
 ***************************************************************/

#include "globals.hh"

#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"

DetectorMessenger::DetectorMessenger(DetectorConstruction* theDet)
: fDetector(theDet) { 
	
	fDetectorDir = new G4UIdirectory( "/det/" );
	fDetectorDir->SetGuidance("Detector control.");

	fSetFileCommand = new G4UIcmdWithAString("/det/setGDML", this);
	fSetFileCommand ->SetGuidance("set cad filename");
	fSetFileCommand ->SetParameterName("cadfilename", false);
	fSetFileCommand ->AvailableForStates(G4State_PreInit);
  
	fSetWorldCommand = new G4UIcmdWithAString("/det/setWorld", this);
}

DetectorMessenger::~DetectorMessenger()
{
	delete fSetFileCommand;
	delete fSetWorldCommand;
	delete fDetectorDir;
}

void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{ 
	if (command == fSetFileCommand) { 
		fDetector->SetGDMLFile(newValue);
	}
	if (command == fSetWorldCommand) { 
		fDetector->SetWorld(newValue);
	}
}
