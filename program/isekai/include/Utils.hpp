#pragma once
#include <random>
#include <iostream>
#include <chrono>
#ifdef _WIN32
  #include <conio.h>
#else 
  #include <termios.h>
  #include <unistd.h>
#endif

namespace utils {
  #ifdef __linux__
    char getch();
  #endif
  double generateNumber(int lowerBound, int higherBound);
}