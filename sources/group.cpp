//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2905: * @file group.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2906: ** << License >>
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
//@+node:gcross.20110521115623.2907: ** << Includes >>
#include "group.hpp"
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
            H5Gopen(
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
            H5Gcreate(
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
//@-others

}
//@-leo
