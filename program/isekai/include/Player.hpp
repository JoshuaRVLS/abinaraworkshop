#pragma once 
#include "Sprite.hpp"
#include "Character.hpp"
#include "Monster.hpp"
#include "Position.hpp"
#include <vector>

class Player: public Sprite, public Character {

  virtual void init_() override;
  int points_ = 0;
  int life_ = 3;


public:
  Player() {};
  Player(const std::string& value, Position& position, const std::string &name, double health, double attack, double defense);

  void setPosition(Position position);
  void addPoints(int points);
  void minLife(int by);

  int& getPoints();
  int& getLife();

  virtual void uniqueSkill(Character& target, Skill& skill) override;
  virtual void normalAttack(Character& target) override;
  virtual void defense() override;
  virtual void defenseOff() override;
  virtual void takeTurn(Character& target) override;;
};