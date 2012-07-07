#ifndef HDFPP_IMPLEMENTATION_ATTRIBUTABLE_HPP
#define HDFPP_IMPLEMENTATION_ATTRIBUTABLE_HPP

// Includes {{{
#include "locatable.hpp"
// Includes }}}

namespace HDF {

// Forward declarations {{{
class Attribute;
// Forward declarations }}}

class Attributable: public virtual Locatable { // {{{
    public:

    Attribute operator[] (char const* name) const;
}; // }}}

}

#endif
