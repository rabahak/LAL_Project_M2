// @(#)root/test:$Name:  $:$Id: Event.cxx,v 1.28 2005/01/19 07:52:45 brun Exp $
// Author: Rene Brun   19/08/96

////////////////////////////////////////////////////////////////////////
//
//                       Event class
//                       =======================
//
//  The Event class is a simple event structure.
////////////////////////////////////////////////////////////////////////


#include "Event.h"
ClassImp(Event)

//______________________________________________________________________________
Event::Event()
{
  filled_cells.clear();
}

//______________________________________________________________________________
Event::~Event()
{
  filled_cells.clear();
}

//______________________________________________________________________________
void Event::build(Int_t ev) {
// set event number
    fiEvent=ev ;

// initialize data member to invalid values
    feTrue=-999.;
    feReco=-999.;
}
