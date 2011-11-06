//@+leo-ver=5-thin
//@+node:gcross.20110529102535.2049: * @file identifiable.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110529102535.2050: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP
#define HDFPP_IMPLEMENTATION_IDENTIFIABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110529102535.2051: ** << Includes >>
#include "identity.hpp"

#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110529102535.2052: ** class Identifiable
class Identifiable {
    //@+others
    //@+node:gcross.20110529102535.2053: *3* Destructors
    public:

    virtual ~Identifiable();
    //@+node:gcross.20110529102535.2054: *3* Fields
    public:

    virtual Identity::Ptr const& getIdentity() const = 0;
    hid_t getId() const;
    //@+node:gcross.20110529102535.2055: *3* Operators
    public:

    bool operator==(Identifiable const& other) const;
    //@-others
};
//@-others

}

#endif
//@-leo
