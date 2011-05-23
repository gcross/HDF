//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1350: * @file containable.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1352: ** << License >>
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

#ifndef HDFPP_CONTAINABLE_HPP
#define HDFPP_CONTAINABLE_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1351: ** << Includes >>
#include "identifiable.hpp"
#include "location.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1353: ** class Containable
//@+<< Forward declarations >>
//@+node:gcross.20110520211700.1488: *3* << Forward declarations >>
class File;
//@-<< Forward declarations >>

class Containable: public Identifiable {
    //@+others
    //@+node:gcross.20110520194631.1357: *3* Constructors
    protected:

    Containable();
    Containable(hid_t id, Identity::Closer const& closer);
    Containable(Identity::Ptr const& file_and_self_identity);
    Containable(Identity::Ptr const& file_identity, hid_t id, Identity::Closer const& closer);
    Containable(Identity::Ptr const& file_identity, Identity::Ptr const& self_identity);
    //@+node:gcross.20110520211700.1486: *3* Fields
    protected:

    Identity::Ptr file_identity;

    public:

    virtual Identity::Ptr const& getFileIdentity() const;
    File getFile() const;
    //@-others
};
//@-others

}

#endif
//@-leo
