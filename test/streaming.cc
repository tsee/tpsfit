
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "ThinPlateSpline.h"
#include "linalg3d.h"
#include "cmp.h"

using namespace std;
using namespace TPS;

const unsigned int nTests = 2;
int main (const int /*argc*/, const char** /*argv*/) {
  cout << "1.." << nTests << endl;
  unsigned int testNo = 0;
  cout << "ok " << ++testNo << " - running" << endl;
  
  Vec testV(1., 5.2, 2.3);
  std::ostringstream str;
  str << testV;
  //cerr << str.str() << endl;
  std::istringstream in(str.str());
  Vec testV2;
  in >> testV2;
  if (!(testV == testV2))
    cout << "not ";
  cout << "ok " << ++testNo << " - Vec equal before and after streaming" << endl;

}

