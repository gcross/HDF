//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1330: * @file identified.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110520194631.1332: ** << Includes >>
#include "implementation/identified.hpp"

#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1333: ** << Usings >>
using boost::make_shared;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520194631.1334: ** class Identified
//@+node:gcross.20110520194631.1336: *3* Constructors
Identified::Identified() {}

Identified::Identified(Identity::Ptr const& identity)
  : identity(identity)
{}

Identified::Identified(hid_t id, Identity::Closer const& closer)
  : identity(make_shared<Identity>(id,closer))
{}
//@+node:gcross.20110520194631.1338: *3* Fields
Identity::Ptr const& Identified::getIdentity() const { return identity; }
//@-others

}
//@-leo
