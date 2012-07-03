//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2231: * @file link.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110602092541.2233: ** << Includes >>
#include "properties/link.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110602092541.2234: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110602092541.2235: ** Properties
//@+node:gcross.20110602092541.2239: *3* LinkAccessProperties
DEFINE_PROPERTIES_BOILERPLATE(LinkAccess,link access,LINK_ACCESS)
//@+node:gcross.20110525201928.3099: *3* LinkCreationProperties
DEFINE_PROPERTIES_BOILERPLATE(LinkCreation,link creation,LINK_CREATE)

//@+others
//@+node:gcross.20110602121059.2127: *4* character encoding
LinkCreationProperties LinkCreationProperties::setCharacterEncoding(CharacterEncoding encoding) const {
    assertSuccess(
        "setting character encoding property",
        H5Pset_char_encoding(
            getId(),
            static_cast<H5T_cset_t>(encoding)
        )
    );
    return *this;
}

CharacterEncoding LinkCreationProperties::getCharacterEncoding() const {
    H5T_cset_t id;
    assertSuccess(
        "getting character encoding property",
        H5Pget_char_encoding(
            getId(),
            &id
        )
    );
    return static_cast<CharacterEncoding>(id);
}
//@-others
//@-others

}
//@-leo
