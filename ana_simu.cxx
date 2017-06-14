#include "Event.h"
#include "TH3F.h"
#include "TCanvas.h"
#include "CalorimeterConstants.h"
#include "TProfile2D.h"
#include "TString.h"
#include "TH1D.h"
using namespace CalConst;

void ana_simu(const Event* event, TString name)
{
  TCanvas * c1 = new TCanvas("c", "c");
  //TProfile3D* hprof3d = new TProfile3D("3d_profile","3d_histogram",NbCellsInXY,0,NbCellsInXY,NbCellsInXY,0,NbCellsInXY,NbLayers,0,NbLayers);
  TProfile2D* hprof2d = new TProfile2D("2d_profile","2d_histogram",NbCellsInXY,0,NbCellsInXY,NbCellsInXY,0,NbCellsInXY);
  std::vector<CalCell> my_cells;
   my_cells = event->cells();
  typedef std::vector<CalCell>::iterator VectIterator;
  for (VectIterator iter = my_cells.begin(); iter != my_cells.end(); iter++)
  {
    float x=iter->address().ix();
    float y=iter->address().iy();
    float z=iter->address().layer();
    float E=iter->energy();
    hprof2d->Fill(E,z,1);
  }

  hprof2d->Draw("LEGO");
  c1->SaveAs(name+".pdf");
}

/*
void ana_simu(const Event* event, TString name)
{
  TCanvas * c1 = new TCanvas("c", "c");
  //TProfile3D* hprof3d = new TProfile3D("3d_profile","3d_histogram",NbCellsInXY,0,NbCellsInXY,NbCellsInXY,0,NbCellsInXY,NbLayers,0,NbLayers);
  TProfile2D* hprof2d = new TProfile2D("2d_profile","2d_histogram",NbCellsInXY,0,NbCellsInXY,NbCellsInXY,0,NbCellsInXY);
  std::vector<CalCell> my_cells;
   my_cells = event->cells();
  typedef std::vector<CalCell>::iterator VectIterator;
  for (VectIterator iter = my_cells.begin(); iter != my_cells.end(); iter++)
  {
    float x=iter->address().ix();
    float y=iter->address().iy();
    float z=iter->address().layer();
    float E=iter->energy();
    hprof2d->Fill(x,y,E);
  }

  hprof2d->Draw("LEGO");
  c1->SaveAs(name+".pdf");
}*/
