//Patryk Socha
//18.01.2017

using namespace std;
int makehist()
{
	Long64_t entries;
	Int_t    bins = 50;
	Int_t	 thr = 15;
	Double_t pe;
	Float_t  pm[1600];
	TString	 filename = "proton_0_0";

	TFile	*file = new TFile(filename+".root");
	TTree	*tree = (TTree*)file->Get("polar");
//	TH1	*hele = (TH1*)file->Get("quicklook/hele");

	tree->SetBranchAddress("particle_energy",&pe);
	tree->SetBranchAddress("pm", pm);

	Int_t xmin = thr;
	Int_t xminini = 10000;
	Int_t xmax = 50000;
	Double_t logxmin = TMath::Log10(xmin);
	Double_t logxminini = TMath::Log10(xminini);
	Double_t logxmax = TMath::Log10(xmax);
	Double_t binwidth = (logxmax-logxmin)/bins;
	Double_t binwidthini = (logxmax-logxminini)/bins;
	Double_t xbins[bins+1], xbinsini[bins+1];

	for (Int_t i=0;i<=bins;i++)
	{
		xbins[i] = TMath::Power(10,logxmin+i*binwidth);
		xbinsini[i] = TMath::Power(10, logxminini+i*binwidthini);
	}
	entries = tree->GetEntries();
//	hele->SetAxisRange(xminini, xmax);

	TH1	*hele  = new TH1D("hele", "Initial enegry spectrum", bins, xbinsini);
	TH1	*hini1 = new TH1D("hini1", "Effective proton energy spectrum, n=1", bins, xbinsini);
	TH1	*hini2 = new TH1D("hini2", "Effective proton energy spectrum, n>1", bins, xbinsini);
	TH1	*heff1 = new TH1D("heff1", "Thr. 15 keV, angle 0 deg., n=1", bins, xbinsini);
	TH1	*heff2 = new TH1D("heff2", "Thr. 15 keV, angle 0 deg., n>1", bins, xbinsini);
	TH1	*hspe  = new TH1D("hspe", "Energy spectrum of all channels", bins, xbins);
	TH2	*hdhe  = new TH2D("hdhe", "Deposited to initial energy", bins, xbinsini, bins, xbins);
	TH2	*hbar  = new TH2D("hbar", "Energy deposited in particular bar", 40, 0, 40, 40, 0, 40);
	TH2	*hmui  = new TH2D("hmui", "Multiplicity for initial energy", bins, xbinsini, 10, 1, 10);
	TH2	*hmud  = new TH2D("hmud", "Multiplicity for deposited energy", bins, xbins, 10, 1, 10);

	TCanvas	*canv = new TCanvas("canv", "Histograms plot", 0, 0, 800, 1500);
	canv->Divide(2,5);

//	TCanvas *can2 = new TCanvas("can2", "Multiplicity histograms", 0, 0, 400, 600);
//	can2->Divide(1,2);

	hele->SetTitle("Initial energy spectrum");
	hele->SetXTitle("Proton energy [keV]");
	hele->SetYTitle("counts");

	hini1->SetXTitle("Proton energy [keV]");
	hini1->SetYTitle("Counts");

	hini2->SetXTitle("Proton energy [keV]");
	hini2->SetYTitle("Counts");

	hspe->SetXTitle("Deposited energy [keV]");
	hspe->SetYTitle("Counts");

	heff1->SetXTitle("Incident proton energy [keV]");
	heff1->SetYTitle("Detection efficiency");

	heff2->SetXTitle("Incident proton energy [keV]");
	heff2->SetYTitle("Detection efficiency");

	
	hdhe->SetXTitle("Initial proton energy [keV]");
	hdhe->SetYTitle("Deposited energy [keV]");
	hdhe->SetZTitle("Counts");

	hbar->SetXTitle("Bar number");
	hbar->SetYTitle("Bar number");
	hbar->SetZTitle("Deposited energy [keV]");

	hmui->SetXTitle("Initial proton energy [keV]");
	hmui->SetYTitle("Multiplicity");
	hmui->SetZTitle("Counts");

	hmud->SetXTitle("Deposited energy [keV]");
	hmud->SetYTitle("Multiplicity");
	hmud->SetZTitle("Counts");

	for (Long64_t i=0; i<entries; i++)
	{
        	tree->GetEntry(i);

		hele->Fill(pe);

	        Int_t triggered = 0;
        	for (Int_t j=0; j<1600; j++)
        	{
            		if (pm[j]>thr)
			{
                		triggered++;
				hspe->Fill(pm[j]);
				hdhe->Fill(pe, pm[j]);
				hbar->SetBinContent(j%40+1, j/40+1, hbar->GetBinContent(j%40+1, j/40+1)+pm[j]);

			}
        	}

        	if (triggered==1)
		{
			hini1->Fill(pe);
			hmui->Fill(pe, triggered);
			for (Int_t j=0; j<1600; j++)
				if (pm[j]>thr)
					hmud->Fill(pm[j], triggered);
		}

		else if (triggered>1 && triggered<=10)
		{
			hini2->Fill(pe);
			hmui->Fill(pe, triggered);
			for (Int_t j=0; j<1600; j++)
				if (pm[j]>thr)
					hmud->Fill(pm[j], triggered);
		}
		else if (triggered>10)
		{
			hmui->Fill(pe, 10);
			for (Int_t j=0; j<1600; j++)
				if (pm[j]>thr)
					hmud->Fill(pm[j], 10);
		}

    	}
    	for (Int_t i=0; i<bins; i++)
	{
        	//calculate the efficiency
/*	        Double_t xlow1 = hini1->GetBinLowEdge(i+1);
        	Double_t xup1  = xlow1+hini1->GetBinWidth(i+1);
	        Int_t	 binlow1, binup1=0;
        	binlow1 = hele->FindBin(xlow1);
	        binup1  = hele->FindBin(xup1);

	        Float_t counts1 = hele->Integral(binlow1,binup1);
        	Float_t efficiency1 = hini1->GetBinContent(i+1)/counts1;
	        heff1->SetBinContent(i+1, efficiency1);

	        Double_t xlow2 = hini2->GetBinLowEdge(i+1);
        	Double_t xup2  = xlow2+hini2->GetBinWidth(i+1);
	        Int_t	 binlow2, binup2=0;
        	binlow2 = hele->FindBin(xlow2);
	        binup2  = hele->FindBin(xup2);

	        Float_t counts2 = hele->Integral(binlow2,binup2);
        	Float_t efficiency2 = hini2->GetBinContent(i+1)/counts2;
	        heff2->SetBinContent(i+1, efficiency2);*/

		heff1->SetBinContent(i+1, hini1->GetBinContent(i+1)/hele->GetBinContent(i+1));
		heff2->SetBinContent(i+1, hini2->GetBinContent(i+1)/hele->GetBinContent(i+1));
    	}

	hdhe->SetBit(TH1::kNoStats);
	hbar->SetBit(TH1::kNoStats);
	hmui->SetBit(TH1::kNoStats);
	hmud->SetBit(TH1::kNoStats);

	canv->cd(1)->SetLogy();
	canv->cd(1)->SetLogx();
	canv->cd(2)->SetLogy();
	canv->cd(2)->SetLogx();
	canv->cd(3)->SetLogy();
//	canv->cd(3)->SetLogx();
	canv->cd(4)->SetLogy();
//	canv->cd(4)->SetLogx();
	canv->cd(5)->SetLogy();
//	canv->cd(5)->SetLogx();
	canv->cd(6)->SetLogy();
//	canv->cd(6)->SetLogx();
//	canv->cd(7)->SetLogz();
	canv->cd(7)->SetLogy();
//	canv->cd(7)->SetLogx();
//	canv->cd(8)->SetLogz();
//	can2->cd(9)->SetLogz();
//	canv->cd(9)->SetLogx();
//	can2->cd(10)->SetLogz();
	canv->cd(10)->SetLogx();

	canv->cd(1);
	hele->Draw();
	canv->cd(2);
	hspe->Draw();
	canv->cd(3);
	hini1->Draw();
	canv->cd(4);
	hini2->Draw();
	canv->cd(5);
	heff1->Draw();
	canv->cd(6);
	heff2->Draw();
	canv->cd(7);
	hdhe->Draw("COLZ");
	canv->cd(8);
	hbar->Draw("COLZ");
	canv->cd(9);
	hmui->Draw("COLZ");
	canv->cd(10);
	hmud->Draw("COLZ");

	canv->Draw();
	canv->Print(filename+".pdf");
//	can2->Draw();
//	can2->Print("multi_"+filename+".pdf");
   	return 0;
}
