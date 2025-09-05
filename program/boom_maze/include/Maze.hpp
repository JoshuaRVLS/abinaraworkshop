#pragma once
#include <vector>
#include "Sprite.hpp"
#include <iostream>
#include <random>

typedef std::vector<std::vector<std::vector<Sprite>>> Map;

class Maze {
   Map map;
   std::random_device rd;
   std::vector<std::string> symbols = {
    "*",
    "*",
    ".",
    ".",
    ".",
    ".",
    ".",
    ".",
    ".",
    ".",
    ".",
    ".",
    "#",
    "#",
    "#",
    "#"
   };
   std::vector<int> playerPosition;
   std::vector<int> endPosition;

public:
  Maze() {};

  void generateMaze();
  void printMap();
  void movePlayer(std::vector<int> coordinates);
  std::string& generateSymbol();
  std::vector<int>& getPlayerPosition();
  int generateRandomPosition();

  Map& getMap();
  
};