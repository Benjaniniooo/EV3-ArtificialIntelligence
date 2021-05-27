/*---------------------------
@file: main.cpp
@author: Benjaniniooo
@version: 1.0
@date: 27.05.2021
---------------------------*/

/*---------------------------
[HELP] = help mark, for explanations
[INFO] = info mark for further information
[NOTE] = note mark used by the programmer
[TODO] = todo mark, to indicate unfinished things
---------------------------*/

//[INFO] Include the SFML - Graphics module for Rendering
//[TODO] Remove this line among others like (71-79:0)
#include <SFML/Graphics.hpp>


//[INFO] Include the main files
#include "CFramework.hpp"
#include "CSimulation.hpp"
#include "CRobot.hpp"
#include "CBox.hpp"

//[INFO] Define the window width as well as height for 1024x724 (derived from the background image)
#define WINDOW_WIDTH 1024
#define WINDOW_HEIGHT 724

//[INFO] Those two lines assign a valid address to the singleton pointer
CFramework* Framework = CFramework::getInstance();
CSimulation* Simulation = CSimulation::getInstance();

//[HELP] This is the main function to call when starting the program
int main(int argc, char const *argv[]) {
  Framework->init(WINDOW_WIDTH, WINDOW_HEIGHT);                 //[INFO] Setup the window, with a size of 1024 x 724
  Framework->loadBackground("img/Wettbewerb2.png");             //[INFO] Load the background image to the renderer
                                                                //[NOTE] background image == foil for the robot do drive on

  CRobot Rob = CRobot();                                        //[HELP] Initializers for the robot and a block to move
  CBox Box = CBox();                                            //[TODO] Remove the initializers, only for testing purposes

  Rob.loadSprite("img/EV3.png");                                //[INFO] Load a sprite to the robot, for visualization
  Box.loadSprite("img/crate.png");                              //[INFO] Load a sprite to the box, for visualization

  Rob.start();                                                  //[INFO] Start the robot and set it's position to the standart
  Box.start(std::atof(argv[1]));                                //[INFO] Setup the first boxes m_position
                                                                //[HELP] std::atof(argv[1]) returns the first command promt as a double

  while(Framework->m_windowIsAlive == true){                    //[INFO] This is the main window loop, witch is active as long as the window is opened
                                                                //[TODO] Maybe? Move this to another place
    sf::Event ev = Framework->getEvent();                       //[INFO] This stores the current event for a later use, eg. get the pressed key
    Framework->ImGuiHandler();                                  //[INFO] This runs the ImGui handler

    //[TODO] Remove the following IF - ELSE statement
    //[INFO] This statement is used for testing only
    if(ev.type == sf::Event::KeyPressed){
      if(ev.key.code == sf::Keyboard::A){
        Rob.rotate(1);
        Box.rotate(1);
      }
      else if(ev.key.code == sf::Keyboard::D){
        Rob.rotate(-1);
        Box.rotate(-1);
      }
      else if(ev.key.code == sf::Keyboard::W){
        Rob.moveForward(1);
      }
      else if(ev.key.code == sf::Keyboard::S){
        Rob.moveForward(-1);
      }
    }

    Framework->reset();                                         //[INFO] Reset the Framework for a draw

    Framework->drawBackground();                                //[INFO] Draw the background initilized at (32:0)

    Framework->renderSprite(Box.m_spr);                         //[INFO] Rendering the box
    Framework->renderSprite(Rob.m_spr);                         //[INFO] Call this to render the EV3 model
                                                                //[TODO] Move this to another place

    Framework->display();                                       //[INFO] display the buffered data


  }

  Framework->close();                                           //[INFO] shut down the window when the window got closed

  return 0;
}
