// Includes {{{
#include "implementation/group.hpp"
// Includes }}}

// Usings {{{
using boost::optional;
// Usings }}}

namespace HDF {

// class Group {{{
// Constructors {{{
Group::Group() {}

Group::Group(
    Location const& location
)
  : Object(
        location.getFile(),
        assertSuccess(
            "opening group",
            H5Gopen2(
                location.getParentId(),
                location.getNameAsCStr(),
                H5P_DEFAULT
            )
        ),
        H5Gclose
    )
{}

Group::Group(
    CreateAt<Location const> location
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , optional<GroupCreationProperties const&> const& optional_group_creation_properties
)
  : Object(
        location->getFile(),
        assertSuccess(
            "opening group",
            H5Gcreate2(
                location->getParentId(),
                location->getNameAsCStr(),
                getOptionalPropertiesId(optional_link_creation_properties),
                getOptionalPropertiesId(optional_group_creation_properties),
                H5P_DEFAULT
            )
        ),
        H5Gclose
    )
{}
// Constructors }}}
// Informational {{{
GroupCreationProperties Group::getCopyOfCreationProperties() const {
    return GroupCreationProperties(assertSuccess(
        "getting group creation properties",
        H5Gget_create_plist(getId())
    ));
}
// Informational }}}
// class Group }}}

}
