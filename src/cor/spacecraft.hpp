#ifndef spacecraft_hpp
#define spacecraft_hpp
#include "vectools.hpp"

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
  ) : mass(mass_), thrust(thrust_), isp(isp_), veff(9.80665*isp_) {};

  // destructor
  ~Spacecraft (void) {};

  std::vector<double> force (const std::vector<double> & u) const {
    return vectools::scaled(u, thrust);
  };

  double fmag (const std::vector<double> & u) const {
    return vectools::norm(force(u));
  };

  double mdot (const std::vector<double> & u) const {
    return -fmag(u)/veff;
  };

};

#endif
