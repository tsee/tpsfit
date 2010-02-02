#ifndef __ThinPlateSpline_h_
#define __ThinPlateSpline_h_

#include <boost/numeric/ublas/matrix.hpp>
#include <vector>
#include <exception>
#include <string>
#include <iostream>
#include "linalg3d.h"

namespace TPS {
  class ThinPlateSpline {
  public:
    ThinPlateSpline(const std::vector<Vec>& controlPoints, const double regularization = 0.);
    ThinPlateSpline(std::istream& input); //< whatever was dumped by DumpAsString
    ThinPlateSpline(); //< for stl containers
    ~ThinPlateSpline() {};

    double Evaluate(const double x, const double z) const;

    const std::vector<Vec>& GetControlPoints() const { return fControlPoints; }
    double GetRegularization() const { return fRegularization; }

    double GetBendingEnergy() const;
    std::string DumpAsString() const;

  private:
    static double tps_base_func(double r);
    void InitializeMatrix();
    std::string DumpMatrix(const boost::numeric::ublas::matrix<double>& matrix) const;
    boost::numeric::ublas::matrix<double> ReadMatrix(std::istream& in) const;

    double fRegularization;
    std::vector<Vec> fControlPoints;

    boost::numeric::ublas::matrix<double> fMtx_l;
    boost::numeric::ublas::matrix<double> fMtx_v;
    boost::numeric::ublas::matrix<double> fMtx_orig_k;
  };


  class TPSException : public std::exception
  {
  public:
    TPSException() {}

    virtual const char* what() const throw() {
      return "Generic ThinPlateSpline exception. Nuke your programmer.";
    }
  };


  class NotEnoughControlPointsException : public TPSException
  {
  public:
    NotEnoughControlPointsException() {}

    virtual const char* what() const throw() {
      return "Not enough control points for evaluating ThinPlateSpline";
    }
  };


  class SingularMatrixException : public TPSException
  {
  public:
    SingularMatrixException() {}

    virtual const char* what() const throw() {
      return "Singular matrix during LU decomposition";
    }
  };

} // end namespace TPS

#endif
