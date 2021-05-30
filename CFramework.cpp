#include "CFramework.hpp" //include the header file

//initialze the class to standard values
CFramework::CFramework(){
  m_windowIsAlive = false;

  m_windowWidth = 0;
  m_windowHeight = 0;
}

CFramework* CFramework::Framework = nullptr;  //set the singleton pointer to nullptr

//create a singleton instance, if none exist; return the instance
CFramework* CFramework::getInstance(){
  if(Framework == nullptr){
    Framework = new CFramework;
  }

  return Framework;
}


//initilize the framework and window
void CFramework::init(int windowWidth, int windowHeight){
  window.create(sf::VideoMode(windowWidth, windowHeight), "EV3 - Emulator");

  m_windowIsAlive = true;

  ImGui::SFML::Init(window);

  m_windowWidth = windowWidth;  //store the width for a later use
  m_windowHeight = windowHeight;  //store the height for a later use
}

//close the window
void CFramework::close(){
  ImGui::SFML::Shutdown();

  window.close();
}

//display the buffered image data
void CFramework::display(){
  ImGui::SFML::Render(window);

  window.display();
}

//clears the window
void CFramework::reset(){
  window.clear();
}

void CFramework::handleWindowEvent(sf::Event::EventType windowEvent){
  if(windowEvent == sf::Event::Closed){
    m_windowIsAlive = false;
  }
}

sf::Event CFramework::getEvent(){
  window.pollEvent(event);

  handleWindowEvent(event.type);
  ImGui::SFML::ProcessEvent(event);

  return event;
}

void CFramework::ImGuiHandler(){
  ImGui::SFML::Update(window, m_deltaClock.restart());

  ImGui::Begin("Emulator - Menu");
  ImGui::End();
}

void CFramework::loadBackground(std::string imageName){
  if(!m_bgtex.loadFromFile(imageName)){
    exit(EXIT_FAILURE);
  }

  m_background = sf::Sprite(m_bgtex);
}

void CFramework::drawBackground(){
  window.draw(m_background);
}

void CFramework::renderSprite(sf::Sprite &sprite){
  window.draw(sprite);
}

void CFramework::renderLines(std::vector<sf::Vertex> &points){
  window.draw(points.data(), points.size(), sf::LineStrip);
}
