// Includes {{{
#include "properties/dataset.hpp"
#include "properties/file.hpp"
#include "properties/group.hpp"
#include "properties/link.hpp"

#include <boost/assign/list_of.hpp>
#include <boost/foreach.hpp>
#include <boost/range/irange.hpp>
#include <illuminate.hpp>
#include <vector>
// Includes }}}

// Usings {{{
using boost::assign::list_of;
using boost::irange;

using std::auto_ptr;
using std::pair;
using std::string;
using std::vector;
// Usings }}}

TEST_SUITE(Properties) { // {{{
TEST_SUITE(DatasetCreationProperties) { // {{{

using HDF::DatasetCreationProperties;
using HDF::Filter;

TEST_CASE(allocation_mode) { // {{{
    DatasetCreationProperties properties;

    using HDF::DefaultAllocationModeForStorage;
    EXPECT_TRUE(properties == properties.setAllocationMode(DefaultAllocationModeForStorage));
    EXPECT_NE(DefaultAllocationModeForStorage,properties.getAllocationMode());

    using HDF::AllocateAllSpaceWhenDatasetIsCreated;
    EXPECT_TRUE(properties == properties.setAllocationMode(AllocateAllSpaceWhenDatasetIsCreated));
    EXPECT_EQ(AllocateAllSpaceWhenDatasetIsCreated,properties.getAllocationMode());

    using HDF::AllocateSpaceIncrementallyAsNeeded;
    EXPECT_TRUE(properties == properties.setAllocationMode(AllocateSpaceIncrementallyAsNeeded));
    EXPECT_EQ(AllocateSpaceIncrementallyAsNeeded,properties.getAllocationMode());

    using HDF::AllocateAllSpaceOnFirstWrite;
    EXPECT_TRUE(properties == properties.setAllocationMode(AllocateAllSpaceOnFirstWrite));
    EXPECT_EQ(AllocateAllSpaceOnFirstWrite,properties.getAllocationMode());
} // }}}
TEST_CASE(chunk) { // {{{
    DatasetCreationProperties properties;

    EXPECT_TRUE(properties == properties.setChunkSizes(list_of(1)(2)(3)));
    vector<hsize_t> chunk_sizes = properties.getChunkSizes();

    EXPECT_EQ(1u,chunk_sizes[0]);
    EXPECT_EQ(2u,chunk_sizes[1]);
    EXPECT_EQ(3u,chunk_sizes[2]);
} // }}}
TEST_CASE(fill_mode) { // {{{
    DatasetCreationProperties properties;

    using HDF::AlwaysFillUponAllocation;
    EXPECT_TRUE(properties == properties.setFillMode(AlwaysFillUponAllocation));
    EXPECT_EQ(AlwaysFillUponAllocation,properties.getFillMode());

    using HDF::OnlyFillUponAllocationIfUserDefinedValue;
    EXPECT_TRUE(properties == properties.setFillMode(OnlyFillUponAllocationIfUserDefinedValue));
    EXPECT_EQ(OnlyFillUponAllocationIfUserDefinedValue,properties.getFillMode());

    using HDF::NeverFill;
    EXPECT_TRUE(properties == properties.setFillMode(NeverFill));
    EXPECT_EQ(NeverFill,properties.getFillMode());
} // }}}
TEST_SUITE(filters) { // {{{

TEST_CASE(modifyFilter) { // {{{
    using HDF::DeflateCompressionFilter;
    DatasetCreationProperties properties;
    EXPECT_TRUE(properties == properties.appendFilter(DeflateCompressionFilter(5)));
    properties.modifyFilter(DeflateCompressionFilter(3));
    EXPECT_EQ(3u,properties.getFilterOfType<DeflateCompressionFilter>().getCompressionLevel());
} // }}}

} // }}}
TEST_CASE(fill_value) { // {{{
    using HDF::FillValueUserDefined;
    DatasetCreationProperties properties;

    EXPECT_NE(FillValueUserDefined,properties.getFillValueStatus());
    EXPECT_TRUE(properties == properties.setFillValue(3.14f));
    EXPECT_EQ(3.14f,properties.getFillValue<float>());
    EXPECT_EQ(FillValueUserDefined,properties.getFillValueStatus());
} // }}}
TEST_CASE(layout) { // {{{
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
} // }}}

} // }}}
TEST_SUITE(FileAccessProperties) { // {{{

using HDF::FileAccessProperties;

TEST_CASE(core_driver) { // {{{
    FileAccessProperties properties;

    EXPECT_TRUE(properties == properties.useCoreDriver(16,true));
    pair<size_t,bool> result = properties.getCoreDriverSettings();
    EXPECT_EQ(16u,result.first);
    EXPECT_EQ(true,result.second);
} // }}}

} // }}}
TEST_SUITE(GroupCreationProperties) { // {{{

using HDF::GroupCreationProperties;

TEST_CASE(estimated_link_information) { // {{{
    GroupCreationProperties properties;

    EXPECT_TRUE(properties == properties.setEstimatedLinkInformation(42u,17u));
    EXPECT_EQ_VAL(properties.getEstimatedLinkInformation().first,42u);
    EXPECT_EQ_VAL(properties.getEstimatedLinkInformation().second,17u);
} // }}}
TEST_CASE(link_creation_order) { // {{{
    GroupCreationProperties properties;

    using HDF::DontTrackLinkCreationOrder;
    EXPECT_TRUE(properties == properties.setLinkCreationOrderTracking(DontTrackLinkCreationOrder));
    EXPECT_EQ_VAL(properties.getLinkCreationOrderTracking(),DontTrackLinkCreationOrder);

    using HDF::TrackLinkCreationOrder;
    EXPECT_TRUE(properties == properties.setLinkCreationOrderTracking(TrackLinkCreationOrder));
    EXPECT_EQ_VAL(properties.getLinkCreationOrderTracking(),TrackLinkCreationOrder);

    using HDF::TrackAndIndexLinksBasedOnCreationOrder;
    EXPECT_TRUE(properties == properties.setLinkCreationOrderTracking(TrackAndIndexLinksBasedOnCreationOrder));
    EXPECT_EQ_VAL(properties.getLinkCreationOrderTracking(),TrackAndIndexLinksBasedOnCreationOrder);
} // }}}
TEST_CASE(local_heap_size_hint) { // {{{
    GroupCreationProperties properties;

    EXPECT_TRUE(properties == properties.setLocalHeapSizeHint(42u));
    EXPECT_EQ_VAL(properties.getLocalHeapSizeHint(),42u);
} // }}}

} // }}}
TEST_SUITE(LinkCreationProperties) { // {{{

using HDF::LinkCreationProperties;

TEST_CASE(character_encoding) { // {{{
    LinkCreationProperties properties;

    using HDF::ASCIIEncoding;
    EXPECT_TRUE(properties == properties.setCharacterEncoding(ASCIIEncoding));
    EXPECT_EQ(ASCIIEncoding,properties.getCharacterEncoding());

    using HDF::UTF8Encoding;
    EXPECT_TRUE(properties == properties.setCharacterEncoding(UTF8Encoding));
    EXPECT_EQ(UTF8Encoding,properties.getCharacterEncoding());
} // }}}
TEST_CASE(create_intermediate_groups) { // {{{
    LinkCreationProperties properties;

    EXPECT_TRUE(properties == properties.setCreateMissingIntermediateGroups());
    EXPECT_EQ(true,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.setCreateMissingIntermediateGroups(false));
    EXPECT_EQ(false,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.createMissingIntermediateGroups());
    EXPECT_EQ(true,properties.getCreateMissingIntermediateGroups());

    EXPECT_TRUE(properties == properties.dontCreateMissingIntermediateGroups());
    EXPECT_EQ(false,properties.getCreateMissingIntermediateGroups());
} // }}}

} // }}}
} // }}}
