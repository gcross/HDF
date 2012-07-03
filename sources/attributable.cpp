//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2838: * @file attributable.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.2840: ** << Includes >>
#include "attributable.hpp"

#include <string>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2841: ** << Usings >>
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2846: ** class Attributable
//@+node:gcross.20110521115623.2848: *3* Operators
Attribute Attributable::operator[] (char const* name) const {
    return Attribute(*this,name);
}
//@-others

}
//@-leo
