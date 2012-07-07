#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_LINK_ACCESS_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_LINK_ACCESS_HPP

// Includes {{{
#include "../properties.hpp"
#include "shared/create_missing_intermediate_groups.hpp"
// Includes }}}

namespace HDF {

// Properties {{{
struct LinkAccessProperties: public Properties { // {{{
    DECLARE_PROPERTIES_BOILERPLATE(LinkAccess)
}; // }}}
struct LinkCreationProperties // {{{
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<LinkCreationProperties>
{
    DECLARE_PROPERTIES_BOILERPLATE(LinkCreation)

    // character ending {{{
    LinkCreationProperties setCharacterEncoding(CharacterEncoding encoding) const;

    CharacterEncoding getCharacterEncoding() const;
    // character ending }}}
}; // }}}
// Properties }}}

}

#endif
