//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2893: * @file group.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2895: ** << License >>
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

#ifndef HDFPP_GROUP_HPP
#define HDFPP_GROUP_HPP

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
