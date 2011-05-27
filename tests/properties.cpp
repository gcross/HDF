//@+leo-ver=5-thin
//@+node:gcross.20110525201928.3104: * @file properties.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110525201928.3105: ** << License >>
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
//@+node:gcross.20110525201928.3106: ** << Includes >>
#include "properties.hpp"

#include <illuminate.hpp>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110525201928.3107: ** << Usings >>
using HDF::ASCIIEncoding;
using HDF::LinkCreationProperties;
using HDF::FileAccessProperties;
using HDF::UTF8Encoding;

using std::pair;
//@-<< Usings >>

//@+others
//@+node:gcross.20110525201928.3108: ** Tests
TEST_SUITE(Properties) {

//@+others
//@+node:gcross.20110526194358.1939: *3* FileAccessProperties
TEST_SUITE(FileAccessProperties) {

//@+others
//@+node:gcross.20110526194358.1940: *4* core driver
TEST_CASE(core_driver) {
    FileAccessProperties properties;

    EXPECT_TRUE(properties == properties.useCoreDriver(16,true));
    pair<size_t,bool> result = properties.getCoreDriverSettings();
    EXPECT_EQ(16,result.first);
    EXPECT_EQ(true,result.second);
}
//@-others

}
//@+node:gcross.20110525201928.3109: *3* LinkCreationProperties
TEST_SUITE(LinkCreationProperties) {

//@+others
//@+node:gcross.20110525201928.3110: *4* character encoding
TEST_CASE(character_encoding) {
    LinkCreationProperties properties;

    EXPECT_TRUE(properties == properties.setCharacterEncoding(ASCIIEncoding));
    EXPECT_EQ(ASCIIEncoding,properties.getCharacterEncoding());

    EXPECT_TRUE(properties == properties.setCharacterEncoding(UTF8Encoding));
    EXPECT_EQ(UTF8Encoding,properties.getCharacterEncoding());
}
//@+node:gcross.20110525201928.3112: *4* create intermediate groups
TEST_CASE(create_intermediate_groups) {
    LinkCreationProperties properties;

    EXPECT_TRUE(properties == properties.setCreateMissingIntermediateGroups());
    EXPECT_EQ(true,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.setCreateMissingIntermediateGroups(false));
    EXPECT_EQ(false,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.createMissingIntermediateGroups());
    EXPECT_EQ(true,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.dontCreateMissingIntermediateGroups());
    EXPECT_EQ(false,properties.getCreateMissingIntermediateGroups());
}
//@-others

}
//@-others

}
//@-others
//@-leo
