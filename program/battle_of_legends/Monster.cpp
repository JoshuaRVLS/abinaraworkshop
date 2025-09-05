#include "Monster.hpp"
#include "Game.hpp"
#include "Utils.hpp"

void Monster::init_() {
  this->skills_.emplace_back("Fury Bite", 1.2);
}

Monster::Monster(const std::string &name, double health, double attack, double defense) : Character(name, health, attack, defense) {
  this->init_();
}
void Monster::uniqueSkill(Character &target, Skill &skill) {
  double damage = utils::generateNumber(1, this->getAttack() * skill.getBonusDamage()) - (target.getDefense() / 2);

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan skill %s! (Damage %.f, Armor Penetration: 50%)\n", this->getName().c_str(), target.getName().c_str(),  skill.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Monster::normalAttack(Character &target) {
  double damage = utils::generateNumber(1, this->attack_);

  if (target.isOnDefense()) damage -= (target.getDefense() + target.getDefense() * 2);

  printf("%s Menyerang %s dengan serangan biasa! (Damage %.f)\n", this->getName().c_str(), target.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());

  target.defenseOff();
}

void Monster::defense() {
  this->onDefense = true;
}

void Monster::defenseOff() {
  this->onDefense = false;
}

void Monster::takeTurn(Character& target) {
  bool useSkill = utils::generateNumber(0, 1);
  if (useSkill) {
    this->uniqueSkill(target, this->skills_[utils::generateNumber(0, this->skills_.size()-1)]);
  } else {
    this->normalAttack(target);
  }
  if (this->health_ < 0) {
    this->health_ = 0;
  }
}
