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

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110524225139.1849: ** class Container
//@+node:gcross.20110524225139.1850: *3* Constructors
Container::Container(File const& file) : Locatable(file) {}

Container::Container(Group const& group) : Locatable(group) {}

Container::Container(Location const& location)
  : Locatable(location.getFileIdentity(),Identity::Ptr())
{
    initialize(location);
}

Container::Container(CreateAt<Location const> location)
  : Locatable(location->getFileIdentity(),Identity::Ptr())
{
    Location current_location = (*location) % "";
    bool first = true;
    BOOST_FOREACH(string const& name, SlashTokenizer(location->getName())) {
        if(first)
            current_location %= name;
        else
            current_location /= name;
        first = false;
        if(!current_location.exists()) Group(createAt(current_location));
    }
    initialize(*location);
}

void Container::initialize(Location const& location) {
    string const& name = location.getName();
    string trimmed_name = name;
    trim_left_if(trimmed_name,isSlashOrDot);
    if(trimmed_name.empty()
    && (file_identity == location.getParentIdentity()
        || (!name.empty() && name[0] == '/')
       )
    ) identity = file_identity;
    else
      *this = Group(location);
}
//@+node:gcross.20110524225139.1851: *3* Fields
hid_t Container::getParentId() const { return getId(); }
//@+node:gcross.20110524225139.1858: *3* Operators
void Container::operator=(File const& file) {
    file_identity = file.getFileIdentity();
    identity = file.getIdentity();
}

void Container::operator=(Group const& group) {
    file_identity = group.getFileIdentity();
    identity = group.getIdentity();
}
//@-others

}
//@-leo
