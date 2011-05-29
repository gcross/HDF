//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1449: * @file contained.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520211700.1450: ** << License >>
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
//@+node:gcross.20110520211700.1451: ** << Includes >>
#include "contained.hpp"
#include "file.hpp"

#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1452: ** << Usings >>
using boost::make_shared;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1456: ** class Contained
//@+node:gcross.20110520211700.1457: *3* Constructors
Contained::Contained() {}

Contained::Contained(File const& file, hid_t id, Identity::Closer const& closer)
  : Identified(make_shared<Identity>(id,closer))
  , file(file)
{}

Contained::Contained(File const& file, Identity::Ptr const& identity)
  : Identified(identity)
  , file(file)
{}
//@+node:gcross.20110520211700.1489: *3* Fields
File const& Contained::getFile() const { return file; }
Identity::Ptr const& Contained::getIdentity() const { return identity; }
//@-others

}
//@-leo
