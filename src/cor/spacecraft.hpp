// Christopher Iliffe Sprague
// cisprague@ac.jaxa.jp
// NSF Award 1713973

#ifndef spacecraft_hpp
#define spacecraft_hpp
#include "linalg.hpp"
#include "constants.hpp"

struct Spacecraft {

  // constants
  const double mass;
  const double thrust;
  const double isp;
  const double veff;

  // constructor
  Spacecraft (
    const double & mass_,
    const double & thrust_,
    const double & isp_
  ) : mass(mass_), thrust(thrust_), isp(isp_), veff(G_0*isp_) {};

  // destructor
  ~Spacecraft (void) {};

  // control vector validity
  void check_control (const std::vector<double> & u) const {
    // dimension of control
    const int dim(u.size());
    // check dimensions
    if (dim != 3) {throw "Control vector must be 3D.";};
  };

  std::vector<double> force (const std::vector<double> & u) const {
    check_control(u);
    return linalg::scaled(u, thrust);
  };

  double fmag (const std::vector<double> & u) const {
    check_control(u);
    return linalg::norm(force(u));
  };

  double mdot (const std::vector<double> & u) const {
    check_control(u);
    return -fmag(u)/veff;
  };

};

#endif
