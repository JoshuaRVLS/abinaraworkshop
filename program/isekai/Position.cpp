#include "Position.hpp"

Position::Position(std::vector<int>& pos): pos_(pos) {};

int& Position::getX() {
  return pos_[0];
}

int& Position::getY() {
  return pos_[1];
}

std::vector<int>& Position::getVector() {
  return pos_;
}