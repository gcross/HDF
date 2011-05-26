//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3007: * @file group_array.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3008: ** << License >>
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
//@+node:gcross.20110521115623.3009: ** << Includes >>
#include "group_array.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3010: ** << Usings >>
using boost::optional;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3017: ** class GroupArray
//@+node:gcross.20110521115623.3019: *3* Constructors
GroupArray::GroupArray() {}

GroupArray::GroupArray(
    Location const& location
)
  : Group(location)
{}

GroupArray::GroupArray(
    CreateAt<Location const> location
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , optional<GroupCreationProperties const&> const& optional_group_creation_properties
)
  : Group(location,optional_link_creation_properties,optional_group_creation_properties)
{}
//@+node:gcross.20110521115623.3021: *3* Informational
unsigned int GroupArray::size() const { return (*this)["size"]; }
//@+node:gcross.20110521115623.3022: *3* Range interface
GroupArray::iterator GroupArray::begin() const { return LocationIterator(*this); }
GroupArray::iterator GroupArray::end() const { return LocationIterator(*this,size()); }

GroupArray::reverse_iterator GroupArray::rbegin() const { return LocationIterator(*this,size()-1,-1); }
GroupArray::reverse_iterator GroupArray::rend() const { return LocationIterator(*this,-1,-1); }
//@-others

}
//@-leo
