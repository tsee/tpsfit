
#include "linalg3d.h"
#include <iostream>

#define ASSERT(cond, desc) if (!(cond)) \
    std::cout << "not "; \
  std::cout << "ok " << ++testNo << " - " << desc << std::endl;


namespace TPS {
  bool equal(double a, double b) {
    return a+kEPSILON > b && b+kEPSILON > a;
  }
}

void assertStream(std::istream& str, unsigned int& testNo) {
  if (!str.good())
    std::cout << "not ";
  std::cout << "ok " << ++testNo << " - input stream still good" << std::endl;
}

