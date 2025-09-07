#pragma once
#include <iostream>
#include <vector>
#include "Skill.hpp"
#include "Sprite.hpp"

class Character {
protected:
  std::string name_;
  double health_, attack_, defense_;
  std::vector<Skill> skills_;
  bool onDefense = false;
  bool isBattle_ = false;
  Character* currentEnemy_;

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
  bool& isBattle();
  Character& getCurrentEnemy();

  void setCurrentEnemy(Character& enemy);
  void setBattle(bool isBattle);
  void setHealth(int health);
  void clearEnemy();

  void takeDamage(double damage);
};