//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1319: * @file identifiable.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1321: ** << License >>
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

#ifndef HDFPP_IDENTIFIABLE_HPP
#define HDFPP_IDENTIFIABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1320: ** << Includes >>
#include "identity.hpp"

#include <boost/function.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1322: ** class Identifiable
class Identifiable {
    //@+others
    //@+node:gcross.20110520194631.1324: *3* Constructors/Destructors
    protected:

    Identifiable(Identity::Ptr const& identity);
    Identifiable(hid_t id, Identity::Closer const& closer);

    public:

    Identifiable();
    virtual ~Identifiable();
    //@+node:gcross.20110520194631.1325: *3* Fields
    protected:

    Identity::Ptr identity;

    public:

    virtual Identity::Ptr const& getIdentity() const;
    virtual hid_t getId() const;
    //@+node:gcross.20110521115623.2946: *3* Operators
    public:

    bool operator==(Identifiable const& other) const;
    //@-others
};
//@-others

}

#endif
//@-leo
