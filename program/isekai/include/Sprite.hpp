#pragma once 
#include "Position.hpp"

class Sprite {

  int layer_;
  Position position_;
  

public:
  Sprite();

  Position& getPosition();
};