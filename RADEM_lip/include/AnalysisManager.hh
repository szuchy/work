//
/// \file AnalysisManager.hh
/// \brief Definition of the AnalysisManager class

#ifndef AnalysisManager_h
#define AnalysisManager_h 1

#include <vector>
#include "globals.hh"

//#include "G4Step.hh"
//#include "G4Event.hh"
//#include "G4Run.hh"
#include "TString.h"
class G4Run;
class G4Event;
class G4Step;

class TCanvas;
class TH1F;
class TFile;
class TTree;
class AnalysisMessenger;


const G4int kMaxTracks=30;
const G4int kMaxSD=100;

class AnalysisManager
{
    public:
        static AnalysisManager* GetInstance();
        static void Dispose();

        void OpenFile();
        void BookTree();
        void BookHistograms();
        void Dump();

        void SetOutputFileName(TString filen){outputFilename=filen;}


        void AddSD(TString det){fSDNameList.push_back(det);}
       	void AddEnergy(G4int detId, G4double edep);
    	void AddNonIonizingEnergy(G4int detId, G4double edep){};


        void BeginOfEventAction(const G4Event *event);
        void EndOfEventAction(const G4Event *event);
        void SteppingAction(const G4Step *aStep);
        void BeginOfRunAction(const G4Run *);
        void EndOfRunAction(const G4Run *);

        void WriteMacros(G4String macfilename);
        
        
        void SetStoreHist(G4bool value){fStoreHist=value;}
        void SetStoreTree(G4bool value){fStoreTree=value;}
        void SetStoreTrack(G4bool value){fStoreTrack=value;}

        void SetLeavesForTracks();
        

        AnalysisManager();
        ~AnalysisManager();

    private:
        AnalysisMessenger *fAnalysisMessenger;

        static AnalysisManager* fManager;
        std::vector<TString > fSDNameList;
        //sensitive detector list

        G4int fNbSD; //number of sensitive volumes

        G4int fEventID;


        G4bool fStoreTree;
        G4bool fStoreHist;
        G4bool fStoreTrack;

        TString outputFilename;

        TFile* fTFile;
        TTree* fTree;


        long long fEventsFill;
        G4bool recordFluence;


        //source
        G4double source_pos[3];
        G4double source_dir[3];
        G4double source_kine;
        //source information




    	G4double fEdepSum[kMaxSD];
        //sensitive detector name;

        //track entering sensitive detectors
        G4int ntrack;
        G4double x[kMaxTracks];
        G4double y[kMaxTracks];
        G4double z[kMaxTracks];
        G4double dx[kMaxTracks];
        G4double dy[kMaxTracks];
        G4double dz[kMaxTracks];
        G4int enter[kMaxTracks];
        G4int escape[kMaxTracks];
        G4int pdg[kMaxTracks]; //particle name
        G4double energy[kMaxTracks]; //particle energy
        G4int SD_id[kMaxTracks]; 
        G4int parent_id[kMaxTracks]; //
        G4double time[kMaxTracks];

        //histogram
        TH1F *h_source_pos[3];
        TH1F *h_source_dir[3];
        TH1F *h_source_kine;
        TH1F *h_edep[kMaxSD];
        G4bool is_effective;
    

};



inline void AnalysisManager::AddEnergy(G4int det, G4double edep) 
{
    fEdepSum[det] += edep;
    is_effective=true;
}
#endif
