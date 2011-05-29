//@+leo-ver=5-thin
//@+node:gcross.20110529102535.2064: * @file identifiable.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110529102535.2065: ** << License >>
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
//@+node:gcross.20110529102535.2066: ** << Includes >>
#include "identifiable.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110529102535.2067: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110529102535.2068: ** class Identifiable
//@+node:gcross.20110529102535.2069: *3* Destructors
Identifiable::~Identifiable() {}
//@+node:gcross.20110529102535.2070: *3* Fields
hid_t Identifiable::getId() const { return getIdentity()->getId(); }
//@+node:gcross.20110529102535.2071: *3* Operators
bool Identifiable::operator==(Identifiable const& other) const {
    return getId() == other.getId();
}
//@-others

}
//@-leo
