#include "TRandom.h"
#include "CalorimeterConstants.h"
#include "CalorimeterSimulation.h"

using namespace CalConst;

void simulate(Event * event)
{
    float f = gRandom->Uniform(0.,1.);
    event->clear_cells();
    // simulate the event
    event->seteTrue(50.); // fixed true energy in GeV
    //event->setx_impact(gRandom->Uniform(XYMin,XYMax));
    //event->sety_impact(gRandom->Uniform(XYMin,XYMax));
    event->setx_impact(gRandom->Uniform(-XYSize,0));
    event->sety_impact(gRandom->Uniform(-XYSize,0));
    CalorimeterSimulation sim;
    sim.SimulateShower(event->get_x_impact(),event->get_y_impact(),event->get_eTrue(),f);
    sim.SimulateHadShower(event->get_x_impact(),event->get_y_impact(),event->get_eTrue(),f);
    sim.smear();
    event->set_cells(sim.get_cells());
    event->setQuantaEnergy(sim.get_quanta_energy());
}
