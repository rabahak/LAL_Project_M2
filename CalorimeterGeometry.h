#ifndef CalorimeterGeometry_h
#define CalorimeterGeometry_h
//#include "CellAddress.h"

class CellAddress;

class CalorimeterGeometry { public:

//Return false if the (x,y,z) point is not located in the calorimeter volume
//otherwise return true and fill the CellAddress variables with the
//address of the cell that contains this point

static bool IsInside(double xyz[3], CellAddress& cellAddress);

// Give the position of the cell center
static double xCentre( const CellAddress& add ) ;
static double yCentre( const CellAddress& add ) ;

private:

 };

#endif
