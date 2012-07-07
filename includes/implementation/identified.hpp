#ifndef HDFPP_IMPLEMENTATION_IDENTIFIED_HPP
#define HDFPP_IMPLEMENTATION_IDENTIFIED_HPP

// Includes {{{
#include "identifiable.hpp"

#include <hdf5.h>
// Includes }}}

namespace HDF {

class Identified: public virtual Identifiable { // {{{
    // Constructors {{{
    protected:

    Identified(Identity::Ptr const& identity);
    Identified(hid_t id, Identity::Closer const& closer);

    public:

    Identified();
    // Constructors }}}
    // Fields {{{
    protected:

    Identity::Ptr identity;

    public:

    virtual Identity::Ptr const& getIdentity() const;
    // Fields }}}
}; // }}}

}

#endif
