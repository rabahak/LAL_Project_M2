#include <TFile.h>
#include <TString.h>
#include <TKey.h>
#include <TH2D.h>
#include <assert.h>
#include <TProfile.h>
#include <TF1.h>

/*
{
// macro to plot distributions from the Event tree
 gROOT->Reset();
 TFile* f = new TFile("Event.root");
 TTree * T = (TTree*)f->Get("T");
 cout <<  f << endl; // check the pointer to the root file
 cout <<  T << endl; // check the pointer to the the tree
 cout << "Number of Entries in tree : "<< T->GetEntries() <<  endl;

 T->Draw("feReco")   ;
}
*/

void make_S_shape(TString file_name, Bool_t corrected=0){
  TFile * f = TFile::Open(file_name,"r");
  TTree * tree = (TTree*)f->Get("T");

  TFile *S_shape_file;
if(!corrected)
S_shape_file = new TFile("S_shapes.root","RECREATE");
else
S_shape_file = new TFile("S_shapes_corrected.root","RECREATE");
//=========== S SHAPE FOR X
if(!corrected)
tree->Draw("fxReco - x_impact:fxReco");
else
tree->Draw("fxReco_corr - x_impact:fxReco_corr");
//TCanvas * c1 = new TCanvas("c","c");
TH2D * hx = new TH2D("hist","hist",100,-0.08,0.03,100,-0.04,0.04);
  for ( Int_t i=0; i< tree->GetSelectedRows(); i++) {
  hx->Fill(tree->GetV2()[i],tree->GetV1()[i]);
      }
  hx->Write();
  //c1->Update();
  auto profx = hx->ProfileX("profx");
  profx->Write();
  // =========== S SHAPE FOR Y
  if(!corrected)
  tree->Draw("fyReco - y_impact:fyReco");
  else
  tree->Draw("fyReco_corr - y_impact:fyReco_corr");
  //TCanvas * c1 = new TCanvas("c","c");
  TH2D * hy = new TH2D("hist","hist",100,-0.08,0.03,100,-0.04,0.04);
    for ( Int_t i=0; i< tree->GetSelectedRows(); i++) {
    hy->Fill(tree->GetV2()[i],tree->GetV1()[i]);
        }
    hy->Write();
    //c1->Update();
    auto profy = hy->ProfileX("profy");
    profy->Write();


  S_shape_file->Write();
  S_shape_file->Close();
}


void Draw(TString pname,Float_t min=-0.08,Float_t max=0.03,Bool_t x=1,Bool_t corrected=0){
TCanvas * c = new TCanvas(pname,pname);
TString file_name = "";
if(!corrected)
file_name = "S_shapes.root";
else
file_name = "S_shapes_corrected.root";

TFile *_file0 = TFile::Open(file_name,"r");


TProfile *h =  (TProfile*)_file0->Get(pname);
if(!corrected){
TF1 *f1 = new TF1("f1", "[0]*sin([1]*x + [2])", min,max);
if(x)
f1->SetParameters(0.01,-70,-3);
else
f1->SetParameters(0.01,-70,-3);
h->Fit("f1");}
h->SetMarkerStyle(20); h->SetMarkerColor(kBlue); h->SetMarkerSize(.6); // Draw histograms with blue markers
h->Draw();
c->Update();
}
