#pragma once 
#include <iostream>
#include <vector>

class Product {
private:
  uint32_t productId_;
  std::string productName_;
  double productPrice_;

public:
  Product() {};
  Product(uint32_t productId, const std::string productName, double productPrice);
  Product(const std::string productName, uint32_t productPrice);

  uint32_t& getId();
  std::string& getProductName();
  double& getProductPrice();
};