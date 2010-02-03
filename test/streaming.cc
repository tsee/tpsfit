
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "ThinPlateSpline.h"
#include "linalg3d.h"
#include "cmp.h"

using namespace std;
using namespace TPS;


const unsigned int nTests = 30;
int main (const int /*argc*/, const char** /*argv*/) {
  cout << "1.." << nTests << endl;
  unsigned int testNo = 0;
  cout << "ok " << ++testNo << " - running" << endl;
  
  { // scope
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

  { // scope
    vector<Vec> ctrl;
    ctrl.push_back(Vec(1., 2., 3.));
    ctrl.push_back(Vec(4., 3., 2.));
    ctrl.push_back(Vec(6., 8., 7.));
    ctrl.push_back(Vec(0., 2., 1.));

    ThinPlateSpline tps(ctrl, 2.5);
    ostringstream str;
    str << tps;
    cerr << str.str();
    istringstream in(str.str());

    int n;
    double v;
    in >> v;
    assertStream(in, testNo);
    ASSERT_EQUAL(v, 2.5, "regularization is 2.5");

    in >> n;
    assertStream(in, testNo);
    ASSERT_EQUAL((unsigned int)n, ctrl.size(), "no. control points okay");
    
    for (unsigned int iVec = 0; iVec < ctrl.size(); ++iVec) {
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, ctrl[iVec].x, "component of ctrl point okay");
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, ctrl[iVec].y, "component of ctrl point okay");
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, ctrl[iVec].z, "component of ctrl point okay");
    }
    
  }
  
}

