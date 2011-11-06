//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2983: * @file group_array.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2985: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP
#define HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2984: ** << Includes >>
#include "group.hpp"
#include "location_iterator.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2986: ** class GroupArray
class GroupArray: public Group {
    //@+others
    //@+node:gcross.20110521115623.2996: *3* Associated types
    public:

    typedef LocationIterator iterator;
    typedef LocationIterator const_iterator;
    typedef LocationIterator reverse_iterator;
    typedef LocationIterator reverse_const_iterator;
    //@+node:gcross.20110521115623.2988: *3* Constructors
    public:

    GroupArray();

    GroupArray(Location const& location);

    GroupArray(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties = boost::none
    );
    //@+node:gcross.20110521115623.3002: *3* I/O support
    template<typename T> void operator<<(RangeOf<T> values) const {
        (*this)["size"] = static_cast<unsigned int>(values->size());
        begin() << values;
    }
    //@+node:gcross.20110521115623.2998: *3* Informational
    public:

    unsigned int size() const;
    //@+node:gcross.20110521115623.3000: *3* Range interface
    public:

    iterator begin() const;
    iterator end() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    //@-others
};
//@-others

}

#endif
//@-leo
