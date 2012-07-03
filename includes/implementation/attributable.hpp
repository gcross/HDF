//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2828: * @file attributable.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_ATTRIBUTABLE_HPP
#define HDFPP_IMPLEMENTATION_ATTRIBUTABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2829: ** << Includes >>
#include "locatable.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2831: ** class Attributable
//@+<< Forward declarations >>
//@+node:gcross.20110528133907.2112: *3* << Forward declarations >>
class Attribute;
//@-<< Forward declarations >>

class Attributable: public virtual Locatable {
    //@+others
    //@+node:gcross.20110521115623.2832: *3* Operators
    public:

    Attribute operator[] (char const* name) const;
    //@-others
};
//@-others

}

#endif
//@-leo
