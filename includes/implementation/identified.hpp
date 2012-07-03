//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1319: * @file identified.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_IDENTIFIED_HPP
#define HDFPP_IMPLEMENTATION_IDENTIFIED_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1320: ** << Includes >>
#include "identifiable.hpp"

#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1322: ** class Identified
class Identified: public virtual Identifiable {
    //@+others
    //@+node:gcross.20110520194631.1324: *3* Constructors
    protected:

    Identified(Identity::Ptr const& identity);
    Identified(hid_t id, Identity::Closer const& closer);

    public:

    Identified();
    //@+node:gcross.20110520194631.1325: *3* Fields
    protected:

    Identity::Ptr identity;

    public:

    virtual Identity::Ptr const& getIdentity() const;
    //@-others
};
//@-others

}

#endif
//@-leo
