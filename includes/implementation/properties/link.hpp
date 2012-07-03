//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2130: * @file link.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_LINK_ACCESS_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_LINK_ACCESS_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2131: ** << Includes >>
#include "../properties.hpp"
#include "shared/create_missing_intermediate_groups.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110602092541.2153: ** Properties
//@+node:gcross.20110525201928.3097: *3* LinkAccessProperties
struct LinkAccessProperties: public Properties {
    DECLARE_PROPERTIES_BOILERPLATE(LinkAccess)
};
//@+node:gcross.20110525201928.3098: *3* LinkCreationProperties
struct LinkCreationProperties
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<LinkCreationProperties>
{
    DECLARE_PROPERTIES_BOILERPLATE(LinkCreation)

    //@+others
    //@+node:gcross.20110602121059.2126: *4* character encoding
    LinkCreationProperties setCharacterEncoding(CharacterEncoding encoding) const;

    CharacterEncoding getCharacterEncoding() const;
    //@-others
};
//@-others

}

#endif
//@-leo
