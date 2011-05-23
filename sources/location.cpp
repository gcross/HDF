//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1375: * @file location.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1376: ** << License >>
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
//@+node:gcross.20110520194631.1377: ** << Includes >>
#include "error.hpp"
#include "location.hpp"

#include <boost/format.hpp>
#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1378: ** << Usings >>
using boost::format;
using boost::make_shared;
using boost::optional;
using boost::shared_ptr;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520194631.1384: ** class Location
//@+node:gcross.20110520194631.1385: *3* Constructors/Destructors
Location::Location() {}

Location::Location(
    Identity::Ptr const& file_identity
  , Identity::Ptr const& parent_identity
  , shared_ptr<string const> const name_ptr
)
  : file_identity(file_identity)
  , parent_identity(parent_identity)
  , name(name_ptr)
{}
//@+node:gcross.20110520194631.1386: *3* Fields
Identity::Ptr const& Location::getFileIdentity() const { return file_identity; }
Identity::Ptr const& Location::getParentIdentity() const { return parent_identity; }
string const& Location::getName() const { return *name; }

hid_t Location::getParentId() const { return parent_identity->getId(); }
char const* Location::getNameAsCStr() const { return getName().c_str(); }
//@+node:gcross.20110523113700.2390: *3* Informational
bool Location::exists(optional<LinkAccessProperties const&> const& optional_link_access_properties) const {
    string const& name = *(this->name);
    if(name == "." || name == "/") return true;
    return
        assertSuccess(
            "ascertaining location existence",
            H5Lexists(
                getParentId(),
                name.c_str(),
                getOptionalPropertiesId(optional_link_access_properties)
            )
        ) == 1;
}
//@+node:gcross.20110520194631.1387: *3* Operators
Location Location::operator/(char const* subname) const {
    return Location(
        file_identity,
        parent_identity,
        make_shared<string>((format("%1%/%2%") % getName() % subname).str())
    );
}

Location Location::operator/(string const& subname) const {
    return Location(
        file_identity,
        parent_identity,
        make_shared<string>((format("%1%/%2%") % getName() % subname).str())
    );
}

Location& Location::operator/=(char const* subname) {
    name = make_shared<string>((format("%1%/%2%") % *name % subname).str());
    return *this;
}

Location& Location::operator/=(string const& subname) {
    name = make_shared<string>((format("%1%/%2%") % *name % subname).str());
    return *this;
}

Location Location::operator%(char const* subname) const {
    return Location(
        file_identity,
        parent_identity,
        make_shared<string>(subname)
    );
}

Location Location::operator%(string const& subname) const {
    return Location(
        file_identity,
        parent_identity,
        make_shared<string>(subname)
    );
}

Location& Location::operator%=(char const* subname) {
    name = make_shared<string>(subname);
    return *this;
}

Location& Location::operator%=(string const& subname) {
    name = make_shared<string>(subname);
    return *this;
}
//@+node:gcross.20110520194631.1388: *3* Values
shared_ptr<string const> const
    Location::dot(new string("."))
  , Location::slash(new string("/"))
  ;
//@-others

}
//@-leo
