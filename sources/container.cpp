//@+leo-ver=5-thin
//@+node:gcross.20110524225139.1842: * @file container.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110524225139.1843: ** << License >>
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
//@+node:gcross.20110524225139.1844: ** << Includes >>
#include "container.hpp"
#include "utilities.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <boost/foreach.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110524225139.1845: ** << Usings >>
using boost::algorithm::trim_left_if;
using boost::optional;

using std::make_pair;
using std::pair;
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110524225139.1849: ** class Container
//@+node:gcross.20110524225139.1850: *3* Constructors
Container::Container(File const& file) : Containable(file,file.getIdentity()) {}

Container::Container(Group const& group) : Containable(group) {}

Container::Container(Location const& location)
  : Containable(location.getFile(),Identity::Ptr())
{
    initialize(location);
}

Container::Container(
    CreateAt<Location const> location
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , optional<GroupCreationProperties const&> const& optional_creation_properties
)
  : Containable(location->getFile(),Identity::Ptr())
{
    initialize(*location,make_pair(optional_link_creation_properties,optional_creation_properties));
}

void Container::initialize(
    Location const& location
  , optional<pair<
        optional<LinkCreationProperties const&>
     ,  optional<GroupCreationProperties const&>
    > > const& creation_properties
) {
    string const& name = location.getName();
    string trimmed_name = name;
    trim_left_if(trimmed_name,isSlashOrDot);
    if(trimmed_name.empty()
    && (file.getIdentity() == location.getParentIdentity()
        || (!name.empty() && name[0] == '/')
       )
    ) identity = file.getIdentity();
    else {
        if(creation_properties)
             *this =
                Group(
                    createAt(location),
                    creation_properties->first,
                    creation_properties->second
                );
        else *this = Group(location);
    }
}
//@+node:gcross.20110524225139.1851: *3* Fields
hid_t Container::getParentId() const { return getId(); }
//@+node:gcross.20110524225139.1858: *3* Operators
void Container::operator=(File const& file) {
    this->file = file;
    identity = file.getIdentity();
}

void Container::operator=(Group const& group) {
    file = group.getFile();
    identity = group.getIdentity();
}
//@-others

}
//@-leo
