#ifndef HDFPP_IMPLEMENTATION_CONTAINED_HPP
#define HDFPP_IMPLEMENTATION_CONTAINED_HPP

// Includes {{{
#include "identified.hpp"
#include "location.hpp"
// Includes }}}

namespace HDF {

class Contained: public Identified, public virtual Locatable { // {{{
    // Constructors {{{
    protected:

    Contained();
    Contained(File const& file, hid_t id, Identity::Closer const& closer);
    Contained(File const& file, Identity::Ptr const& self_identity);
    // Constructors }}}
    // Fields {{{
    protected:

    File file;

    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    // Fields }}}
}; // }}}

}

#endif
