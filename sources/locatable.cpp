//@+leo-ver=5-thin
//@+node:gcross.20110521115623.1470: * @file locatable.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.1471: ** << License >>
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
//@+node:gcross.20110521115623.1472: ** << Includes >>
#include "locatable.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.1473: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.1474: ** class Locatable
//@+node:gcross.20110523113700.1685: *3* Constructors
Locatable::Locatable() {}

Locatable::Locatable(hid_t id, Identity::Closer const& closer)
  : Containable(id,closer)
{}

Locatable::Locatable(Identity::Ptr const& file_and_self_identity)
  : Containable(file_and_self_identity)
{}

Locatable::Locatable(Identity::Ptr const& file_identity, hid_t id, Identity::Closer const& closer)
  : Containable(file_identity,id,closer)
{}

Locatable::Locatable(Identity::Ptr const& file_identity, Identity::Ptr const& self_identity)
  : Containable(file_identity,self_identity)
{}
//@+node:gcross.20110523113700.1686: *3* Location
Location Locatable::getLocation() const {
    return Location(file_identity,identity,Location::dot);
}


Location Locatable::operator/(char const* subname) const {
    return getLocation() / subname;
}

Location Locatable::operator/(std::string const& subname) const {
    return getLocation() / subname;
}
//@-others

}
//@-leo
