//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1449: * @file contained.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110520211700.1451: ** << Includes >>
#include "contained.hpp"

#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1452: ** << Usings >>
using boost::make_shared;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1456: ** class Contained
//@+node:gcross.20110520211700.1457: *3* Constructors
Contained::Contained() {}

Contained::Contained(File const& file, hid_t id, Identity::Closer const& closer)
  : Identified(make_shared<Identity>(id,closer))
  , file(file)
{}

Contained::Contained(File const& file, Identity::Ptr const& identity)
  : Identified(identity)
  , file(file)
{}
//@+node:gcross.20110520211700.1489: *3* Fields
File const& Contained::getFile() const { return file; }
Identity::Ptr const& Contained::getIdentity() const { return identity; }
//@-others

}
//@-leo
