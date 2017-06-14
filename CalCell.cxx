#include "CalCell.h"

// default constructor needed of containers of the standard template library
CalCell::CalCell()
{
}

// full constructor
CalCell::CalCell(const CellAddress& ca, float energy){
m_energy = energy;
m_address = ca;
}
// energy
float CalCell::energy() const{
return m_energy;
}

// address
CellAddress CalCell::address() const{
return m_address;
}

void CalCell::Set_energy(float new_energy){
  m_energy=new_energy;
}

void CalCell::Add_energy(float added_energy){
  m_energy+=added_energy;
}

/*
private:
float m_energy;
CellAddress m_address;

};

#endif
*/
