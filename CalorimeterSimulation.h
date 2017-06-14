#ifndef CalorimeterSimulation_h
#define CalorimeterSimulation_h

#include "CellAddress.h"
#include "CalCell.h"
#include <vector>
#include <map>
#include "TH1F.h"
#include "TCanvas.h"
#include "TF1.h"

float f_shower(float);

class CalorimeterSimulation {
public:

CalorimeterSimulation();

~CalorimeterSimulation();

// Add the calorimeter cells to the vector of cell caldata
 void CalorimeterData(std::vector<CalCell>& caldata) const;

// Simulate a shower of a given energy, starting from the impact point (x,y) of the electron
// at the front end of the calorimeter
void SimulateShower(float x, float y, float energy,float f);
void SimulateHadShower(float x,float y,float energy,float f);
std::map<CellAddress,CalCell> get_cells();

// Print all the cells
friend std::ostream& operator<<(std::ostream& os, const CalorimeterSimulation & cs);

// setters
void set_quanta_energy(float e);

// getters
float get_quanta_energy();

// functions
void smear();
float reconstruct_energy();
std::vector<float> reconstruct_XY();

private:  // to be completed
std::map<CellAddress,CalCell> Cells;
float quanta_energy;

 };

#endif
