#include "Patient.hpp"

Patient::Patient(const uint32_t& uniqueId, const std::string &nama, const uint32_t tingkatan, const uint32_t urutan):  uniqueId_(uniqueId), nama_(nama), tingkatan_(tingkatan), urutan_(urutan){}

uint32_t &Patient::getUniqueId()
{
  // TODO: insert return statement here
  return uniqueId_;
}
std::string &Patient::getName()
{
  // TODO: insert return statement here
  return nama_;
}
uint32_t &Patient::getTingkatan()
{
  // TODO: insert return statement here
  return tingkatan_;
}
uint32_t &Patient::getUrutan() {
  // TODO: insert return statement here
  return urutan_;
}
