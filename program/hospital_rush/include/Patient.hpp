#pragma once
#include <iostream> 
#include <vector>

class Patient {
private:
  uint32_t uniqueId_;
  std::string nama_;
  uint32_t tingkatan_;
  uint32_t urutan_;

public:
  Patient() {};
  Patient(const uint32_t& uniqueId, const std::string& nama, const uint32_t tingkat, const uint32_t urutan);

  uint32_t& getUniqueId();
  std::string& getName();
  uint32_t& getTingkatan();
  uint32_t& getUrutan();
};

