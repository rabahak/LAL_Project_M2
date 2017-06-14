#include "CalorimeterGeometry.h"
#include "CalorimeterConstants.h"
#include "CellAddress.h"
#include "Utility.h"
using namespace CalConst;
//Return false if the (x,y,z) point is not located in the calorimeter volume
//otherwise return true and fill the CellAddress variables with the
//address of the cell that contains this point
bool CalorimeterGeometry::IsInside(double xyz[3], CellAddress& cellAddress){


  // check if position is inside calorimeter
  if ( (xyz[0] < XYMin) || (xyz[0]> XYMax) ||
      (xyz[1]< XYMin) || (xyz[1] > XYMax)  ||
      (xyz[2]< ZMin) || (xyz[2]> ZMax))
      return 0;
      else
      {
        cellAddress = xyz_to_CellAddress(xyz[0],xyz[1],xyz[2]);

        return 1;
      }

}

// Give the position of the cell center
double CalorimeterGeometry::xCentre( const CellAddress& add ){
  return XYMin+add.ix()*XYSize+XYSize/2;
}

double CalorimeterGeometry::yCentre( const CellAddress& add ){
  return XYMax-add.iy()*XYSize-XYSize/2;
}
