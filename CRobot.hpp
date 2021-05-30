#include <cmath>
#include "box2d/box2d.h"

#include "CSimulation.hpp"

#pragma once

//define PI, temporarily
#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286

#ifndef CROBOT_HPP
#define CROBOT_HPP

class CRobot{
public:
  CRobot();

  sf::Sprite m_spr;                 //sprite for rendering
  sf::Texture m_tex;                //texture to render

  b2BodyDef m_robotBodyDef;
  b2Body* m_robotBody;

  void loadSprite(std::string imageName);

  void start();

  /*-----------------
  sensors and motors
  -----------------*/
  void moveForward(double m);
  void rotate(double deg);

  void setPosition(double x, double y);

  bool m_draw;

protected:
  double m_rotation;

  //position based on the origin; position = origin
  std::array<double, 2> m_position;

  b2BodyDef m_robot;
};

#endif
