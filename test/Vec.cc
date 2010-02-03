
#include <string>
#include <iostream>
#include <cmath>

#include "linalg3d.h"
#include "test/cmp.h"

using namespace std;
using namespace TPS;


const unsigned int nTests = 7;
int main (const int /*argc*/, const char** /*argv*/) {
  cout << "1.." << nTests << endl;
  unsigned int testNo = 0;
  cout << "ok " << ++testNo << " - running" << endl;

  Vec testV(1., 5.2, 2.3);
  if (!equal(testV.x, 1.))
    cout << "not ";
  cout << "ok " << ++testNo << " - x okay" << endl;

  if (!equal(testV.y, 5.2))
    cout << "not ";
  cout << "ok " << ++testNo << " - y okay" << endl;
  
  if (!equal(testV.z, 2.3))
    cout << "not ";
  cout << "ok " << ++testNo << " - z okay" << endl;

  if (!equal(testV.norm(), 1.*1.+5.2*5.2+2.3*2.3))
    cout << "not ";
  cout << "ok " << ++testNo << " - norm" << endl;

  if (!equal(testV.len(), sqrt(testV.norm())))
    cout << "not ";
  cout << "ok " << ++testNo << " - len" << endl;

  Vec testV2(1., 5.2, 2.3);

  if (!(testV == testV2))
    cout << "not ";
  cout << "ok " << ++testNo << " - ==" << endl;
}

