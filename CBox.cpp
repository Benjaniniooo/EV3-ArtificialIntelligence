#include "CBox.hpp"

CBox::CBox(){
  m_rotation = 0;

  m_position[0] = 17.5;
  m_position[1] = 17.5;
}

void CBox::loadSprite(std::string imageName){
  m_spr.setOrigin(17.5f, 17.5f);
  m_spr.setRotation(0);
  m_spr.setPosition(0, 0);

  if(!m_tex.loadFromFile(imageName)){
    exit(EXIT_FAILURE);
  }

  m_tex.setSmooth(true);  //smooth out the texture
  m_spr.setTexture(m_tex);  //assign the texture to the sprite, note: the texture must exist until the sprite is destroyed
}

void CBox::rotate(double deg){
  m_spr.rotate(deg);

  m_rotation += deg;
}

void CBox::setPosition(double x, double y){
  m_spr.setPosition(x, y);

  m_position[0] = x;
  m_position[1] = y;
}

void CBox::start(int boxNumber){
  if(boxNumber == 1){
    setPosition(345, 190);
  }else if(boxNumber == 2){
    setPosition(226, 319);
  }else if(boxNumber == 3){
    setPosition(104, 449);
  }
}
