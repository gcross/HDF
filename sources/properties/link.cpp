//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2231: * @file link.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2232: ** << License >>
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
