#include "CSimulation.hpp"

CSimulation::CSimulation(){}

CSimulation* CSimulation::Simulation = nullptr;  //set the singleton pointer to nullptr

//create a singleton instance, if none exist; return the instance
CSimulation* CSimulation::getInstance(){
  if(Simulation == nullptr){
    Simulation = new CSimulation;
  }

  return Simulation;
}
