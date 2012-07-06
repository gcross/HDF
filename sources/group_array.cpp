// Includes {{{
#include "implementation/attribute.hpp"
#include "implementation/group_array.hpp"
// Includes }}}

// Usings {{{
using boost::optional;
// Usings }}}

namespace HDF {

// class GroupArray {{{
// Constructors {{{
GroupArray::GroupArray() {}

GroupArray::GroupArray(
    Location const& location
)
  : Group(location)
{}

GroupArray::GroupArray(
    CreateAt<Location const> location
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , optional<GroupCreationProperties const&> const& optional_group_creation_properties
)
  : Group(location,optional_link_creation_properties,optional_group_creation_properties)
{}
// Contructors }}}
// Informational {{{
unsigned int GroupArray::size() const { return (*this)["size"]; }
// Informational }}}
// Range interface {{{
GroupArray::iterator GroupArray::begin() const { return LocationIterator(*this); }
GroupArray::iterator GroupArray::end() const { return LocationIterator(*this,size()); }

GroupArray::reverse_iterator GroupArray::rbegin() const { return LocationIterator(*this,size()-1,-1); }
GroupArray::reverse_iterator GroupArray::rend() const { return LocationIterator(*this,-1,-1); }
// Range interface }}}
// class GroupArray }}}

}
