#ifndef Utility_h
#define Utility_h
#include <cmath>
#include "CalorimeterConstants.h"
#include "TH1F.h"
#include "TF1.h"

//Static is just a way of providing a useful function to many different C files.
//Each C file that includes the header will get its own definition that it can call.
static CellAddress xyz_to_CellAddress(float x,float y,float z){

    // Convert X num of Cells
    double xCell = (x+CalConst::XYMax)/CalConst::XYSize;
    xCell = int(xCell);

    // Convert Y num of Cells
    double yCell = std::abs(y-CalConst::XYMax)/CalConst::XYSize;
    yCell = int(yCell);

    // Convert Z num of Cells
    double num_lay = z/CalConst::ZSize;
    num_lay = int(num_lay);

    CellAddress my_celladdress(xCell,yCell,num_lay);
    return my_celladdress;
  }

static float CellAddress_to_XY(int ix){

    return (CalConst::XYMin+ix*(CalConst::XYSize));
}

static std::vector<float> fit_par_gauss(TH1F* hist){
  hist->Fit("gaus");
  TF1 * fit = (TF1*)hist->GetFunction("gaus");
  double max = fit->GetParameter(0);
  double mean = fit->GetParameter(1);
  double rms = fit->GetParameter(2);

  std::vector<float> result;
  result.push_back(max);
  result.push_back(mean);
  result.push_back(rms);

  return result;
}

/*
float get_mean_of_gaussFit(*TH1F my_hist, ){

  TF1 f1("f1","gaus",-2,2);
  f1.SetParameters(MAX,0,1);
  h->Fit("gaus");
  TF1 *fit1 = (TF1*)h->GetFunction("gaus");
  double amplitude = fit1->GetParameter(0);
  double mean = fit1->GetParameter(1);
  double rms = fit1->GetParameter(2);
}
*/

#endif
