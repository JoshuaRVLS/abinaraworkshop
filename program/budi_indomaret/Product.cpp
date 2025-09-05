#include "./Product.hpp"
#include "Product.hpp"

Product::Product(uint32_t productId, const std::string productName, double productPrice): productId_(productId), productName_(productName), productPrice_(productPrice) {}

Product::Product(const std::string productName, uint32_t productPrice): productName_(productName), productPrice_(productPrice) {}

uint32_t &Product::getId() {
  return this->productId_;
}

std::string &Product::getProductName() {
  return this->productName_;
}

double &Product::getProductPrice() {
  return this->productPrice_;
}

