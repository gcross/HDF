//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1472: * @file properties.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520211700.1473: ** << License >>
//@+at
// Copyright (c) 2011, Gregory Crosswhite
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//@@c
//@-<< License >>

//@+<< Includes >>
//@+node:gcross.20110520211700.1474: ** << Includes >>
#include "error.hpp"
#include "properties.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1475: ** << Usings >>
using boost::optional;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1478: ** class Properties
//@+node:gcross.20110520211700.1479: *3* Constructors/Destructors
Properties::Properties(hid_t id) : Identifiable(id,H5Pclose) {}
//@+node:gcross.20110520211700.1501: ** Properties
LinkAccessProperties::LinkAccessProperties()
  : Properties(assertSuccess("creating link access properties",H5Pcreate(H5P_LINK_ACCESS)))
{}
//@+node:gcross.20110525201928.3099: *3* LinkCreationProperties
LinkCreationProperties::LinkCreationProperties()
  : Properties(assertSuccess("creating link creation properties",H5Pcreate(H5P_LINK_CREATE)))
{}

H5T_cset_t LinkCreationProperties::getCharacterEncodingId(CharacterEncoding encoding) {
    switch(encoding) {
        case ASCIIEncoding: return H5T_CSET_ASCII;
        case UTF8Encoding: return H5T_CSET_UTF8;
    }
}

LinkCreationProperties::CharacterEncoding LinkCreationProperties::getCharacterEncodingFromId(H5T_cset_t id) {
    switch(id) {
        case H5T_CSET_ASCII: return ASCIIEncoding;
        case H5T_CSET_UTF8: return UTF8Encoding;
        default: return ASCIIEncoding;
    }
}

LinkCreationProperties LinkCreationProperties::setCharacterEncoding(CharacterEncoding encoding) const {
    assertSuccess(
        "setting character encoding property",
        H5Pset_char_encoding(
            getId(),
            getCharacterEncodingId(encoding)
        )
    );
    return *this;
}

LinkCreationProperties::CharacterEncoding LinkCreationProperties::getCharacterEncoding() const {
    H5T_cset_t id;
    assertSuccess(
        "getting character encoding property",
        H5Pget_char_encoding(
            getId(),
            &id
        )
    );
    return getCharacterEncodingFromId(id);
}

LinkCreationProperties LinkCreationProperties::setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups) const {
    assertSuccess(
        "setting create intermediate groups property",
        H5Pset_create_intermediate_group(
            getId(),
            create_missing_intermediate_groups
        )
    );
    return *this;
}

bool LinkCreationProperties::getCreateMissingIntermediateGroups() const {
    unsigned int create_missing_intermediate_groups;
    assertSuccess(
        "getting create intermediate groups property",
        H5Pget_create_intermediate_group(
            getId(),
            &create_missing_intermediate_groups
        )
    );
    return create_missing_intermediate_groups==1;
}

LinkCreationProperties LinkCreationProperties::createMissingIntermediateGroups() const {
    return setCreateMissingIntermediateGroups(true);
}

LinkCreationProperties LinkCreationProperties::dontCreateMissingIntermediateGroups() const {
    return setCreateMissingIntermediateGroups(false);
}
//@-others

}
//@-leo
