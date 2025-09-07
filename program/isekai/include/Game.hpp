#pragma once
#ifdef _WIN32 
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif
#include <Map.hpp>
#include <Monster.hpp>
#include <Player.hpp>
#include <iostream>

class Game {
  Map map_;
  std::vector<Monster> monsters_;
  std::vector<Trap> traps_;
  Player player_;
  int maxMonsters = 3;
  int maxTraps = 3;
  int maxTreasures = 3;
  int totalTurn = 0;
  int currentEnemyIndex;

  std::string status_;


  bool isRunning_ = true;

  void update_();
  void clear_();
  void init_();
  void render_();
  void input_();
  void check_();
  void playerInfo_();
  void fight_();
  void checkWinner_();
  void printFightInfo_();

public:
  Game();
  ~Game() = default;
  

  void start();
};