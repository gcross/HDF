//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1350: * @file contained.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_CONTAINED_HPP
#define HDFPP_IMPLEMENTATION_CONTAINED_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1351: ** << Includes >>
#include "identified.hpp"
#include "location.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1353: ** class Contained
class Contained: public Identified, public virtual Locatable {
    //@+others
    //@+node:gcross.20110520194631.1357: *3* Constructors
    protected:

    Contained();
    Contained(File const& file, hid_t id, Identity::Closer const& closer);
    Contained(File const& file, Identity::Ptr const& self_identity);
    //@+node:gcross.20110520211700.1486: *3* Fields
    protected:

    File file;

    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //@-others
};
//@-others

}

#endif
//@-leo
