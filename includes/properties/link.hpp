//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2130: * @file link.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2132: ** << License >>
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

#ifndef HDFPP_PROPERTIES_LINK_ACCESS_HPP
#define HDFPP_PROPERTIES_LINK_ACCESS_HPP

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
