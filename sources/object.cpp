//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2866: * @file object.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2867: ** << License >>
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
//@+node:gcross.20110521115623.2868: ** << Includes >>
#include "object.hpp"

#include <boost/scoped_array.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2869: ** << Usings >>
using boost::optional;
using boost::scoped_array;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2873: ** class Object
//@+node:gcross.20110521115623.2874: *3* Constructors
Object::Object() {}

Object::Object(Identity::Ptr const& file_identity, hid_t id, Identity::Closer const& closer)
  : Locatable(file_identity,id,closer)
{}

Object::Object(Identity::Ptr const& file_identity, Identity::Ptr const& self_identity)
  : Locatable(file_identity,self_identity)
{}

Object::Object(
    Location const& location
  , optional<LinkAccessProperties> const& optional_properties
) : Locatable(
        location.getFileIdentity(),
        assertSuccess(
            "opening object",
            H5Oopen(
                location.getParentId(),
                location.getNameAsCStr(),
                getOptionalPropertiesId(optional_properties)
            )
        ),
        H5Oclose
    )
{}
//@+node:gcross.20110521115623.2875: *3* Comments
string Object::getComment() const {
    size_t comment_size =
        assertSuccess(
            "getting object comment length",
            H5Oget_comment(getId(),NULL,0)
        );
    if(comment_size == 0) return string();

    scoped_array<char> buffer(new char[comment_size+1]);
    assertSuccess(
        "getting object comment",
        H5Oget_comment(getId(),buffer.get(),comment_size+1)
    );
    return string(buffer.get());
}

void Object::setComment(char const* comment) const {
    assertSuccess(
        "setting object comment",
        H5Oset_comment(getId(),comment)
    );
}

void Object::setComment(std::string const& comment) const {
    setComment(comment.c_str());
}
//@+node:gcross.20110523113700.1692: *3* Fields
Containable const& Object::getAttributeContainable() const { return *this; }
//@-others

}
//@-leo
