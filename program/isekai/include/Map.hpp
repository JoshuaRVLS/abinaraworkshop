#pragma once 
#include <vector>
#include "Sprite.hpp"
#include <iostream>

typedef std::vector<std::vector<std::vector<Sprite>>> Tiles;

class Map {
  Tiles tiles_;

public:
  Map() {};

  void generateMap();
};