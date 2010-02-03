
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "ThinPlateSpline.h"
#include "linalg3d.h"
#include "cmp.h"

using namespace std;
using namespace TPS;

void validateTPS(ThinPlateSpline& tps, unsigned int& testNo, vector<Vec>& ctrl) {
  ostringstream str;
  str << tps;
  //cerr << str.str();
  istringstream in(str.str());

  int n;
  double v;
  in >> v;
  assertStream(in, testNo);
  ASSERT_EQUAL(v, 2.5, "regularization is 2.5");

  // check n ctrl points
  in >> n;
  assertStream(in, testNo);
  ASSERT((unsigned int)n == ctrl.size(), "no. control points okay");

  // check ctrl points themselves
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

  // check first matrix size
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 7, "size-x of first matrix");
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 7, "size-y of first matrix");

  // check first matrix itself
  double matrix1[7][7] = {
    { 76.1282, 48.8258, 34.6775, 153.96, 1, 6, 7, },
    { 0.151231, 27.2935, 43.5815, 0.798838, 0.848769, 3.09262, 0.941385, },
    { 0.0528529, 0.787796, 117.794, 25.9109, 0.27849, -2.75347, -0.11159, },
    { 0.455514, -0.393057, 0.657608, -82.8326, 0.694963, 1.29319, 0.254802, },
    { 0.0131357, 0.123056, 0.00154092, 0.026084, -0.136139, -0.488869, -0.214268, },
    { 0.0394072, 0.00278134, 0.0467957, 0.0758382, 0.789671, 0.171778, -0.123369, },
    { 0.0131357, 0.01314, -0.000239197, 0.0123946, 0.241193, -0.106106, -0.0689151, },
  };
  for (unsigned int ix = 0; ix < 7; ++ix) {
    for (unsigned int iy = 0; iy < 7; ++iy) {
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, matrix1[ix][iy], "matrix1 elem");

    }
  }

  // check second matrix size
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 7, "size-x of second matrix");
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 1, "size-y of second matrix");

  // check second matrix itself
  double matrix2[7][1] = { {-0.0198328}, {-0.00661092}, {0.00771274},
                           {0.0187309}, {-0.25076}, {0.393784}, {0.652772} };
  for (unsigned int ix = 0; ix < 7; ++ix) {
    for (unsigned int iy = 0; iy < 1; ++iy) {
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, matrix2[ix][iy], "matrix2 elem");

    }
  }

  // check third matrix size
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 4, "size-x of third matrix");
  in >> n;
  assertStream(in, testNo);
  ASSERT(n == 4, "size-y of third matrix");

  // check third matrix itself
  double matrix3[4][4] = {
    {34.6775, 11.5129, 76.1282, 4.02359},
    {11.5129, 34.6775, 48.8258, 24.0823},
    {76.1282, 48.8258, 34.6775, 153.96},
    {4.02359, 24.0823, 153.96, 34.6775},
  };
  for (unsigned int ix = 0; ix < 4; ++ix) {
    for (unsigned int iy = 0; iy < 4; ++iy) {
      in >> v;
      assertStream(in, testNo);
      ASSERT_EQUAL(v, matrix3[ix][iy], "matrix3 elem");

    }
  }
}

const unsigned int nTests = 370;
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
    validateTPS(tps, testNo, ctrl);
    ostringstream out;
    out << tps;
    istringstream in(out.str());
    ThinPlateSpline tps2(in);
    validateTPS(tps2, testNo, ctrl);
  } // end scope

}

