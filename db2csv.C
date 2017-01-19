//This program reads settings of modules from files and writes them into .csv file
//Author: Patryk Socha, Hualin Xiao
//Date: 09.07.2015
//PSI

#include <iostream>
#include <fstream>
#include <string>    

#include <TCanvas.h>
#include <TH1F.h>
#include <TMath.h>
#include <TROOT.h>
#include <TStyle.h>

#include "include/lib_det.h"
#include "include/lib_exp.h"
#include "TF1.h"

using namespace std; 

void Help()
{
    cout<<"db2csv -det <type> -indir <directory> -o <output.csv>"<<endl;
}

int main(int argc, char **argv)
{
    TROOT app("app","app");
    gROOT->SetStyle("Plain");

    Int_t           fee_id;
    Int_t           pmt_id;
    Int_t           firmware_id;
    Int_t           target_id;
    Int_t           if_id;
    Int_t           asic_id;
    Int_t           vd_id;
    Long64_t        sensor_id;
    Float_t         module_id;
    Float_t         hv;
    Float_t         vfp;
    Float_t         vpz;
    Float_t         vfs;
    Float_t         vrc;
    Float_t         vthr;
    Float_t         vcal;
    Float_t         pw_dynode;
    Float_t         dummy2;
    Float_t         dac1;
    Float_t         dac2;
    Float_t         dac_too_many;
    Float_t         dac_dy12;
    Float_t         dynode_1;
    Float_t         pw12_too_many;
    Float_t         pw_too_high;
    Float_t         dynode_2;
    Int_t           disable[65];
    Char_t          offset[129];
    Float_t         firmware_version;
    Float_t         version;
    Bool_t          is_valid;
    Int_t           test_on[65];
    Int_t	    value[65];
    Char_t	    number[3];

    TCanvas* plots = new TCanvas("plots1","Plots",0,0,500,500);
    plots->Divide(3,5);

    TH1F* hhv = new TH1F("hhv","High voltage",25,0,25);
    TH1F* hvrp = new TH1F("hvrp","vrp",25,0,25);
    TH1F* hvfp = new TH1F("hvfp","vfp",25,0,25);
    TH1F* hvpz = new TH1F("hvpz","vpz",25,0,25);
    TH1F* hvfs = new TH1F("hvfs","vfs",25,0,25);
    TH1F* hvrc = new TH1F("hvrc","vrc",25,0,25);
    TH1F* hvthr = new TH1F("hvthr","vthr",25,0,25);
    TH1F* hdac1 = new TH1F("hdac1","dac1",25,0,25);
    TH1F* hdac2 = new TH1F("hdac2","dac2",25,0,25);
    TH1F* hdactm = new TH1F("hdactm","dac too many",25,0,25);
    TH1F* hdac_dy12 = new TH1F("hdac_dy12","Dac dy12",25,0,25);
    TH1F* hdynode1 = new TH1F("hdynode1","Dynode 1",25,0,25);
    TH1F* hdisable = new TH1F("hdisable","Disable",25,0,25);
    TH1F* hoffset = new TH1F("hoffset","Offset [changed modules]",25,0,25);


    const char* binname[25];

    TString output="ModuleSettings.csv";
    TString type="FM";

    Int_t s=0;
    TString sel;
    TString indir=".";
    while (s<argc-1) {
        sel = argv[++s];
        if( sel == "help" || sel=="-h" ){
            Help();
            return 0;
        } else if( sel == "-det" )
        {
            type=argv[++s];
        } 
        else if( sel == "-o")
        {
            output=argv[++s];
        }
        else if( sel == "-indir")
        {
            indir=argv[++s];
        }
        else
        {
            cout<<"can not understand: "<<sel<<endl;
            return 0;
        }
    }

    DataType *detector=new DataType(type);

    ofstream tablefile;
    tablefile.open(output);
    tablefile<<"module id,fee id,pmt id,firmware id,target id,if id,asic id,vd id,sensor id,high voltage,vfp,vpz,vfs,vrc,vthr,vcal,pw dynode,dummy2,dac1,dac2,dac too many,dac dy12,dynode1,pw12 too many,pw too high,dynode2,disable channel,offset,test on,firmware version\n";

    for(int k=0;k<5;k++)
        for(int l=0;l<5;l++)
        {
            int module_id=detector->Pos2ModID[k*5+l];
            TString lisfile=Form("%s/module_%03d.lis",indir.Data(),module_id);
            FILE * f=fopen(lisfile.Data(),"r");
            if (!f)
            {
                cout<<"can not find: "<<lisfile<<endl;
                return 0;
            }

            TString tmp;
            const int max=32;
            TString* lines=new TString[max];
            tmp.Gets(f);//skip first line
            int i=0;
            while (tmp.Gets(f))
            {
                if ((tmp==""))continue;
                if ((tmp.BeginsWith("#")))continue;
                lines[i]=tmp;
                i++;
                if (i>=max)break;
            }
            if (i!=max)
            {
                cout<<"wrong format in: "<<lisfile<<endl;
                return 0;
            }
            int j=0;
            do
            {
                tablefile<<Form("%3d",module_id)<<",";
                i=sscanf(lines[j].Data(),"%d",&fee_id);
                tablefile<<fee_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&pmt_id);
                tablefile<<pmt_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&firmware_id);
                tablefile<<firmware_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&target_id);
                tablefile<<target_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&if_id);
                tablefile<<if_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&asic_id);
                tablefile<<asic_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%d",&vd_id);
                tablefile<<vd_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%llx",&sensor_id);
                tablefile<<sensor_id<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%s",number);
                binname[k*5+l]=number;
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&hv);
                tablefile<<hv<<",";
                hhv->SetBinContent(k*5+l+1,TMath::Abs(hv));
                hhv->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vfp);
                tablefile<<vfp<<",";
                hvfp->SetBinContent(k*5+l+1,vfp);
                hvfp->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vpz);
                tablefile<<vpz<<",";
                hvpz->SetBinContent(k*5+l+1,vpz);
                hvpz->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vfs);
                tablefile<<vfs<<",";
                hvfs->SetBinContent(k*5+l+1,vfs);
                hvfs->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vrc);
                tablefile<<vrc<<",";
                hvrc->SetBinContent(k*5+l+1,vrc);
                hvrc->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vthr);
                tablefile<<vthr<<",";
                hvthr->SetBinContent(k*5+l+1,vthr);
                hvthr->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&vcal);
                tablefile<<vcal<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&pw_dynode);
                tablefile<<pw_dynode<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dummy2);
                tablefile<<dummy2<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dac1);
                tablefile<<dac1<<",";
                hdac1->SetBinContent(k*5+l+1,dac1);
                hdac1->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dac2);
                tablefile<<dac2<<",";
                hdac2->SetBinContent(k*5+l+1,dac2);
                hdac2->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dac_too_many);
                tablefile<<dac_too_many<<",";
                hdactm->SetBinContent(k*5+l+1,dac_too_many);
                hdactm->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dac_dy12);
                tablefile<<dac_dy12<<",";
                hdac_dy12->SetBinContent(k*5+l+1,dac_dy12);
                hdac_dy12->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dynode_1);
                tablefile<<dynode_1<<",";
                hdynode1->SetBinContent(k*5+l+1,dynode_1);
                hdynode1->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&pw12_too_many);
                tablefile<<pw12_too_many<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&pw_too_high);
                tablefile<<pw_too_high<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&dynode_2);
                tablefile<<dynode_2<<",";
                if (i!=1)break;j++;
                for (int m=0;m<65;m++)
                {
                    i=sscanf(lines[j].Data()+2*m,"%d",&disable[m]);
                    tablefile<<disable[m]<<" ";
                    hdisable->AddBinContent(k*5+l+1,disable[m]);
                    if (i!=1)break;
                }
                tablefile<<",";
                hdisable->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                if (i!=1)break;j++;
                /*for (int k=0;k<65;k++)
                  {
                  i=sscanf(lines[j].Data()+2*k,"%d",&offset[k]);
                  tablefile<<offset[k]<<" ";
                  if (i!=1)break;
                  }*/
                i=sscanf(lines[j].Data(),"%s",offset);
                tablefile<<offset<<",";
                hoffset->GetXaxis()->SetBinLabel(k*5+l+1,binname[k*5+l]);
                for (int m=0;m<65;m++)
                {
                    i=sscanf(lines[j].Data()+2*m,"%d",&value[m]);
                    if(value[m]!=0)hoffset->AddBinContent(k*5+l+1,1);
                }
                if (i!=1)break;j++;
                for (int m=0;m<65;m++)
                {
                    i=sscanf(lines[j].Data()+2*m,"%d",&test_on[m]);
                    tablefile<<test_on[m]<<" ";
                    if (i!=1)break;
                }
                tablefile<<",";
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&firmware_version);
                tablefile<<firmware_version<<endl;
                if (i!=1)break;j++;
                i=sscanf(lines[j].Data(),"%f",&version);
                if (i!=1)break;j++;
                int valid;
                i=sscanf(lines[j].Data(),"%d",&valid);
                if (i!=1)break;j++;
                is_valid=valid==1;
                /* too verbose. Let the user test.
                   if (!is_valid)
                   {
                   printf("caution we have read an invalid module setting\n");
                   }
                   */
            } while (0);
            if(j!=max)
            {
                printf("wrong format at line %d\n",j);
                return 0;
            }
        }

    plots->cd(1);
    hhv->Draw();
    plots->cd(2);
    hvfp->Draw();
    plots->cd(3);
    hvpz->Draw();
    plots->cd(4);
    hvfs->Draw();
    plots->cd(5);
    hvrc->Draw();
    plots->cd(6);
    hvthr->Draw();
    plots->cd(7);
    hdac1->Draw();
    plots->cd(8);
    hdac2->Draw();
    plots->cd(9);
    hdactm->Draw();
    plots->cd(10);
    hdac_dy12->Draw();
    plots->cd(11);
    hdynode1->Draw();
    plots->cd(12);
    hdisable->Draw();
    plots->cd(13);
    hoffset->Draw();
    if(output.Contains(".csv"))output.ReplaceAll(".csv",".pdf");
    else
    {
        output+=".pdf";
    }
    plots->Print(output);
    return 0;
}
