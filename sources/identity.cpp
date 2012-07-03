//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1303: * @file identity.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110520194631.1305: ** << Includes >>
#include "implementation/identity.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1306: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110520194631.1307: ** class Identity
//@+node:gcross.20110520194631.1309: *3* Constructors/Destructors
Identity::Identity(hid_t id, Closer const& close)
  : id(id)
  , close(close)
{}

Identity::~Identity() { close(id); }
//@+node:gcross.20110520194631.1311: *3* Fields
hid_t Identity::getId() const { return id; }
//@-others

}
//@-leo
