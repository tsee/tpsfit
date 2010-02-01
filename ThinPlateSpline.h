#ifndef __ThinPlateSpline_h_
#define __ThinPlateSpline_h_

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>
#include "linalg3d.h"

namespace TPS {
  class ThinPlateSpline {
  public:
    ThinPlateSpline();
    ThinPlateSpline(const std::vector<Vec>& controlPoints);
    ~ThinPlateSpline();

    void SetControlPoints(const std::vector<Vec>& controlPoints) { fControlPoints = controlPoints; }
    const std::vector<Vec>& GetControlPoints() { return fControlPoints; }
    void SetRegularization(const double regularization) { fRegularization = regularization; }
    double GetRegularization() { return fRegularization; }

  private:
    static double tps_base_func(double r);

    double fRegularization;
    std::vector<Vec> fControlPoints;
  };


} // end namespace TPS

#endif
