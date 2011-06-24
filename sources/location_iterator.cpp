//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2953: * @file location_iterator.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2954: ** << License >>
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
//@+node:gcross.20110521115623.2955: ** << Includes >>
#include "implementation/location_iterator.hpp"

#include <boost/lexical_cast.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2956: ** << Usings >>
using boost::lexical_cast;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2963: ** class LocationIterator
//@+node:gcross.20110521115623.2964: *3* Constructors
LocationIterator::LocationIterator() {}

LocationIterator::LocationIterator(Locatable const& parent, int index, int direction)
  : location(parent.getLocation())
  , index(index)
  , direction(direction)
{
    updateMyLocation();
}
//@+node:gcross.20110521115623.2966: *3* Facade requirements
Location const& LocationIterator::dereference() const { return location; }

bool LocationIterator::equal(LocationIterator const& other) const {
    return index == other.index
        && location.getParentId() == other.location.getParentId()
        && location.getFile() == other.location.getFile()
           ;
}

void LocationIterator::increment() { advance(1); }
void LocationIterator::decrement() { advance(-1); }
void LocationIterator::advance(int n) { index += n*direction; updateMyLocation(); }

int LocationIterator::distance_to(LocationIterator const& other) const {
    return (other.index - index)*direction;
}
//@+node:gcross.20110521115623.2967: *3* Miscellaneous
void LocationIterator::updateMyLocation() {
    location %= lexical_cast<string>(index);
}
//@-others

}
//@-leo
