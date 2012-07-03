//@+leo-ver=5-thin
//@+node:gcross.20110521115623.1470: * @file locatable.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.1472: ** << Includes >>
#include "implementation/file.hpp"
#include "implementation/locatable.hpp"
#include "implementation/location.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.1473: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110528133907.2106: ** class Locatable
//@+node:gcross.20110523113700.1686: *3* Operators
Location Locatable::getLocation() const {
    return Location(getFile(),getIdentity(),Location::dot);
}


Location Locatable::operator/(char const* subname) const {
    return getLocation() / subname;
}

Location Locatable::operator/(std::string const& subname) const {
    return getLocation() / subname;
}
//@-others

}
//@-leo
