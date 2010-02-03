
#include "linalg3d.h"

namespace TPS {
  bool equal(double a, double b) {
    return a+kEPSILON > b && b+kEPSILON > a;
  }
  #undef EPSILON
}

