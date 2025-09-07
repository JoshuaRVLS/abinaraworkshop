#include "Character.hpp"

Character::Character(const std::string &name, double health, double attack, double defense): name_(name), health_(health), attack_(attack), defense_(defense) {};

std::string& Character::getName() {
  return name_;
}

void Character::takeDamage(double damage) {
  health_ -= damage;
  if (health_ < 0) {
    health_ = 0;
  }
}

double &Character::getHealth() {
  return health_;
}

bool &Character::isBattle() {
  return isBattle_;
}

Character &Character::getCurrentEnemy() {
  return *currentEnemy_;
}

void Character::setCurrentEnemy(Character &enemy) {
  currentEnemy_ = &enemy;
}

void Character::setBattle(bool isBattle)
{
  isBattle_ = isBattle;
}

void Character::setHealth(int health) {
  health_ = health;
}

void Character::clearEnemy() {
  currentEnemy_ = nullptr;
}

double &Character::getAttack() {
  return attack_;
}

double &Character::getDefense() {
  return defense_;
}

std::vector<Skill> &Character::getSkills() {
  return skills_;
}

bool &Character::isOnDefense() {
  return onDefense;
}
