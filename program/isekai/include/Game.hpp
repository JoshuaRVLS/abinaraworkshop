#pragma once
#ifdef _WIN32 
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif
#include <Map.hpp>
#include <iostream>

class Game {
  Map map_;


  bool isRunning_ = true;

  void clear_();
  void init_();
  void render_();
  void input_();

public:
  Game();

  void start();
};