//@+leo-ver=5-thin
//@+node:gcross.20110526150836.1927: * @file enumerations.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110526150836.1929: ** << License >>
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

#ifndef HDFPP_ENUMERATIONS_HPP
#define HDFPP_ENUMERATIONS_HPP

//@+<< Includes >>
//@+node:gcross.20110526150836.1928: ** << Includes >>
#include "error.hpp"

#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110526150836.1930: ** Enumerations
//@+node:gcross.20110526150836.1952: *3* CharacterEncoding
enum CharacterEncoding {
    ASCIIEncoding = H5T_CSET_ASCII
  , UTF8Encoding = H5T_CSET_UTF8
};
//@+node:gcross.20110526150836.1942: *3* DataspaceClass
enum DataspaceClass {
    SimpleSpace = H5S_SIMPLE
  , ScalarSpace = H5S_SCALAR
  , NullSpace = H5S_NULL
};
//@+node:gcross.20110526150836.1955: *3* FileCreateMode
enum FileCreateMode { FailIfFileExisting, TruncateIfFileExisting };

unsigned int getFileCreateModeFlag(FileCreateMode mode);
//@+node:gcross.20110526150836.1954: *3* FileFlushScope
enum FileFlushScope {
    GlobalFileScope = H5F_SCOPE_GLOBAL
  , LocalFileScope = H5F_SCOPE_LOCAL
};
//@+node:gcross.20110526150836.1953: *3* FileOpenMode
enum FileOpenMode { OpenReadOnly, OpenReadWrite };

unsigned int getFileOpenModeFlag(FileOpenMode mode);
//@-others

}

#endif
//@-leo
