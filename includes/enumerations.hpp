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
//@+node:gcross.20110528133907.2060: *3* AllocationMode
enum AllocationMode {
    DefaultAllocationModeForStorage = H5D_ALLOC_TIME_DEFAULT
  , AllocateAllSpaceWhenDatasetIsCreated = H5D_ALLOC_TIME_EARLY
  , AllocateSpaceIncrementallyAsNeeded = H5D_ALLOC_TIME_INCR
  , AllocateAllSpaceOnFirstWrite = H5D_ALLOC_TIME_LATE
};
//@+node:gcross.20110526150836.1952: *3* CharacterEncoding
enum CharacterEncoding {
    ASCIIEncoding = H5T_CSET_ASCII
  , UTF8Encoding = H5T_CSET_UTF8
};
//@+node:gcross.20110526194358.1952: *3* DatasetLayout
enum DatasetLayout {
    CompactDatasetLayout = H5D_COMPACT
  , ContiguousDatasetLayout = H5D_CONTIGUOUS
  , ChunkedDatasetLayout = H5D_CHUNKED
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
//@+node:gcross.20110528133907.2057: *3* FillMode
enum FillMode {
    AlwaysFillUponAllocation = H5D_FILL_TIME_ALLOC
  , OnlyFillUponAllocationIfUserDefinedValue = H5D_FILL_TIME_IFSET
  , NeverFill = H5D_FILL_TIME_NEVER
};
//@+node:gcross.20110528133907.2052: *3* FillValueStatus
enum FillValueStatus {
    FillValueUndefined = H5D_FILL_VALUE_UNDEFINED
  , FillValueLibraryDefault = H5D_FILL_VALUE_DEFAULT
  , FillValueUserDefined = H5D_FILL_VALUE_USER_DEFINED
};
//@+node:gcross.20110602092541.2060: *3* LinkCreationOrderTracking
enum LinkCreationOrderTracking {
    DontTrackLinkCreationOrder = 0u
  , TrackLinkCreationOrder = H5P_CRT_ORDER_TRACKED
  , TrackAndIndexLinksBasedOnCreationOrder = H5P_CRT_ORDER_TRACKED | H5P_CRT_ORDER_INDEXED
};
//@+node:gcross.20110526194358.2003: *3* ScaleMethod
enum ScaleMethod {
    ScaleFloatingPointWithVariableBits = H5Z_SO_FLOAT_DSCALE
  , ScaleFloatingPointWithFixedBits = H5Z_SO_FLOAT_ESCALE
  , ScaleInteger = H5Z_SO_INT
};
//@+node:gcross.20110602121059.2134: *3* SpaceAllocationStatus
enum SpaceAllocationStatus {
    SpaceNotAllocated = H5D_SPACE_STATUS_NOT_ALLOCATED
  , SpaceFullyAllocated = H5D_SPACE_STATUS_ALLOCATED
  , SpacePartiallyAllocated = H5D_SPACE_STATUS_PART_ALLOCATED
};
//@+node:gcross.20110527143225.1984: *3* SZIPCodingMethod
enum SZIPCodingMethod {
    SZIPEntropyCodingMethod = H5_SZIP_EC_OPTION_MASK
  , SZIPNearestNeighborCodingMethod = H5_SZIP_NN_OPTION_MASK
};
//@-others

}

#endif
//@-leo
