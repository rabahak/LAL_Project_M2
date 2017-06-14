#include "TMath.h"
#include "CalCell.h"
#include "Utility.h"
#include <cmath>
//#include "CalorimeterGeometry.h"

class CalorimeterGeometry;

std::pair<float,float> reconstruct_XY(std::vector<CalCell>);
float reconstruct_energy(std::vector<CalCell>);
float fit_sin(float,float ,float ,float );
std::pair<float,float> correct_XY(float, float );
void reconstruct_event(Event * event)
{
  std::pair<float,float> position;
  std::pair<float,float> position_corrected;
  std::vector<CalCell> cells = event->cells();
  position = reconstruct_XY(cells);
  position_corrected = correct_XY(position.first,position.second);

  event->setfxReco(position.first);
  event->setfxReco_err(position.first - event->get_x_impact());
  event->setfyReco(position.second);
  event->setfyReco_err(position.second - event->get_y_impact());

  event->setfxReco_corr(position_corrected.first);
  event->setfyReco_corr(position_corrected.second);

  event->seteReco(0);
  float eReco = reconstruct_energy(cells);
  event->seteReco(eReco);

}

std::pair<float,float> reconstruct_XY(std::vector<CalCell> Cells){

  float weighted_sumX=0;
  float weighted_sumY=0;
  float sum=0;

  for (std::vector<CalCell>::iterator iter = Cells.begin(); iter != Cells.end(); iter++)
  {
    float z=iter->address().layer();
    if(z==0){

    float x = CalorimeterGeometry::xCentre(iter->address());
    float y = CalorimeterGeometry::yCentre(iter->address());
    float E=iter->energy();
    weighted_sumX+=x*E;
    weighted_sumY+=y*E;
    sum+=E;
    }
  }
  float bar_x = weighted_sumX/sum;
  float bar_y = weighted_sumY/sum;

  std::pair<float,float> result;
  result.first = bar_x;
  result.second = bar_y;

  return result;
}

float reconstruct_energy(std::vector<CalCell> Cells){
  float eReco=0;
  for (std::vector<CalCell>::iterator iter = Cells.begin(); iter != Cells.end(); iter++){
    float my_energy = iter->energy();
   eReco+=my_energy;
  }
  return eReco;
}

std::pair<float,float> correct_XY(float x_rec, float y_rec){
  float x1=5.47657e-03 ,x2=-9.72752e+01 ,x3=-3.92091e+00;
  /*
  1  p0           5.47657e-03   1.56364e-04   1.06651e-06   6.13050e-01
   2  p1          -9.72752e+01   9.66288e-01   4.70853e-03   9.54811e-05
   3  p2          -3.92091e+00   4.22552e-02   2.06245e-04  -6.16882e-03
  */
  float y1=6.26072e-03  ,y2=-9.71736e+01 ,y3=-3.79537e+00 ;
  /*
  1  p0           6.26072e-03   1.32746e-04   1.03549e-06  -4.93716e+00
  2  p1          -9.71736e+01   7.80314e-01   3.83301e-03   3.08178e-04
  3  p2          -3.79537e+00   4.34517e-02   2.16579e-04  -7.26439e-04
  */
  float x_cor=0;
  float bias_x = fit_sin(x_rec,x1,x2,x3);
  x_cor=x_rec-bias_x;

  float y_cor=0;
  float bias_y = fit_sin(y_rec,y1,y2,y3);
  y_cor=y_rec-bias_y;

std::pair<float,float> position_corrected;
position_corrected.first = x_cor;
position_corrected.second= y_cor;

return position_corrected;
}

float fit_sin(float x,float x1,float x2,float x3){
  return x1*sin(x2*x + x3);
}
