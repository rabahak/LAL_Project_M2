#include <TFile.h>
#include <TString.h>
#include <TKey.h>
#include <TH2D.h>
#include <assert.h>
#include <TProfile.h>
#include <TF1.h>

void Draw(TString pname){
TFile *_file0 = TFile::Open("X_S_shape.root","r");
assert(_file0);
/*
TKey *key = _file0->FindKey(hname);
if (key ==0){
  cout << "!!Histogram does not exist!!" << endl;
  throw 1;
}
*/
TProfile *h =  (TProfile*)_file0->Get(pname);
TF1 *f1 = new TF1("f1", "[0]*sin([1]*x + [2])", -0.1,0.);
f1->SetParameters(0.02,1,0);
h->Fit("f1");
h->SetFillColor(kYellow); // Fill fill color to yellow
h->SetMarkerStyle(20); h->SetMarkerColor(kBlue); h->SetMarkerSize(.6); // Draw histograms with blue markers
h->Draw();
}
