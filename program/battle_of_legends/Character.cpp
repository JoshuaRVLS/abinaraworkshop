#include "Character.hpp"

Character::Character(const std::string &name, double health, double attack, double defense): name_(name), health_(health), attack_(attack), defense_(defense) {};

std::string& Character::getName() {
  return this->name_;
}

void Character::takeDamage(double damage) {
  this->health_ -= damage;
  if (this->health_ < 0) {
    this->health_ = 0;
  }
}

double &Character::getHealth() {
  return this->health_;
}

double &Character::getAttack() {
  return this->attack_;
}

double &Character::getDefense() {
  return this->defense_;
}

std::vector<Skill> &Character::getSkills() {
  return this->skills_;
}

bool &Character::isOnDefense() {
  return this->onDefense;
}
