#include "Sprite.hpp"
#include <iostream>

Sprite::Sprite(const std::string& value, std::vector<int> initialPosition): value_(value), currentPosition(initialPosition) {};

std::string &Sprite::getValue() {
  return this->value_;
}

void Sprite::setHidden(bool hidden) {
  this->hidden_ = hidden;
}

bool Sprite::isHidden() {
  return this->hidden_;
}

void Sprite::setPosition(std::vector<int> newPosition) {
  currentPosition = newPosition;
}
