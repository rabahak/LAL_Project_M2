#include "CellAddress.h"
#include "CalCell.h"
#include <vector>
#include <map>
#include "CalorimeterConstants.h"
#include "CalorimeterSimulation.h"
#include <math.h>
#include "TRandom.h"
#include "Utility.h"
#include "assert.h"
using namespace CalConst;

typedef std::map<CellAddress,CalCell>::iterator MapIterator;

CellAddress xyz_to_CellAdress(float,float,float);

CalorimeterSimulation::~CalorimeterSimulation(){
    Cells.erase(Cells.begin(),Cells.end());
}

CalorimeterSimulation::CalorimeterSimulation(){
  //Cells.erase(Cells.begin(),Cells.end());
  int counter=0;
  //for (MapIterator iter = Cells.begin(); iter != Cells.end(); iter++){ counter++;}
  //std::cout<<"counter = "<<counter<<std::endl;
  std::vector<CellAddress> addresses;
  std::vector<CalCell> cells;

  for(int i=0; i < NbCellsInXY; i++)
    for(int j = 0; j < NbCellsInXY; j++)
      for(int k = 0; k < NbLayers; k++)
      {
        CellAddress temp_add(i,j,k);
        addresses.push_back(temp_add);
        CalCell temp_cell(temp_add,0);
        cells.push_back(temp_cell);
      }
      for ( int i = 0; i < NbCellsInXY*NbCellsInXY*NbLayers ; i++) { Cells[addresses[i]] = cells[i]; }



}

// Add the calorimeter cells to the vector of cell caldata
 void CalorimeterSimulation::CalorimeterData(std::vector<CalCell>& caldata) const{

 }

// Simulate a shower of a given energy, starting from the impact point (x,y) of the electron
// at the front end of the calorimeter
void CalorimeterSimulation::SimulateShower(float x_impact, float y_impact, float energy,float f=0){

  int rand_pts = 100000;
  float z_step = ZMax/100;

  float f_max= f_shower(3./50.); // MATLAB: Max(f_shower(x)) x>0
  int nb_counts=0;
  int nb_counts_tot=0;
  std::vector<CellAddress> addresses;
  CellAddress temp_celladdress;

  for(float z=0; z<ZMax; z=z+z_step)
  { nb_counts=0;
    float fz_TRUE=f_shower(z);
    for (int i=0; i<rand_pts; i++)
    {
      float E = gRandom->Uniform(0,f_max) ;
      if(E<=fz_TRUE)
      nb_counts++;
     } // the rand_pts
     nb_counts_tot=nb_counts_tot+nb_counts;
     for(int i=0; i<nb_counts; i++){
       float x=gRandom->Gaus(x_impact,MR);
       float y=gRandom->Gaus(y_impact,MR);
       temp_celladdress = xyz_to_CellAddress(x,y,z);
       addresses.push_back(temp_celladdress);
     }// the nb_counts loop

   } // the z loop

  // Distribution of energy
  quanta_energy = ((1-f)*energy)/nb_counts_tot;
  std::vector<CellAddress>::iterator it;

  for(it = addresses.begin(); it != addresses.end(); it++)
  {
    Cells.find(*it)->second.Add_energy(quanta_energy);
  }

}

std::map<CellAddress,CalCell> CalorimeterSimulation::get_cells(){
  return Cells;
}

float f_shower(float z){
  float b=0.5;
  float a=4;
  float X0=0.01;
  float t = z/X0;
  return pow((b*t),(a-1))*exp(-b*t);

}

float f_had_shower(float z){
  float b=1;
  float a=2;
  float L=0.1;
  float t = z/L;
  return pow((b*t),(a-1))*exp(-b*t);

}

void CalorimeterSimulation::smear(){
  for (MapIterator iter = Cells.begin(); iter != Cells.end(); iter++){
    float my_energy = iter->second.energy();
    if ( my_energy != 0 ) {
      iter->second.Set_energy(gRandom->Gaus(my_energy,sqrt(my_energy)));
    }
  }
}

// setters

void CalorimeterSimulation::set_quanta_energy(float e){
  quanta_energy = e;
}

// getters

float CalorimeterSimulation::get_quanta_energy(){
  return quanta_energy;
}

void CalorimeterSimulation::SimulateHadShower(float x_impact,float y_impact,float energy,float f){

    int rand_pts = 100000;
    float z_step = ZMax/100;

    float f_had_max = f_had_shower((0.02-0.01)/1);

    int nb_counts=0;
    int nb_counts_tot=0;
    std::vector<CellAddress> addresses;
    CellAddress temp_celladdress;
    //====== ELECTROMAGNETIC SHOWER
    for(float z=0; z<ZMax; z=z+z_step)
    { nb_counts=0;
      float fz_TRUE=f_had_shower(z);
      for (int i=0; i<rand_pts; i++)
      {
        float E = gRandom->Uniform(0,f_had_max) ;
        if(E<=fz_TRUE)
        nb_counts++;
       } // the rand_pts
       nb_counts_tot=nb_counts_tot+nb_counts;
       for(int i=0; i<nb_counts; i++){
         float x=gRandom->Gaus(x_impact,MR);
         float y=gRandom->Gaus(y_impact,MR);
         temp_celladdress = xyz_to_CellAddress(x,y,z);
         addresses.push_back(temp_celladdress);
       }// the nb_counts loop

     } // the z loop

     //====== HADRONIC shower


     //======= FILLING
     quanta_energy = ((f)*energy)/nb_counts_tot; // fraction of Electro
     std::vector<CellAddress>::iterator it;

     for(it = addresses.begin(); it != addresses.end(); it++)
     {
       Cells.find(*it)->second.Add_energy(quanta_energy);
     }


    // Distribution of energy


  }
