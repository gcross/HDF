#ifndef HDFPP_IMPLEMENTATION_ENUMERATIONS_HPP
#define HDFPP_IMPLEMENTATION_ENUMERATIONS_HPP

// Includes {{{
#include "error.hpp"

#include <hdf5.h>
// Includes }}}

namespace HDF {

// Enumerations {{{
enum AllocationMode { // {{{
    DefaultAllocationModeForStorage = H5D_ALLOC_TIME_DEFAULT
  , AllocateAllSpaceWhenDatasetIsCreated = H5D_ALLOC_TIME_EARLY
  , AllocateSpaceIncrementallyAsNeeded = H5D_ALLOC_TIME_INCR
  , AllocateAllSpaceOnFirstWrite = H5D_ALLOC_TIME_LATE
}; // }}}
enum CharacterEncoding { // {{{
    ASCIIEncoding = H5T_CSET_ASCII
  , UTF8Encoding = H5T_CSET_UTF8
}; // }}}
enum DatasetLayout { // {{{
    CompactDatasetLayout = H5D_COMPACT
  , ContiguousDatasetLayout = H5D_CONTIGUOUS
  , ChunkedDatasetLayout = H5D_CHUNKED
}; // }}}
enum DataspaceClass { // {{{
    SimpleSpace = H5S_SIMPLE
  , ScalarSpace = H5S_SCALAR
  , NullSpace = H5S_NULL
}; // }}}
// enum FileCreateMode {{{
enum FileCreateMode { FailIfFileExisting, TruncateIfFileExisting };

unsigned int getFileCreateModeFlag(FileCreateMode mode);
// enum FileCreateMode }}}
enum FileFlushScope { // {{{
    GlobalFileScope = H5F_SCOPE_GLOBAL
  , LocalFileScope = H5F_SCOPE_LOCAL
}; // }}}
// enum FileOpenMode {{{
enum FileOpenMode { OpenReadOnly, OpenReadWrite };

unsigned int getFileOpenModeFlag(FileOpenMode mode);
// enum FileOpenMode }}}
enum FillMode { // {{{
    AlwaysFillUponAllocation = H5D_FILL_TIME_ALLOC
  , OnlyFillUponAllocationIfUserDefinedValue = H5D_FILL_TIME_IFSET
  , NeverFill = H5D_FILL_TIME_NEVER
}; // }}}
enum FillValueStatus { // {{{
    FillValueUndefined = H5D_FILL_VALUE_UNDEFINED
  , FillValueLibraryDefault = H5D_FILL_VALUE_DEFAULT
  , FillValueUserDefined = H5D_FILL_VALUE_USER_DEFINED
}; // }}}
enum LinkCreationOrderTracking { // {{{
    DontTrackLinkCreationOrder = 0u
  , TrackLinkCreationOrder = H5P_CRT_ORDER_TRACKED
  , TrackAndIndexLinksBasedOnCreationOrder = H5P_CRT_ORDER_TRACKED | H5P_CRT_ORDER_INDEXED
}; // }}}
enum ScaleMethod { // {{{
    ScaleFloatingPointWithVariableBits = H5Z_SO_FLOAT_DSCALE
  , ScaleFloatingPointWithFixedBits = H5Z_SO_FLOAT_ESCALE
  , ScaleInteger = H5Z_SO_INT
}; // }}}
enum SpaceAllocationStatus { // {{{
    SpaceNotAllocated = H5D_SPACE_STATUS_NOT_ALLOCATED
  , SpaceFullyAllocated = H5D_SPACE_STATUS_ALLOCATED
  , SpacePartiallyAllocated = H5D_SPACE_STATUS_PART_ALLOCATED
}; // }}}
enum SZIPCodingMethod { // {{{
    SZIPEntropyCodingMethod = H5_SZIP_EC_OPTION_MASK
  , SZIPNearestNeighborCodingMethod = H5_SZIP_NN_OPTION_MASK
}; // }}}
// Enumerations }}}

}

#endif
