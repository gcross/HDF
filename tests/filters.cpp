//@+leo-ver=5-thin
//@+node:gcross.20110528133907.2077: * @file filters.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110528133907.2078: ** << License >>
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
//@+node:gcross.20110528133907.2079: ** << Includes >>
#include "properties/dataset.hpp"

#include <illuminate.hpp>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110528133907.2080: ** << Usings >>
using HDF::DatasetCreationProperties;
using HDF::Filter;

using std::auto_ptr;
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110528133907.2032: ** Functions
//@+node:gcross.20110528133907.2033: *3* checkCorrectFilterClass
template<typename FilterClass> void checkCorrectFilterClass(auto_ptr<Filter> filter_ptr) {
    EXPECT_EQ(
        FilterClass::filter_id,
        filter_ptr->getFilterId()
    );
    EXPECT_EQ(
        string(typeid(FilterClass).name()),
        string(typeid(*filter_ptr).name())
    );
}
//@+node:gcross.20110526194358.1978: ** Filters
TEST_SUITE(Filters) {

//@+others
//@+node:gcross.20110528133907.2051: *3* Deflate
TEST_CASE(Deflate) {
    using HDF::DeflateCompressionFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(DeflateCompressionFilter(5)));
    checkCorrectFilterClass<DeflateCompressionFilter>(properties.getFilterAtIndex(0));
    DeflateCompressionFilter const filter = properties.getFilterOfType<DeflateCompressionFilter>();
    EXPECT_EQ(5u,filter.getCompressionLevel());
}
//@+node:gcross.20110526194358.1990: *3* Fletcher32
TEST_CASE(Fletcher32) {
    using HDF::Fletcher32ChecksumFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(Fletcher32ChecksumFilter()));
    checkCorrectFilterClass<Fletcher32ChecksumFilter>(properties.getFilterAtIndex(0));
}
//@+node:gcross.20110528133907.2037: *3* NBit
TEST_CASE(NBit) {
    using HDF::NBitCompressionFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(NBitCompressionFilter()));
    checkCorrectFilterClass<NBitCompressionFilter>(properties.getFilterAtIndex(0));
}
//@+node:gcross.20110528133907.2045: *3* ScaleOffset
TEST_CASE(ScaleOffset) {
    using HDF::ScaleOffsetCompressionFilter;
    using HDF::ScaleInteger;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(ScaleOffsetCompressionFilter(ScaleInteger,42)));
    checkCorrectFilterClass<ScaleOffsetCompressionFilter>(properties.getFilterAtIndex(0));
    ScaleOffsetCompressionFilter const filter = properties.getFilterOfType<ScaleOffsetCompressionFilter>();
    EXPECT_EQ(ScaleInteger,filter.getScaleMethod());
    EXPECT_EQ(42u,filter.getScaleFactor());
}
//@+node:gcross.20110528133907.2035: *3* Shuffle
TEST_CASE(Shuffle) {
    using HDF::ShuffleFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(ShuffleFilter()));
    checkCorrectFilterClass<ShuffleFilter>(properties.getFilterAtIndex(0));
}
//@+node:gcross.20110528133907.2049: *3* SZIP
TEST_CASE(SZIP) {
    using HDF::SZIPCompressionFilter;
    using HDF::SZIPNearestNeighborCodingMethod;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(SZIPCompressionFilter(SZIPNearestNeighborCodingMethod,42)));
    checkCorrectFilterClass<SZIPCompressionFilter>(properties.getFilterAtIndex(0));
    SZIPCompressionFilter const filter = properties.getFilterOfType<SZIPCompressionFilter>();
    EXPECT_EQ(SZIPNearestNeighborCodingMethod,filter.getCodingMethod());
    EXPECT_EQ(42u,filter.getPixelsPerBlock());
}
//@-others

}
//@-others
//@-leo
