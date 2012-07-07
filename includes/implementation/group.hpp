#ifndef HDFPP_IMPLEMENTATION_GROUP_HPP
#define HDFPP_IMPLEMENTATION_GROUP_HPP

// Includes {{{
#include "object.hpp"
#include "parameters.hpp"
#include "parent.hpp"
#include "properties/group.hpp"

#include <boost/optional.hpp>
// Includes }}}

namespace HDF {

class Group: public Object, public Parent { // {{{
    // Constructors {{{
    public:

    Group();

    Group(Location const& location);

    Group(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties = boost::none
    );
    // Constructors }}}
    // Informational {{{
    GroupCreationProperties getCopyOfCreationProperties() const;
    // Informational }}}
}; // }}}

namespace Implementation { // {{{

hid_t createGroup(
    CreateAt<Location const> location
  , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties
);
hid_t openGroup(Location const& location);

} // }}}

}

#endif
