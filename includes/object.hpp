//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2852: * @file object.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2854: ** << License >>
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

#ifndef HDFPP_OBJECT_HPP
#define HDFPP_OBJECT_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2853: ** << Includes >>
#include "attributable.hpp"
#include "locatable.hpp"
#include "properties.hpp"

#include <boost/optional.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2855: ** class Object
class Object: public Locatable, public Attributable {
    //@+others
    //@+node:gcross.20110521115623.2856: *3* Constructors
    protected:

    Object();

    public:

    Object(Identity::Ptr const& file_identity, hid_t id, Identity::Closer const& closer);
    Object(Identity::Ptr const& file_identity, Identity::Ptr const& self_identity);
    Object(Location const& location, boost::optional<LinkAccessProperties> const& optional_properties = boost::none);
    //@+node:gcross.20110521115623.2861: *3* Comments
    public:

    std::string getComment() const;

    void setComment(char const* comment) const;
    void setComment(std::string const& comment) const;
    //@+node:gcross.20110523113700.1693: *3* Fields
    protected:

    virtual Containable const& getAttributeContainable() const;
    //@-others
};
//@-others

}

#endif
//@-leo
