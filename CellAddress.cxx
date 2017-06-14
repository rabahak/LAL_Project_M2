

////////////////////////////////////////////////////////////////////////
//
//                       Event class
//                       =======================
//
//  The Event class is a simple event structure.
////////////////////////////////////////////////////////////////////////

#include "CellAddress.h"
#include "CalorimeterConstants.h"
#include "Utility.h"
#include <iostream>

using namespace CalConst;


// Convert X and Y in num of Cells
int X_to_cell(double x){
  double xCell = x/CalConst::XYSize;
  xCell = int(xCell);
  return xCell;
}

// default constructor = gives you an invalid address
CellAddress::CellAddress()
{
}

// full constructor
CellAddress::CellAddress(int ix, int iy, int layer)
{
  m_ix = ix;
  m_iy = iy;
  m_layer = layer;
}

// valid address ?
bool CellAddress::IsValid() const{
CellAddress my_address = xyz_to_CellAddress(XYMax,0,0); // used only to convert m to indices
int iXYMax = my_address.ix();

  if ( (m_ix < 0) || (m_ix > iXYMax) ||
      (m_iy < 0) || (m_iy > iXYMax)  ||
      (m_layer < 0) || (m_layer > (NbLayers - 1)))
      //m_ix == 0 || &m_iy == NULL || &m_layer == NULL)
      {
        std::cout<<"Error: address of cell is not valid."<<std::endl;
        return 0;
      }
  else return 1;
}

// x-axis index
int CellAddress::ix() const{
  return m_ix;
}

// y-axis index
int CellAddress::iy() const{
  return m_iy;
}

// z-axis index (depth)
int CellAddress::layer() const{
  return m_layer;
}

//private:
// int m_ix, m_iy, m_layer;
