// Includes {{{
#include "implementation/parent.hpp"

#include <boost/format.hpp>
// Includes }}}

// Usings {{{
using boost::format;
using boost::optional;

using std::string;
// Usings }}}

namespace HDF {

// Exceptions {{{
// LinkRemoveError {{{
LinkRemoveError::LinkRemoveError(char const* name)
  : Error((format("deleting name %1%") % name).str())
  , name(name)
{}

LinkRemoveError::~LinkRemoveError() throw() {}
// LinkRemoveError }}}
// Exceptinos }}}

// class Parent {{{
// Miscellaneous {{{
void Parent::remove(char const* name, optional<LinkAccessProperties const&> const& optional_properties) const { // {{{
    if(H5Ldelete(
        getId(),
        name,
        getOptionalPropertiesId(optional_properties)
       ) < 0
    ) throw LinkRemoveError(name);
} // }}}

void Parent::remove(string const& name, optional<LinkAccessProperties const&> const& optional_properties) const { // {{{
    remove(name.c_str(),optional_properties);
} // }}}
// Miscellaneous }}}
// class Parent }}}

}
