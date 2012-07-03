//@+leo-ver=5-thin
//@+node:gcross.20110529102535.2064: * @file identifiable.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110529102535.2066: ** << Includes >>
#include "implementation/identifiable.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110529102535.2067: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110529102535.2068: ** class Identifiable
//@+node:gcross.20110529102535.2069: *3* Destructors
Identifiable::~Identifiable() {}
//@+node:gcross.20110529102535.2070: *3* Fields
hid_t Identifiable::getId() const { return getIdentity()->getId(); }
//@+node:gcross.20110529102535.2071: *3* Operators
bool Identifiable::operator==(Identifiable const& other) const {
    return getId() == other.getId();
}
//@-others

}
//@-leo
