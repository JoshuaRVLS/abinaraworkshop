#pragma once 
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <random>
#ifdef _WIN32
  #include <conio.h> // Windows tai
#else 
  #include <termios.h>
  #include <unistd.h>
#endif
#include "Patient.hpp"

class Hospital {
private:
  bool isRunning_ = true;
  std::random_device rd;
  
  std::map<uint32_t, std::vector<Patient>> allPatients;

  uint32_t generateRandomTingkatan_();
  uint32_t generateUniqueId_();

  void generateDummyPatients_(uint32_t count);
  void showMenu_();
  void showPatients_();
  void handlePatient_();
  void addPatient_();
  

public:
  Hospital();

  void start();
};