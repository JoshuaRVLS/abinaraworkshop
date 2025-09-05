#pragma once
#include <iostream>
#include <vector>
#include "Skill.hpp"

class Character {
protected:
  std::string name_;
  double health_, attack_, defense_;
  std::vector<Skill> skills_;
  bool onDefense = false;

  virtual void init_() = 0;

public:

  Character() {};
  Character(const std::string& name, double health, double attack, double defense);

  virtual void uniqueSkill(Character& target, Skill& skill) = 0;
  virtual void normalAttack(Character& target) = 0;
  virtual void defense() = 0;
  virtual void defenseOff() = 0;
  virtual void takeTurn(Character& target) = 0;

  std::string& getName();
  double& getHealth();
  double& getAttack();
  double& getDefense();
  std::vector<Skill>& getSkills();
  bool& isOnDefense();

  void takeDamage(double damage);


};