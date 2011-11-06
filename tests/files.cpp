//@+leo-ver=5-thin
//@+node:gcross.20110524225139.1905: * @file files.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110524225139.1906: ** << License >>
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
//@+node:gcross.20110524225139.1907: ** << Includes >>
#include "dataset.hpp"
#include "temporary_memory_file.hpp"

#include <boost/assign/list_of.hpp>
#include <illuminate.hpp>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110524225139.1908: ** << Usings >>
using HDF::createAt;
using HDF::Dataset;
using HDF::rangeOf;
using HDF::TemporaryMemoryFile;

using boost::assign::list_of;
//@-<< Usings >>

//@+others
//@+node:gcross.20110524225139.1913: ** Functions
//@+node:gcross.20110524225139.1914: *3* fileIdIsInvalid
bool fileIdIsInvalid(hid_t id) {
    bool result = H5Fclose(id) < 0;
    H5Eclear2(H5Eget_current_stack());
    return result;
}
//@+node:gcross.20110524225139.1909: ** Tests
TEST_SUITE(Files) {

//@+others
//@+node:gcross.20110524225139.1910: *3* Closing
TEST_SUITE(Closing) {

//@+others
//@+node:gcross.20110524225139.1911: *4* trivial case
TEST_CASE(trivial_case) {
    hid_t id = TemporaryMemoryFile().getId();
    ASSERT_TRUE(fileIdIsInvalid(id));
}
//@+node:gcross.20110524225139.1916: *4* after creating dataset
TEST_CASE(after_creating_dataset) {
    hid_t id;
    {
        TemporaryMemoryFile file;
        Dataset(createAt(file / "x marks the spot"),rangeOf(list_of(1)));
        id = file.getId();
    }
    ASSERT_TRUE(fileIdIsInvalid(id));
}
//@-others

}
//@-others

}
//@-others
//@-leo
