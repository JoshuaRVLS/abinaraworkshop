#pragma once 
#include <string>

class Skill {
private:
  std::string name_;
  double bonusDamage_;

public:
  Skill() {};
  Skill(const std::string& name, double bonusDamage);

  std::string& getName();
  double& getBonusDamage();
};