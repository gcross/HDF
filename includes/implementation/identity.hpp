//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1284: * @file identity.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1286: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_IDENTITY_HPP
#define HDFPP_IMPLEMENTATION_IDENTITY_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1285: ** << Includes >>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1287: ** class Identity
class Identity: boost::noncopyable {
    //@+others
    //@+node:gcross.20110520194631.1290: *3* Typedefs
    public:

    typedef boost::function<void(hid_t)> Closer;
    typedef boost::shared_ptr<Identity const> Ptr;
    //@+node:gcross.20110520194631.1289: *3* Constructors/Destructors
    public:

    Identity(hid_t id, Closer const& close);
    ~Identity();
    //@+node:gcross.20110520194631.1288: *3* Fields
    protected:

    hid_t id;
    Closer close;

    public:

    virtual hid_t getId() const;
    //@-others
};
//@-others

}

#endif
//@-leo
