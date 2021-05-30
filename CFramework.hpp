#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "imgui.h"
#include "imgui-SFML.h"

#pragma once

#ifndef CFRAMEWORK_HPP
#define CFRAMEWORK_HPP

class CFramework{
public:
  CFramework(); //public constructor

  void init(int windowWidth, int windowHeight); //initialize the window

  void reset();   //reset all the buffers as well as imgui
  void display(); //display the buffered information
  void close();   //close the window

  void ImGuiHandler();  //an imgui handler

  void loadBackground(std::string imageName); //render the window background
  void drawBackground();                      //draw the background

  void renderSprite(sf::Sprite &sprite);
  void renderLines(std::vector<sf::Vertex> &points);

  sf::Event getEvent();  //get the current input event

  static CFramework* getInstance(); //singleton function

  bool m_windowIsAlive; //window status
  int m_windowWidth;    //self-explanatory
  int m_windowHeight;   //self-explanatory

protected:
  void handleWindowEvent(sf::Event::EventType windowEvent); //processes the latest event and looks for window events

  sf::RenderWindow window;
  sf::Event event;

  sf::Clock m_deltaClock;

  sf::Texture m_bgtex;
  sf::Sprite m_background;

private:
  static CFramework* Framework;
};

#endif
