#include <TFile.h>
#include <TString.h>
#include <TKey.h>
#include <TH2D.h>
#include <assert.h>

void Draw_hist(){
TFile *_file0 = TFile::Open("X_S_shape.root","r");
assert(_file0);
TString hname="hist";
/*
TKey *key = _file0->FindKey(hname);
if (key ==0){
  cout << "!!Histogram does not exist!!" << endl;
  throw 1;
}
*/
TH2D *h =  (TH2D*)_file0->Get(hname);
h->GetXaxis()->SetRangeUser(-0.1,0); // Set the range
h->SetFillColor(kYellow); // Fill fill color to yellow
h->SetFillColor(kYellow); // Fill fill color to yellow
h->SetMarkerStyle(20); h->SetMarkerColor(kBlue); h->SetMarkerSize(.6); // Draw histograms with blue markers
h->Draw();
}
