#pragma once
#include "Hero.hpp"
#include "Monster.hpp"
#include <random> 


class Game {
  Hero* hero;
  Monster* monster;

  uint32_t totalTurn = 1;

  bool playerTurn_ = true;
  bool isRunning_ = true;

  void wait_();
  void update_();
  void fight_();
  void printInfo_();
  void checkWinner_();

public:

  Game();
  ~Game();

  void start();
};