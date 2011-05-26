//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3157: * @file memory_file.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3159: ** << License >>
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

#ifndef HDFPP_MEMORY_FILE_HPP
#define HDFPP_MEMORY_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3158: ** << Includes >>
#include "file.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.3160: ** class MemoryFile
class MemoryFile: public File {
    //@+others
    //@+node:gcross.20110521115623.3161: *3* Constructors
    public:

    MemoryFile(
        char const* filepath
      , FileOpenMode mode
      , size_t increment_size_in_bytes = 4096
      , bool write_data_to_filepath = false
      , boost::optional<FileAccessProperties const&> const& optional_properties = boost::none
    );

    MemoryFile(
        char const* filepath
      , FileCreateMode mode
      , size_t increment_size_in_bytes = 4096
      , bool write_data_to_filepath = false
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    //@-others
};
//@-others

}

#endif
//@-leo
