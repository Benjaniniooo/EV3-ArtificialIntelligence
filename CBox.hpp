#include "SFML/Graphics.hpp"
#include "box2d/box2d.h"

#pragma once

#ifndef CBOX_HPP
#define CBOX_HPP

class CBox{
public:
  CBox();

  sf::Sprite m_spr;                 //sprite for rendering
  sf::Texture m_tex;                //texture to render

  void loadSprite(std::string imageName);

  void start(int boxNumber);

  void rotate(double deg);
  void setPosition(double x, double y);

protected:
  double m_rotation;

  std::array<double, 2> m_position;
};

#endif
