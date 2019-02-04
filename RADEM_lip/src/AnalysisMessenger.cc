/**
 * @file: AnalysisMessenger.cc
 * @class AnalysisMessenger
 * @brief Implementation of AnalysisMessenger, to control AnalysisManager with macros
 *
 *
 * @Author  : Hualin Xiao
 * @Date    : Dec., 2015
 * @Version : 1.00
 */


#include "globals.hh"

#include "AnalysisMessenger.hh"
#include "AnalysisManager.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIcmdWithAnInteger.hh"
#include <G4UIcmdWithADoubleAndUnit.hh>
#include <G4UIcmdWithADouble.hh>
#include <G4UIcmdWithABool.hh>
#include <G4UIcmdWithAnInteger.hh>
#include "G4SystemOfUnits.hh"

AnalysisMessenger::AnalysisMessenger(AnalysisManager* theAna)
: fAnalysis(theAna) { 
	
	fAnalysisDir = new G4UIdirectory( "/analysis/" );
	fAnalysisDir->SetGuidance("Analysis control.");

 	fSetOutputFileNameCmd= new G4UIcmdWithAString("/analysis/setOutputFileName", this);

 	fAddSDCmd= new G4UIcmdWithAString("/analysis/addSD", this);
  fAddSDCmd->SetGuidance("Add sensitive detector");

   
  fBookHistoCmd= new G4UIcmdWithABool("/analysis/bookHist",this);
  fBookHistoCmd->SetGuidance("Book histograms or not ");

  fBookTreeCmd= new G4UIcmdWithABool("/analysis/bookTree",this);
  fBookTreeCmd->SetGuidance("Book tree. To record event in the tree or not");

  fStoreTrackCmd= new G4UIcmdWithABool("/analysis/storeTrack",this);
  fStoreTrackCmd->SetGuidance("a switch to store track or not in root files.");


}

AnalysisMessenger::~AnalysisMessenger()
{
    delete fSetOutputFileNameCmd;
    delete fAddSDCmd;
    delete fBookTreeCmd;
    delete fBookHistoCmd;
    delete fStoreTrackCmd;

}

void AnalysisMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{ 
	if (command == fSetOutputFileNameCmd) 
    { 
		fAnalysis->SetOutputFileName(newValue);
	}
	if (command == fAddSDCmd) 
    { 
		fAnalysis->AddSD(newValue);
	}
	if (command == fBookTreeCmd) 
    { 
		fAnalysis->SetStoreTree(fBookTreeCmd->GetNewBoolValue(newValue));
	}
	if (command == fBookHistoCmd) 
    { 
		fAnalysis->SetStoreHist(fBookHistoCmd->GetNewBoolValue(newValue));
	}
	if (command == fStoreTrackCmd) 
    { 
		fAnalysis->SetStoreTrack(fStoreTrackCmd->GetNewBoolValue(newValue));
	}
    
    



}
