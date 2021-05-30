#include <SFML/Graphics.hpp>
#include <vector>

#pragma once

#ifndef CSIMULATION_HPP
#define CSIMULATION_HPP

class CSimulation{
public:
  CSimulation();

  static CSimulation* getInstance(); //singleton function

private:
  static CSimulation* Simulation;
};

#endif
