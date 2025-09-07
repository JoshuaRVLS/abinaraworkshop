#pragma once 
#include "Sprite.hpp"
#include "Skill.hpp"
#include "Character.hpp"
#include "Position.hpp"

class Monster: public Sprite, public Character {

  virtual void init_() override;

public:
  Monster() {};
  Monster(const std::string& value, Position& position, const std::string &name, double health, double attack, double defense);

  virtual void uniqueSkill(Character& target, Skill& skill) override;
  virtual void normalAttack(Character& target) override;
  virtual void defense() override;
  virtual void defenseOff() override;
  virtual void takeTurn(Character& target) override;

};