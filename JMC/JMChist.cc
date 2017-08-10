//Patryk Socha
//24.05.2017

using namespace std;
int JMChist()
{
	Long64_t entries;
	Float_t dose;
	Float_t edep;
	Float_t iniEnergy;
	TString	 filename = "JMC";

	TFile*	file = new TFile(filename+".root");
	TTree*	tree = (TTree*)file->Get("Tree");

	tree->SetBranchAddress("Dose", &dose);
	tree->SetBranchAddress("Edep", &edep);
	tree->SetBranchAddress("IniEnergy", &iniEnergy);

	entries = tree->GetEntries();

	cout << entries << endl;

/*	for(Int_t i=0; i<entries; i++)
	{
		tree->GetEntry(i);
		cout << iniEnergy << endl;
	}*/

	return 0;
}
