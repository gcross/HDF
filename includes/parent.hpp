//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1343: * @file parent.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1345: ** << License >>
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

#ifndef HDFPP_PARENT_HPP
#define HDFPP_PARENT_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1344: ** << Includes >>
#include "error.hpp"
#include "locatable.hpp"
#include "parent.hpp"
#include "properties.hpp"

#include <hdf5.h>
#include <boost/optional.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520211700.1505: ** Exceptions
//@+node:gcross.20110520211700.1506: *3* LinkRemoveError
struct LinkRemoveError : public Error {
    std::string name;
    LinkRemoveError(char const* name);
    virtual ~LinkRemoveError() throw();
};
//@+node:gcross.20110520194631.1346: ** class Parent
class Parent {
    //@+others
    //@+node:gcross.20110523113700.1699: *3* Destructors
    public:

    virtual ~Parent();
    //@+node:gcross.20110523113700.1680: *3* Fields
    protected:

    virtual hid_t getParentId() const = 0;
    //@+node:gcross.20110523113700.1681: *3* Miscellaneous
    public:
        void remove(char const* name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
        void remove(std::string const& name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
    //@-others
};
//@-others

}

#endif
//@-leo
