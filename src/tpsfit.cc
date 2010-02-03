/*
 *  Thin Plate Spline calculator
 *
 *    Copyright (C) 2010 by Steffen Mueller smueller -at- cpan -dot- org
 *
 *  This program is Free Software / Open Source with a very permissive
 *  license:
 *
 *  Permission to use, copy, modify, distribute and sell this software
 *  and its documentation for any purpose is hereby granted without fee,
 *  provided that the above copyright notice appear in all copies and
 *  that both that copyright notice and this permission notice appear
 *  in supporting documentation.  The authors make no representations
 *  about the suitability of this software for any purpose.
 *  It is provided "as is" without express or implied warranty.
 *
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <limits>

#include "linalg3d.h"
#include "ThinPlateSpline.h"

using namespace TPS;
using namespace std;

void usage() {
  cout << "Usage: tpsfit <textfile> <regularization>\n\n"
       << "Calculates the thin plate spline matrices and dumps the data to STDOUT\n"
       << "The output can be read using the ThinPlateSpline class in another program.\n\n"
       << "<textfile> contains an arbitrary number (>3) of whitespace\n"
       << "separated sets of x/y/z values, each set specifying the coordinates\n"
       << "of a control point for the thin plate spline.\n"
       << "<regularization> is a floating point value indicating the strength\n"
       << "of the regularization. Defaults to 0.\n"
       << endl;
}

int main(const int argc, const char** argv) {
  if (argc < 2 || argc > 3) {
    usage();
    exit(1);
  }
  cout << scientific << std::setprecision(numeric_limits<double>::digits10 + 1);

  double regularization = 0.;
  if (argc == 3)
    regularization = atof(argv[2]);

  ifstream in;
  in.open(argv[1]);
  vector<Vec> control_points;
  while (in.good()) {
    Vec cp;
    try {
      in >> cp;
    }
    catch (EndOfFileException e) {
      break;
    }

    control_points.push_back(cp);
  }

  ThinPlateSpline tps(control_points, regularization);

  cout << tps <<endl;
  return 0;
}

