#pragma once 
#include <iostream>

#ifdef _WIN32
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif

#include "Maze.hpp"

class Game {
  bool isRunning_ = true;
  Maze maze;

  void init_();
  void clear_();
  void check_();
  void render_();
  void input_();

public:
  Game();
  ~Game() = default;

  void start();
};