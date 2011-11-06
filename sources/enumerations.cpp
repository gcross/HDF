//@+leo-ver=5-thin
//@+node:gcross.20110526150836.1935: * @file enumerations.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110526150836.1936: ** << License >>
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
//@+node:gcross.20110526150836.1937: ** << Includes >>
#include "implementation/enumerations.hpp"

#include <boost/lexical_cast.hpp>
#include <stdexcept>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110526150836.1938: ** << Usings >>
using boost::lexical_cast;

using std::invalid_argument;
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110526150836.1956: ** Functions
//@+node:gcross.20110526150836.1957: *3* getFileCreateModeFlag
unsigned int getFileCreateModeFlag(FileCreateMode mode) {
    switch(mode) {
        case FailIfFileExisting: return H5F_ACC_EXCL;
        case TruncateIfFileExisting: return H5F_ACC_TRUNC;
    }
    throw invalid_argument(lexical_cast<string>(mode));
}
//@+node:gcross.20110526150836.1958: *3* getFileOpenModeFlag
unsigned int getFileOpenModeFlag(FileOpenMode mode) {
    switch(mode) {
        case OpenReadOnly: return H5F_ACC_RDONLY;
        case OpenReadWrite: return H5F_ACC_RDWR;
    }
    throw invalid_argument(lexical_cast<string>(mode));
}
//@-others

}
//@-leo
