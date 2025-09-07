#pragma once 
#include "Sprite.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "Position.hpp"
#include "Player.hpp"
#include <vector>

class Trap: public Sprite {

  int damage_;

public:
  Trap() {};
  Trap(const std::string& value, Position& position, int damage);

  void setPosition(Position position);
  void giveDamage(Player& player);
};