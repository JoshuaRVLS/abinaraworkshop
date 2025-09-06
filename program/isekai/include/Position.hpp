#pragma once 
#include <vector>

class Position {
  std::vector<int> pos_;

public:
  Position() {};
  Position(std::vector<int>& pos);

  int& getX();
  int& getY();
  std::vector<int>& getVector();
};