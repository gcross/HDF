// Includes {{{
#include "properties/link.hpp"
// Includes }}}

namespace HDF {

// Properties {{{
//     link access {{{
DEFINE_PROPERTIES_BOILERPLATE(LinkAccess,link access,LINK_ACCESS)
//     link access }}}
//         link creation {{{
DEFINE_PROPERTIES_BOILERPLATE(LinkCreation,link creation,LINK_CREATE)

//         character encoding {{{
LinkCreationProperties LinkCreationProperties::setCharacterEncoding(CharacterEncoding encoding) const { // {{{
    assertSuccess(
        "setting character encoding property",
        H5Pset_char_encoding(
            getId(),
            static_cast<H5T_cset_t>(encoding)
        )
    );
    return *this;
} // }}}

CharacterEncoding LinkCreationProperties::getCharacterEncoding() const { // {{{
    H5T_cset_t id;
    assertSuccess(
        "getting character encoding property",
        H5Pget_char_encoding(
            getId(),
            &id
        )
    );
    return static_cast<CharacterEncoding>(id);
} // }}}
//         character encoding }}}

//         link creation }}}
// Properties }}}

}
