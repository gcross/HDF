// Includes {{{
#include "properties/dataset.hpp"

#include <illuminate.hpp>
// Includes }}}

// Usings {{{
using HDF::DatasetCreationProperties;
using HDF::Filter;

using std::auto_ptr;
using std::string;
// Usings }}}

// Helper Functions {{{
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
// Helper Functions }}}
TEST_SUITE(Filters) { // {{{
TEST_CASE(Deflate) { // {{{
    using HDF::DeflateCompressionFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(DeflateCompressionFilter(5)));
    checkCorrectFilterClass<DeflateCompressionFilter>(properties.getFilterAtIndex(0));
    DeflateCompressionFilter const filter = properties.getFilterOfType<DeflateCompressionFilter>();
    EXPECT_EQ(5u,filter.getCompressionLevel());
} // }}}
TEST_CASE(Fletcher32) { // {{{
    using HDF::Fletcher32ChecksumFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(Fletcher32ChecksumFilter()));
    checkCorrectFilterClass<Fletcher32ChecksumFilter>(properties.getFilterAtIndex(0));
} // }}}
TEST_CASE(NBit) { // {{{
    using HDF::NBitCompressionFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(NBitCompressionFilter()));
    checkCorrectFilterClass<NBitCompressionFilter>(properties.getFilterAtIndex(0));
} // }}}
TEST_CASE(ScaleOffset) { // {{{
    using HDF::ScaleOffsetCompressionFilter;
    using HDF::ScaleInteger;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(ScaleOffsetCompressionFilter(ScaleInteger,42)));
    checkCorrectFilterClass<ScaleOffsetCompressionFilter>(properties.getFilterAtIndex(0));
    ScaleOffsetCompressionFilter const filter = properties.getFilterOfType<ScaleOffsetCompressionFilter>();
    EXPECT_EQ(ScaleInteger,filter.getScaleMethod());
    EXPECT_EQ(42u,filter.getScaleFactor());
} // }}}
TEST_CASE(Shuffle) { // {{{
    using HDF::ShuffleFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(ShuffleFilter()));
    checkCorrectFilterClass<ShuffleFilter>(properties.getFilterAtIndex(0));
} // }}}
TEST_CASE(SZIP) { // {{{
    using HDF::SZIPCompressionFilter;
    using HDF::SZIPNearestNeighborCodingMethod;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(SZIPCompressionFilter(SZIPNearestNeighborCodingMethod,42)));
    checkCorrectFilterClass<SZIPCompressionFilter>(properties.getFilterAtIndex(0));
    SZIPCompressionFilter const filter = properties.getFilterOfType<SZIPCompressionFilter>();
    EXPECT_EQ(SZIPNearestNeighborCodingMethod,filter.getCodingMethod());
    EXPECT_EQ(42u,filter.getPixelsPerBlock());
} // }}}
} // }}}
