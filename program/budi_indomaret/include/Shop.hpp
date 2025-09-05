#pragma once 
#include <iostream>
#include <vector>
#include <Product.hpp>

class Shop {
private:
  bool isRunning_ = true;
  std::vector<Product> products_;


  void clear_();
  void wait_();
  void showMenu_();
  void addProduct_();
  void showProducts_();
  void showTotalProducts_();
  void buyProduct_(const int& productIndex);


public:
  Shop() {};

  void start();
};