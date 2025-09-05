#include "Skill.hpp"

Skill::Skill(const std::string& name, double bonusDamage): name_(name), bonusDamage_(bonusDamage) {};

std::string& Skill::getName() {
  return this->name_;
}

double& Skill::getBonusDamage() {
  return this->bonusDamage_;
}