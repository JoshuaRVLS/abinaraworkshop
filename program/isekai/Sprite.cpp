#include "Sprite.hpp"

Sprite::Sprite(const std::string& value, Position position): value_(value), position_(position) {};

Position& Sprite::getPosition() {
  return position_;
}

std::string& Sprite::getValue() {
  return value_;
}
