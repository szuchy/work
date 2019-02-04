/***************************************************************
 * Run action
 * Author  : Hualin Xiao
 * Date    : Jan, 2015
 * Version : 1.10
 ***************************************************************/
#include "stdlib.h"


#include "G4Run.hh"
#include "G4RunManager.hh"
#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

#include "AnalysisManager.hh"
#include "RunAction.hh"
using namespace std;

RunAction::RunAction()
 :	G4UserRunAction()
{ 
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run* run)
{ 
	G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
	AnalysisManager* analysisManager = AnalysisManager::GetInstance();
    analysisManager->BeginOfRunAction(run);
}

void RunAction::EndOfRunAction(const G4Run* aRun)
{
    
    AnalysisManager* analysisManager = AnalysisManager::GetInstance();
    analysisManager->EndOfRunAction(aRun); 
	
	G4cout << "### This run has been finish." << G4endl;
	
}
