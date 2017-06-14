#ifndef CellAddress_h
#define CellAddress_h

#include <iostream>

// ------------------------------------------------------------------------
// CellAddress
// is a way to identify a calorimter cell using its positions along
//  the x, y and z axis
// ------------------------------------------------------------------------

class CellAddress {
public:
// default constructor = gives you an invalid address
CellAddress();

// full constructor
CellAddress(int ix, int iy, int layer);

// valid address ?
bool IsValid() const;

// x-axis index
int ix() const;

// y-axis index
int iy() const;

// z-axis index (depth)
int layer() const;

// this defines comparator between two CellAddress . This is necessary for some
// container types of the standard template library (std)
bool operator<(const CellAddress &x) const
{
if (x.m_iy == this ->m_iy && x.m_ix == this->m_ix) return (this->m_layer < x.m_layer);
if (x.m_ix == this->m_ix) return (this->m_iy < x.m_iy);
return (this->m_ix < x.m_ix);
}

bool operator>(const CellAddress &x) const
{
 if (x.m_iy == this ->m_iy && x.m_ix == this->m_ix) return (this->m_layer > x.m_layer);
 if (x.m_ix == this->m_ix) return (this->m_iy > x.m_iy);
return (this->m_ix > x.m_ix);
}

// display cell address content
friend std::ostream& operator<<(std::ostream& os, const CellAddress &y)
 {
 os<<"("<<y.ix()<<", "<<y.iy()<<", "<<y.layer()<<")";
 return os;
}

private:
 int m_ix, m_iy, m_layer;

};

#endif
