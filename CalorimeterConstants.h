#ifndef CalorimeterConstants_h
#define CalorimeterConstants_h

namespace CalConst {
// dimensions, in meters
 static const float ZMin = 0.;
 static const float ZMax = 10.;
 static const float XYMin = -2.;
 static const float XYMax = 2.;

static const int NbCellsInXY = 40;
static const int NbLayers = 10;

// Cell size in x-y
static const float XYSize = ( XYMax - XYMin ) / (double) NbCellsInXY ;
static const float ZSize = ( ZMax - ZMin ) / (double) NbLayers ;

//ADDED
static const float MR= 0.05/2;
static const float MR_had = 0.1/2;
}

#endif
