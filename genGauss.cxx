#include "TH1F.h"
#include "TRandom.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TFitResult.h"
#include <iostream>
using namespace std;

void genGauss() {
  int MAX = 1. ;
  // Histogram creation. We use "new", but root handles internally the pointers.
  // Therefore, you should not "delete" the histograms pointer
  TH1F* h = new TH1F("HGauss","Gaussian distribution",100,-2.,2.);

  // Draw 10000 numbers according the gaussian law
  // We use gRandom->Uniform(MAX)  to draw numbers
  // uniformly  between  0. and MAX
  for (int i=0; i<100000; i++)
  {
     float MAX = 100;
     float x = 0.;
     float y = 0.;
     x = gRandom->Uniform(-2.,2.);
     y = gRandom->Uniform(0,MAX);
     float y_gauss = MAX*TMath::Gaus(x) ;
     if(y<y_gauss)
     {
       h->Fill(x);
     }
    // we  fill here the histogram
  }
  TCanvas * c1 = new TCanvas("c", "c");
  h->Draw();

  // Fit
  TF1 f1("f1","gaus",-2,2);
  f1.SetParameters(MAX,0,1);
  h->Fit("gaus");
  TF1 *fit1 = (TF1*)h->GetFunction("gaus");
  double amplitude = fit1->GetParameter(0);
  double mean = fit1->GetParameter(1);
  double rms = fit1->GetParameter(2);
  //double integral = fit1->Integral(mean-3*rms, mean+3*rms);
  double integral = fit1->Integral(-2., mean-3*rms) + fit1->Integral(mean+rms, 2.);

  cout << "integral = "<<integral<<endl;
  cout << "unnormalized integral ="<<integral*(100./4.)<<endl;


}

void genGaussRoot(){
  TH1F* h = new TH1F("HGauss","Gaussian distribution",100,-2.,2.);

  for (int i=0; i<100000; i++)
  {
    h->Fill(gRandom->Gaus());
  }
  h->Draw();
  TCanvas * c1 = new TCanvas("c1", "c1");
  h->Fit("gaus");
}
