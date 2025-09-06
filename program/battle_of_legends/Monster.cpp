#include "Monster.hpp"
#include "Game.hpp"
#include "Utils.hpp"

void Monster::init_() {
  skills_.emplace_back("Fury Bite", 1.2);
}

Monster::Monster(const std::string &name, double health, double attack, double defense) : Character(name, health, attack, defense) {
  init_();
}
void Monster::uniqueSkill(Character &target, Skill &skill) {
  double damage = utils::generateNumber(1, getAttack() * skill.getBonusDamage()) - (target.getDefense() / 2);

  if (damage < 0) damage = 0;

  printf("%s Menyerang %s dengan serangan skill %s! (Damage %.f, Armor Penetration: 50%)\n", getName().c_str(), target.getName().c_str(),  skill.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());
}

void Monster::normalAttack(Character &target) {
  double damage = utils::generateNumber(1, attack_);

  if (target.isOnDefense()) damage -= (target.getDefense() + target.getDefense() * 2);

  printf("%s Menyerang %s dengan serangan biasa! (Damage %.f)\n", getName().c_str(), target.getName().c_str(), damage);
  target.takeDamage(damage);
  printf("%s HP tersisa: %.1f\n", target.getName().c_str(), target.getHealth());

  target.defenseOff();
}

void Monster::defense() {
  onDefense = true;
}

void Monster::defenseOff() {
  onDefense = false;
}

void Monster::takeTurn(Character& target) {
  bool useSkill = utils::generateNumber(0, 1);
  if (useSkill) {
    uniqueSkill(target, skills_[utils::generateNumber(0, skills_.size()-1)]);
  } else {
    normalAttack(target);
  }
  if (health_ < 0) {
    health_ = 0;
  }
}
