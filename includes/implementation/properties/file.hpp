//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2106: * @file file.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2108: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2107: ** << Includes >>
#include "../properties.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110602092541.2152: ** Properties
//@+node:gcross.20110526150836.1974: *3* FileAccessProperties
struct FileAccessProperties: public Properties {
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileAccess)

    //@+others
    //@+node:gcross.20110526194358.1949: *4* core driver
    FileAccessProperties useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const;

    void getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const;
    std::pair<size_t,bool> getCoreDriverSettings() const;
    //@-others
};
//@+node:gcross.20110526150836.1973: *3* FileCreationProperties
struct FileCreationProperties: public Properties {
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileCreation)

    //@+others
    //@-others
};
//@-others

}

#endif
//@-leo
