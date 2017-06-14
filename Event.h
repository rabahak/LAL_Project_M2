#ifndef ROOT_Event
#define ROOT_Event

//////////////////////////////////////////////////////////////////////////
//                                                                      //
// Event                                                                //
//                                                                      //
// Description of the event                                             //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "CalorimeterSimulation.h"
#include "TH3F.h"
#include <cmath>
#include "TRandom.h"
class TDirectory;

class Event : public TObject {

private:
    int       fiEvent ;           // event number
    float     feTrue ; // true energy
    float     feReco ; // reconstructed energy
    float     feRecoBias ; // bias of reconstructed energy
    float     x_impact;
    float     y_impact;
    float     fxReco;
    float     fyReco;
    float     fxReco_corr;
    float     fyReco_corr;
    float     fyReco_err;
    float     fxReco_err;
    std::vector<CalCell> filled_cells;//!transient
    TH3F*     hist;//! transient
    float     quanta_energy;
public:
    Event();  // constructor
    virtual ~Event(); // destructor
    void clear_cells(){filled_cells.clear();}
    void	build(int ev); // initialize

  // setters
   void	seteTrue(float e) { feTrue = e ; }
   //void	seteReco(float e) { feReco = e ; }
   void seteReco(float e) {feReco = e ;}
   void seteRecoBias(float bias) { feRecoBias=feReco+bias ;}
   void setx_impact(float x){x_impact=x;}
   void sety_impact(float y){y_impact=y;}
   void setfxReco(float x){fxReco=x;}
   void setfyReco(float y){fyReco=y;}
   void setfxReco_corr(float x){fxReco_corr=x;}
   void setfyReco_corr(float y){fyReco_corr=y;}
   void setfxReco_err(float xerr){fxReco_err=xerr;}
   void setfyReco_err(float yerr){fyReco_err=yerr;}
   void set_cells(std::map<CellAddress,CalCell> cells){
     typedef std::map<CellAddress,CalCell>::iterator MapIterator;
     for (MapIterator iter = cells.begin(); iter != cells.end(); ++iter){
       filled_cells.push_back(iter->second);
   }
 }
   void set_hist(TH3F* h){hist=h;}
   void setQuantaEnergy(float e){quanta_energy = e;}


// getters
   float get_eTrue () const { return feTrue ; }
   float get_eReco () const { return feReco ; }
   float get_x_impact() const { return x_impact; }
   float get_y_impact() const { return y_impact; }
   std::vector<CalCell> cells() const {return filled_cells;}
   TH3F* get_hist() const{return hist;}
   float get_fxReco(){return fxReco;}
   float get_fyReco(){return fyReco;}
   float get_fxReco_corr(){return fxReco_corr;}
   float get_fyReco_corr(){return fyReco_corr;}
   float get_fxReco_err(){return fxReco_err;}
   float get_fyReco_err(){return fyReco_err;}
   float getQuantaEnergy(){return quanta_energy;}

// technical (ignore)
   ClassDef(Event,1)  //Event structure
};



#endif
