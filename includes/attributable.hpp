//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2828: * @file attributable.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2830: ** << License >>
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

#ifndef HDFPP_ATTRIBUTABLE_HPP
#define HDFPP_ATTRIBUTABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2829: ** << Includes >>
#include "locatable.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2831: ** class Attributable
//@+<< Forward declarations >>
//@+node:gcross.20110528133907.2112: *3* << Forward declarations >>
class Attribute;
//@-<< Forward declarations >>

class Attributable: public virtual Locatable {
    //@+others
    //@+node:gcross.20110521115623.2832: *3* Operators
    public:

    Attribute operator[] (char const* name) const;
    //@-others
};
//@-others

}

#endif
//@-leo
