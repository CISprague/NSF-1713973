// Christopher Iliffe Sprague
// cisprague@ac.jaxa.jp

#ifndef dynamics_hpp
#define dynamics_hpp
#include <vector>
#include "spacecraft.hpp"
#include "body.hpp"
#include "vectools.hpp"

struct Dynamics {

  // members
  const std::vector<Body>   bodies;
  const double              nbodies;
  const std::vector<double> F;
  const double              mdot;

  // constructor
  Dynamics (
    const std::vector<double> & control_,
    const Spacecraft          & spacecraft_,
    const std::vector<Body>   & bodies_
  ) :
    bodies(bodies_),
    nbodies(bodies_.size()),
    F(spacecraft_.force(control_)),
    mdot(spacecraft_.mdot(control_)) {
  };

  // destructor
  ~Dynamics (void) {};

  // dynamics
  void operator () (
    const std::vector<double> & x,
    std::vector<double> &dxdt,
    const double & t
  ) {

    // velocity
    dxdt[0] = x[3];
    dxdt[1] = x[4];
    dxdt[2] = x[5];

    // propulsion
    dxdt[3] = F[0]/x[6];
    dxdt[4] = F[1]/x[6];
    dxdt[5] = F[2]/x[6];
    dxdt[6] = mdot;

    // tbc

  };


};

#endif
