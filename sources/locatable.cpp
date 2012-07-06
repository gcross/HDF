// Includes {{{
#include "implementation/file.hpp"
#include "implementation/locatable.hpp"
#include "implementation/location.hpp"
// Includes }}}

namespace HDF {

// class Locatable {{{
// Operators {{{
Location Locatable::getLocation() const {
    return Location(getFile(),getIdentity(),Location::dot);
}


Location Locatable::operator/(char const* subname) const {
    return getLocation() / subname;
}

Location Locatable::operator/(std::string const& subname) const {
    return getLocation() / subname;
}
// Operators }}}
// class Locatable }}}

}
