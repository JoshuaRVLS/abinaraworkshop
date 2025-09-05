#pragma once
#include "Character.hpp"
#include "Monster.hpp"


class Hero: public Character {
private:
  virtual void init_() override;
  
public:
  Hero() {};
  Hero(const std::string& name, double health, double attack, double damage);

  virtual void uniqueSkill(Character& target, Skill& skill) override;
  virtual void normalAttack(Character& target) override;
  virtual void defense() override;
  virtual void defenseOff() override;
  virtual void takeTurn(Character& target) override;

};