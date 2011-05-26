//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3208: * @file temporary_memory_file.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3209: ** << License >>
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
//@+node:gcross.20110521115623.3210: ** << Includes >>
#include "temporary_memory_file.hpp"

#include <cstdio>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3211: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3214: ** class TemporaryMemoryFile
//@+node:gcross.20110521115623.3215: *3* Constructors
TemporaryMemoryFile::TemporaryMemoryFile(
    size_t increment_size_in_bytes
  , boost::optional<CreationProperties const&> const& optional_creation_properties
  , boost::optional<AccessProperties const&> const& optional_access_properties
)
  : MemoryFile(
        getTemporaryFileName(),
        FailIfFileExisting,
        increment_size_in_bytes,
        false,
        optional_creation_properties,
        optional_access_properties
    )
{}
//@+node:gcross.20110521115623.3216: *3* Miscellaneous
char const* TemporaryMemoryFile::getTemporaryFileName() {
    static char buffer[L_tmpnam];
    tmpnam(buffer);
    return buffer;
}
//@-others

}
//@-leo
