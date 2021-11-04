#pragma once
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

enum inputType { Level, Dim1, Dim2 };

class TextBox
{
private:
  inputType Type;
  sf::Vector2f pos;
  sf::RectangleShape boundary;
  sf::Text textbox;
  std::ostringstream text;
  bool isSelected = false;
  int limit;
  std::string max,min;

  void typeText(int ch);
  void backspace();

public:
  bool isOn();
  bool contains(sf::Vector2i pos);
  sf::Vector2f getSize();
  inputType getType();

  TextBox(inputType Type,sf::Font &font, sf::Vector2f pos, int size, sf::Color color, int lim, std::string min,std::string max,bool sel);

  void adjustTextBox();
  void setPosition(sf::Vector2f pos);
  void selected(bool sel);
  std::string getText();
  void setText(std::string txt);
  void drawTo(sf::RenderWindow &window);
  void typedOn(sf::Event &input);
};
