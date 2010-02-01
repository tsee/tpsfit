/*
 *  Thin Plate Spline class that was created on the basis of "tpsdemo".
 *  "tpsdemo" comes with the following copyright and license. This
 *  library adopts the same license.
 *
 *  Thin Plate Spline demo/example in C++
 *
 *  - a simple TPS editor, using the Boost uBlas library for large
 *    matrix operations and OpenGL + GLUT for 2D function visualization
 *    (curved plane) and user interface
 *
 *  Copyright (C) 2003,2005 by Jarno Elonen
 *
 *  TPSDemo is Free Software / Open Source with a very permissive
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
 *  TODO:
 *    - implement TPS approximation 3 as suggested in paper
 *      Gianluca Donato and Serge Belongie, 2002: "Approximation
 *      Methods for Thin Plate Spline Mappings and Principal Warps"
 *
 *  -- END tpsdemo copyright and license --
 *
 *  The changes from tpsdemo to this library are
 *    Copyright (C) 2010 by Steffen Mueller (smueller -at- cpan -dot- org)
 *
 */
#include "ThinPlateSpline.h"
#include <boost/numeric/ublas/matrix.hpp>

#include "linalg3d.h"
#include "ludecomposition.h"

#include <vector>
#include <cmath>

using namespace boost::numeric::ublas;
using namespace TPS;

ThinPlateSpline::ThinPlateSpline() :
  fRegularization(0.)
{
}

ThinPlateSpline::ThinPlateSpline(const std::vector<Vec>& controlPoints) :
  fRegularization(0.), fControlPoints(controlPoints)
{
}


static double tps_base_func(double r)
{
  if ( r == 0.0 )
    return 0.0;
  else
    return r*r * log(r);
}


