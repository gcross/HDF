//@+leo-ver=5-thin
//@+node:gcross.20110521115623.1460: * @file locatable.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_LOCATABLE_HPP
#define HDFPP_IMPLEMENTATION_LOCATABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.1461: ** << Includes >>
#include "identifiable.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.1463: ** class Locatable
//@+<< Forward declarations >>
//@+node:gcross.20110528133907.2088: *3* << Forward declarations >>
class File;
class Location;
//@-<< Forward declarations >>

class Locatable: public virtual Identifiable {
    //@+others
    //@+node:gcross.20110528133907.2087: *3* Fields
    public:

    virtual File const& getFile() const = 0;
    //@+node:gcross.20110523113700.1682: *3* Operators
    public:
        Location getLocation() const;
        Location operator/(char const* subname) const;
        Location operator/(std::string const& subname) const;
    //@-others
};
//@-others

}

#endif
//@-leo
