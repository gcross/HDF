//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3166: * @file memory_file.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3167: ** << License >>
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
//@+node:gcross.20110521115623.3168: ** << Includes >>
#include "implementation/memory_file.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3169: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3172: ** class MemoryFile
//@+node:gcross.20110521115623.3173: *3* Constructors
MemoryFile::MemoryFile(
    char const* filepath
  , FileOpenMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileAccessProperties const&> const& optional_properties
)
  : File(
        filepath,
        mode,
        GET_OPTIONAL_OR(optional_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{}

MemoryFile::MemoryFile(
    char const* filepath
  , FileCreateMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileCreationProperties const&> const& optional_creation_properties
  , boost::optional<FileAccessProperties const&> const& optional_access_properties
)
  : File(
        filepath,
        mode,
        optional_creation_properties,
        GET_OPTIONAL_OR(optional_access_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{}
//@-others

}
//@-leo
