#pragma once 
#include "Position.hpp"
#include <iostream>

class Sprite {
protected:
  int layer_;
  Position position_;
  std::string value_;

public:
  Sprite() {};

  Sprite(const std::string& value, Position position);

  Position& getPosition();
  std::string& getValue();
};