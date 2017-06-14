#ifndef CalCell_h
#define CalCell_h

#include "CellAddress.h"

class CalCell {

public:

// default constructor needed of containers of the standard template library
CalCell();

// full constructor
CalCell(const CellAddress& ca, float energy);

// energy
float energy() const;

// address
CellAddress address() const;

//Set energy
void Set_energy(float);
void Add_energy(float);

// "print"
friend std::ostream& operator<<(std::ostream& os, const CalCell &y) { os<<"["<<y.address()<<","<<y.energy()<<"]"; return os; }

private:
float m_energy;
CellAddress m_address;

};

#endif
