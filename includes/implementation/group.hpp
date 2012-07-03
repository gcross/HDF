//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2893: * @file group.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_GROUP_HPP
#define HDFPP_IMPLEMENTATION_GROUP_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2894: ** << Includes >>
#include "object.hpp"
#include "parameters.hpp"
#include "parent.hpp"
#include "properties/group.hpp"

#include <boost/optional.hpp>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2896: ** class Group
class Group: public Object, public Parent {
    //@+others
    //@+node:gcross.20110521115623.2897: *3* Constructors
    public:

    Group();

    Group(Location const& location);

    Group(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties = boost::none
    );
    //@+node:gcross.20110602121059.2128: *3* Informational
    GroupCreationProperties getCopyOfCreationProperties() const;
    //@-others
};
//@+node:gcross.20110521115623.2977: ** Implementation
namespace Implementation {

hid_t createGroup(
    CreateAt<Location const> location
  , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties
);
hid_t openGroup(Location const& location);

}
//@-others

}

#endif
//@-leo
