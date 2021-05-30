#include "CRobot.hpp"

CRobot::CRobot(){
  m_draw = false;
  m_rotation = 0;

  m_position[0] = 33.5;
  m_position[1] = 26.5;
}

void CRobot::loadSprite(std::string imageName){
  m_draw = true;

  m_spr.setOrigin(33.5, 26.5);
  m_spr.setRotation(0);
  m_spr.setPosition(0, 0);

  if(!m_tex.loadFromFile(imageName)){
    exit(EXIT_FAILURE);
  }

  m_tex.setSmooth(true);  //smooth out the texture
  m_spr.setTexture(m_tex);  //assign the texture to the sprite, note: the texture must exist until the sprite is destroyed
}

void CRobot::rotate(double deg){
  if(m_draw){
    m_spr.rotate(deg);
  }

  m_rotation += deg;
}

void CRobot::moveForward(double m){
  double c = m * cos((PI / 180 * m_rotation));
  double s = m * sin((PI / 180 * m_rotation));

  if(m_draw){
    m_spr.move(c, s);
  }

  m_position[0] += c;
  m_position[1] += s;
}

void CRobot::start(){
  moveForward(509);
  rotate(90);
  moveForward(565);
  rotate(90);
  moveForward(150);
}

void CRobot::setPosition(double x, double y){
  m_spr.setPosition(x, y);

  m_position[0] = x;
  m_position[1] = y;
}
