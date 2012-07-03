//@+leo-ver=5-thin
//@+node:gcross.20110529102535.2049: * @file identifiable.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP
#define HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110529102535.2051: ** << Includes >>
#include "identity.hpp"

#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110529102535.2052: ** class Identifiable
class Identifiable {
    //@+others
    //@+node:gcross.20110529102535.2053: *3* Destructors
    public:

    virtual ~Identifiable();
    //@+node:gcross.20110529102535.2054: *3* Fields
    public:

    virtual Identity::Ptr const& getIdentity() const = 0;
    hid_t getId() const;
    //@+node:gcross.20110529102535.2055: *3* Operators
    public:

    bool operator==(Identifiable const& other) const;
    //@-others
};
//@-others

}

#endif
//@-leo
