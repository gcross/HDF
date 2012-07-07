#ifndef HDFPP_IMPLEMENTATION_LOCATABLE_HPP
#define HDFPP_IMPLEMENTATION_LOCATABLE_HPP

// Includes {{{
#include "identifiable.hpp"
// Includes }}}

namespace HDF {

// class Locatable {{{

// Forward declarations {{{
class File;
class Location;
// Forward declarations }}}

class Locatable: public virtual Identifiable {
    // Fields {{{
    public:

    virtual File const& getFile() const = 0;
    // Fields }}}
    // Operators {{{
    public:
        Location getLocation() const;
        Location operator/(char const* subname) const;
        Location operator/(std::string const& subname) const;
    // Operators }}}
};
// class Locatable }}}

}

#endif
