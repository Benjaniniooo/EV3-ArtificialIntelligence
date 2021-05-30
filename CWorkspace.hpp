#include "box2d/box2d.h"

#include "CBox.hpp"
#include "CRobot.hpp"

#pragma once

#ifndef CWORKSPACE_HPP
#define CWORKSPACE_HPP

class CWorkspace{
public:
  CWorkspace();

  friend CBox;
  friend CRobot;

protected:
  b2Vec2 m_gravity{0.0f, 0.0f};
  b2World m_world{m_gravity};


private:
};

#endif
