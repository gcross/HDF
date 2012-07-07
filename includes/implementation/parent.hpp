#ifndef HDFPP_IMPLEMENTATION_PARENT_HPP
#define HDFPP_IMPLEMENTATION_PARENT_HPP

// Includes {{{
#include "error.hpp"
#include "locatable.hpp"
#include "parent.hpp"
#include "properties/link.hpp"

#include <hdf5.h>
#include <boost/optional.hpp>
#include <string>
// Includes }}}

namespace HDF {

// Exceptions {{{
struct LinkRemoveError : public Error { // {{{
    std::string name;
    LinkRemoveError(char const* name);
    virtual ~LinkRemoveError() throw();
}; // }}}
// Exceptions }}}

class Parent: public virtual Identifiable { // {{{
    // Miscellaneous {{{
    public:
        void remove(char const* name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
        void remove(std::string const& name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
    // Miscellaneous }}}
}; // }}}

}

#endif
