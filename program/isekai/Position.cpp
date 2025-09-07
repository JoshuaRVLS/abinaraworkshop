#include "Position.hpp"

Position::Position(int& x, int& y): pos_({x, y}) {};

int& Position::getX() {
  return pos_[0];
}

int& Position::getY() {
  return pos_[1];
}

std::vector<int>& Position::getVector() {
  return pos_;
}