#pragma once 
#include <vector>

class Position {
  std::vector<int> pos_;

public:
  Position() {};
  Position(int& x, int& y);

  int& getX();
  int& getY();
  std::vector<int>& getVector();
};