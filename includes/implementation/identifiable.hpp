#ifndef HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP
#define HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP

// Includes {{{
#include "identity.hpp"

#include <hdf5.h>
// Includes }}}

namespace HDF {

class Identifiable { // {{{
    // Destructors {{{
    public:

    virtual ~Identifiable();
    // Destructors }}}
    // Fields {{{
    public:

    virtual Identity::Ptr const& getIdentity() const = 0;
    hid_t getId() const;
    // Fields }}}
    // Operators {{{
    public:

    bool operator==(Identifiable const& other) const;
    // Operators }}}
}; // }}}

}

#endif
