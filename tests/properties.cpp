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

#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>
#include <boost/range/irange.hpp>
#include <illuminate.hpp>
#include <vector>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110525201928.3107: ** << Usings >>
using HDF::DatasetCreationProperties;
using HDF::LinkCreationProperties;
using HDF::FileAccessProperties;

using boost::assign::list_of;
using boost::irange
;

using std::pair;
using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110525201928.3108: ** Tests
TEST_SUITE(Properties) {

//@+others
//@+node:gcross.20110526194358.1950: *3* DatasetCreationProperties
TEST_SUITE(DatasetCreationProperties) {

//@+others
//@+node:gcross.20110526194358.1951: *4* chunk
TEST_CASE(chunk) {
    DatasetCreationProperties properties;

    EXPECT_TRUE(properties == properties.setChunkSizes(list_of(1)(2)(3)));
    vector<hsize_t> chunk_sizes = properties.getChunkSizes();

    EXPECT_EQ(1,chunk_sizes[0]);
    EXPECT_EQ(2,chunk_sizes[1]);
    EXPECT_EQ(3,chunk_sizes[2]);
}
//@+node:gcross.20110526194358.1978: *4* filter
TEST_SUITE(filter) {

//@+others
//@+node:gcross.20110526194358.1990: *5* Fletcher32
TEST_CASE(Fletcher32) {
    using HDF::Fletcher32Filter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.addFletcher32ChecksumFilter());
    EXPECT_EQ(Fletcher32Filter,properties.getFilterTypeAtIndex(0));
}
//@+node:gcross.20110526194358.1979: *5* GZIP
TEST_CASE(GZIP) {
    using HDF::GZIPFilter;
    BOOST_FOREACH(unsigned int const level, irange(1,10)) {
        DatasetCreationProperties properties;
        EXPECT_TRUE(properties == properties.useGZIPCompression(level));
        EXPECT_EQ(level,properties.getGZIPCompressionLevel());
        EXPECT_EQ(GZIPFilter,properties.getFilterTypeAtIndex(0));
    }
}
//@+node:gcross.20110526194358.2000: *5* NBit
TEST_CASE(NBit) {
    using HDF::NBitFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.addNBitCompressionFilter());
    EXPECT_EQ(NBitFilter,properties.getFilterTypeAtIndex(0));
}
//@+node:gcross.20110527143225.1977: *5* ScaleOffset
TEST_CASE(ScaleOffset) {
    using HDF::ScaleOffsetFilter;
    using HDF::IntegerScaleOperation;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.addScaleOffsetCompressionFilter(IntegerScaleOperation,42));
    EXPECT_EQ(IntegerScaleOperation,properties.getScaleOffsetFilterParameters().first);
    EXPECT_EQ(42,properties.getScaleOffsetFilterParameters().second);
    EXPECT_EQ(ScaleOffsetFilter,properties.getFilterTypeAtIndex(0));
}
//@+node:gcross.20110526194358.1981: *5* Shuffle
TEST_CASE(Shuffle) {
    using HDF::ShuffleFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.addShuffleFilter());
    EXPECT_EQ(ShuffleFilter,properties.getFilterTypeAtIndex(0));
}
//@+node:gcross.20110527143225.1986: *5* SZIP
//@+at
// TEST_CASE(SZIPOffset) {
//     using HDF::SZIPFilter;
//     using HDF::SZIPNearestNeighborCodingMethod;
//     DatasetCreationProperties properties;
//     EXPECT_TRUE(properties == properties.addSZIPCompressionFilter(SZIPNearestNeighborCodingMethod,42));
//     EXPECT_EQ(SZIPNearestNeighborCodingMethod,properties.getSZIPFilterParameters().first);
//     EXPECT_EQ(42,properties.getSZIPFilterParameters().second);
//     EXPECT_EQ(SZIPFilter,properties.getFilterTypeAtIndex(0));
// }
//@-others

}
//@+node:gcross.20110527143225.1996: *4* fill value
TEST_CASE(fill_value) {
    DatasetCreationProperties properties;

    EXPECT_TRUE(properties == properties.setFillValue(3.14f));
    EXPECT_EQ(3.14f,properties.getFillValue<float>());
}
//@+node:gcross.20110526194358.1956: *4* layout
TEST_CASE(layout) {
    DatasetCreationProperties properties;

    using HDF::CompactDatasetLayout;
    EXPECT_TRUE(properties == properties.setLayout(CompactDatasetLayout));
    EXPECT_EQ(CompactDatasetLayout,properties.getLayout());

    using HDF::ContiguousDatasetLayout;
    EXPECT_TRUE(properties == properties.setLayout(ContiguousDatasetLayout));
    EXPECT_EQ(ContiguousDatasetLayout,properties.getLayout());

    using HDF::ChunkedDatasetLayout;
    EXPECT_TRUE(properties == properties.setLayout(ChunkedDatasetLayout));
    EXPECT_EQ(ChunkedDatasetLayout,properties.getLayout());
}
//@-others

}
//@+node:gcross.20110526194358.1939: *3* FileAccessProperties
TEST_SUITE(FileAccessProperties) {

//@+others
//@+node:gcross.20110526194358.1940: *4* core driver
TEST_CASE(core_driver) {
    FileAccessProperties properties;

    EXPECT_TRUE(properties == properties.useCoreDriver(16,true));
    pair<size_t,bool> result = properties.getCoreDriverSettings();
    EXPECT_EQ(16u,result.first);
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

    using HDF::ASCIIEncoding;
    EXPECT_TRUE(properties == properties.setCharacterEncoding(ASCIIEncoding));
    EXPECT_EQ(ASCIIEncoding,properties.getCharacterEncoding());

    using HDF::UTF8Encoding;
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
