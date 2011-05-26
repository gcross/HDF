//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3198: * @file temporary_memory_file.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3200: ** << License >>
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

#ifndef HDFPP_TEMPORARY_MEMORY_FILE_HPP
#define HDFPP_TEMPORARY_MEMORY_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3199: ** << Includes >>
#include "memory_file.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.3201: ** class TemporaryMemoryFile
class TemporaryMemoryFile: public MemoryFile {
    //@+others
    //@+node:gcross.20110521115623.3203: *3* Constructors
    public:

    TemporaryMemoryFile(
        size_t increment_size_in_bytes = 4096
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    //@+node:gcross.20110521115623.3219: *3* Miscellaneous
    protected:

    static char const* getTemporaryFileName();
    //@-others
};
//@-others

}

#endif
//@-leo
