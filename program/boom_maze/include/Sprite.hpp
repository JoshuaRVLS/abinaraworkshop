#pragma once
#include <string>
#include <vector>

class Sprite {
  std::string value_;
  bool hidden_ = true;
  std::vector<int> currentPosition;
  

public:
  Sprite() {};
  Sprite(const std::string& value, std::vector<int> initialPosition);


  void setPosition(std::vector<int> newPosition);
  std::string& getValue();
  void setHidden(bool hidden);
  bool isHidden();

};