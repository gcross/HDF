//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2905: * @file group.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.2907: ** << Includes >>
#include "implementation/group.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2908: ** << Usings >>
using boost::optional;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2909: ** class Group
//@+node:gcross.20110521115623.2910: *3* Constructors
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
//@+node:gcross.20110602121059.2130: *3* Informational
GroupCreationProperties Group::getCopyOfCreationProperties() const {
    return GroupCreationProperties(assertSuccess(
        "getting group creation properties",
        H5Gget_create_plist(getId())
    ));
}
//@-others

}
//@-leo
