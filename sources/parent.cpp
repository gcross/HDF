//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1402: * @file parent.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1403: ** << License >>
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
//@+node:gcross.20110520194631.1404: ** << Includes >>
#include "implementation/parent.hpp"

#include <boost/format.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1405: ** << Usings >>
using boost::format;
using boost::optional;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1509: ** Exceptions
//@+node:gcross.20110520211700.1510: *3* LinkRemoveError
LinkRemoveError::LinkRemoveError(char const* name)
  : Error((format("deleting name %1%") % name).str())
  , name(name)
{}

LinkRemoveError::~LinkRemoveError() throw() {}
//@+node:gcross.20110520211700.1499: ** class Parent
//@+node:gcross.20110523113700.1697: *3* Miscellaneous
void Parent::remove(char const* name, optional<LinkAccessProperties const&> const& optional_properties) const {
    if(H5Ldelete(
        getId(),
        name,
        getOptionalPropertiesId(optional_properties)
       ) < 0
    ) throw LinkRemoveError(name);
}

void Parent::remove(string const& name, optional<LinkAccessProperties const&> const& optional_properties) const {
    remove(name.c_str(),optional_properties);
}
//@-others

}
//@-leo
