//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3007: * @file group_array.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.3009: ** << Includes >>
#include "implementation/attribute.hpp"
#include "implementation/group_array.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3010: ** << Usings >>
using boost::optional;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3017: ** class GroupArray
//@+node:gcross.20110521115623.3019: *3* Constructors
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
//@+node:gcross.20110521115623.3021: *3* Informational
unsigned int GroupArray::size() const { return (*this)["size"]; }
//@+node:gcross.20110521115623.3022: *3* Range interface
GroupArray::iterator GroupArray::begin() const { return LocationIterator(*this); }
GroupArray::iterator GroupArray::end() const { return LocationIterator(*this,size()); }

GroupArray::reverse_iterator GroupArray::rbegin() const { return LocationIterator(*this,size()-1,-1); }
GroupArray::reverse_iterator GroupArray::rend() const { return LocationIterator(*this,-1,-1); }
//@-others

}
//@-leo
