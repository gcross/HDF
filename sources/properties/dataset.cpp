//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2159: * @file dataset.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2160: ** << License >>
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
//@+node:gcross.20110602092541.2161: ** << Includes >>
#include "properties/dataset.hpp"

#include <boost/format.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110602092541.2162: ** << Usings >>
using boost::format;

using std::string;
using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110526194358.1972: ** Exception
//@+node:gcross.20110526194358.1973: *3* NoSuchFilterException
NoSuchFilterException::NoSuchFilterException(string const& name)
  : Exception((format("No filter named '%1%' was added.'") % name).str())
  , name(name)
{}

NoSuchFilterException::~NoSuchFilterException() throw() {}
//@+node:gcross.20110602092541.2163: ** Properties
//@+node:gcross.20110526150836.1970: *3* DatasetAccessProperties
DatasetAccessProperties::DatasetAccessProperties()
  : Properties(assertSuccess("creating dataset access properties",H5Pcreate(H5P_DATASET_ACCESS)))
{}

//@+others
//@-others
//@+node:gcross.20110526150836.1966: *3* DatasetCreationProperties
DatasetCreationProperties::DatasetCreationProperties()
  : Properties(assertSuccess("creating dataset creation properties",H5Pcreate(H5P_DATASET_CREATE)))
{}

//@+others
//@+node:gcross.20110528133907.2064: *4* allocation mode
DatasetCreationProperties DatasetCreationProperties::setAllocationMode(AllocationMode allocation_mode) {
    assertSuccess(
        "setting fill time (mode)",
        H5Pset_alloc_time(
            getId(),
            static_cast<H5D_alloc_time_t>(allocation_mode)
        )
    );
    return *this;
}

AllocationMode DatasetCreationProperties::getAllocationMode() const {
    H5D_alloc_time_t allocation_mode;
    assertSuccess(
        "getting dataset fill value status",
        H5Pget_alloc_time(
            getId(),
            &allocation_mode
        )
    );
    return static_cast<AllocationMode>(allocation_mode);
}
//@+node:gcross.20110526194358.1941: *4* chunk
DatasetCreationProperties DatasetCreationProperties::setChunkSize(hsize_t const chunk_size) const {
    return setChunkSizes(1,&chunk_size);
}

DatasetCreationProperties DatasetCreationProperties::setChunkSizes(unsigned int rank, hsize_t const* chunk_sizes) const {
    assertSuccess(
        "setting dataset chunk sizes",
        H5Pset_chunk(getId(),rank,chunk_sizes)
    );
    return *this;
}

vector<hsize_t> DatasetCreationProperties::getChunkSizes() const {
    unsigned int rank =
        assertSuccess(
            "getting chunk size rank",
            H5Pget_chunk(getId(),0,NULL)
        );
    vector<hsize_t> chunk_sizes(rank);
    if(rank > 0)
        assertSuccess(
            "getting chunk sizes",
            H5Pget_chunk(getId(),rank,&chunk_sizes.front())
        );
    return chunk_sizes;
}
//@+node:gcross.20110528133907.2056: *4* fill mode
DatasetCreationProperties DatasetCreationProperties::setFillMode(FillMode fill_mode) {
    assertSuccess(
        "setting fill time (mode)",
        H5Pset_fill_time(
            getId(),
            static_cast<H5D_fill_time_t>(fill_mode)
        )
    );
    return *this;
}

FillMode DatasetCreationProperties::getFillMode() const {
    H5D_fill_time_t fill_mode;
    assertSuccess(
        "getting dataset fill value status",
        H5Pget_fill_time(
            getId(),
            &fill_mode
        )
    );
    return static_cast<FillMode>(fill_mode);
}
//@+node:gcross.20110527143225.1992: *4* fill value
DatasetCreationProperties DatasetCreationProperties::setFillValue(Datatype const& datatype, void const* value) const {
    assertSuccess(
        "setting dataset fill value",
        H5Pset_fill_value(
            getId(),
            datatype.getDatatypeId(),
            value
        )
    );
    return *this;
}

void DatasetCreationProperties::getFillValue(Datatype const& datatype, void* value) const {
    assertSuccess(
        "setting dataset fill value",
        H5Pget_fill_value(
            getId(),
            datatype.getDatatypeId(),
            value
        )
    );
}

FillValueStatus DatasetCreationProperties::getFillValueStatus() const {
    H5D_fill_value_t fill_value_status;
    assertSuccess(
        "getting dataset fill value status",
        H5Pfill_value_defined(
            getId(),
            &fill_value_status
        )
    );
    return static_cast<FillValueStatus>(fill_value_status);
}
//@+node:gcross.20110528133907.2025: *4* filter






//@+node:gcross.20110528133907.2070: *5* allAddedFiltersAreAvailable
bool DatasetCreationProperties::allAddedFiltersAreAvailable() const {
    return assertSuccess(
        "checking that all added filters are available",
        H5Pall_filters_avail(getId())
    ) == 1;
}
//@+node:gcross.20110528133907.2067: *5* appendFilter
DatasetCreationProperties DatasetCreationProperties::appendFilter(Filter const& filter) const {
    assertSuccess(
        "adding filter",
        H5Pset_filter(
            getId(),
            filter.getFilterId(),
            filter.getFlags(),
            filter.getNumberOfParameters(),
            filter.getParameterData()
        )
    );
    return *this;
}
//@+node:gcross.20110528133907.2068: *5* getFilterAtIndex
std::auto_ptr<Filter> DatasetCreationProperties::getFilterAtIndex(unsigned int index) const {
    size_t number_of_parameters = 0;
    unsigned int flags, filter_config;
    assertSuccess(
        "getting filter (by index)",
        H5Pget_filter(
            getId(),
            index,
            &flags,
            &number_of_parameters, NULL,
            0, NULL,
            &filter_config
        )
    );
    vector<unsigned int> parameters(number_of_parameters);
    H5Z_filter_t filter_id = assertSuccess(
        "getting filter (by index)",
        H5Pget_filter(
            getId(),
            index,
            &flags,
            &number_of_parameters, &parameters.front(),
            0, NULL,
            &filter_config
        )
    );
    return Filter::construct(filter_id,parameters,flags & H5Z_FLAG_OPTIONAL);
}
//@+node:gcross.20110528133907.2069: *5* getFilterWithId
std::auto_ptr<Filter> DatasetCreationProperties::getFilterWithId(H5Z_filter_t filter_id) const {
    size_t number_of_parameters = 0;
    unsigned int flags, filter_config;
    assertSuccess(
        "getting filter (by index)",
        H5Pget_filter_by_id(
            getId(),
            filter_id,
            &flags,
            &number_of_parameters, NULL,
            0, NULL,
            &filter_config
        )
    );
    vector<unsigned int> parameters(number_of_parameters);
    assertSuccess(
        "getting filter (by index)",
        H5Pget_filter_by_id(
            getId(),
            filter_id,
            &flags,
            &number_of_parameters, &parameters.front(),
            0, NULL,
            &filter_config
        )
    );
    return Filter::construct(filter_id,parameters,flags & H5Z_FLAG_OPTIONAL);
}
//@+node:gcross.20110528133907.2072: *5* modifyFilter
void DatasetCreationProperties::modifyFilter(Filter const& filter) const {
    assertSuccess(
        "modifying filter",
        H5Pmodify_filter(
            getId(),
            filter.getFilterId(),
            filter.getFlags(),
            filter.getNumberOfParameters(),
            filter.getParameterData()
        )
    );
}
//@+node:gcross.20110528133907.2071: *5* removeFilterWithId
void DatasetCreationProperties::removeFilterWithId(H5Z_filter_t filter_id) const {
    assertSuccess(
        "removing filter",
        H5Premove_filter(
            getId(),
            filter_id
        )
    );
}
//@+node:gcross.20110526194358.1955: *4* layout
DatasetCreationProperties DatasetCreationProperties::setLayout(DatasetLayout layout) const {
    assertSuccess(
        "setting dataset layout",
        H5Pset_layout(getId(),static_cast<H5D_layout_t>(layout))
    );
    return *this;
}

DatasetLayout DatasetCreationProperties::getLayout() const {
    return static_cast<DatasetLayout>(
        assertSuccess(
            "getting dataset layout",
            H5Pget_layout(getId())
        )
    );
}
//@-others
//@+node:gcross.20110526150836.1971: *3* DatasetTransferProperties
DatasetTransferProperties::DatasetTransferProperties()
  : Properties(assertSuccess("creating dataset transfer properties",H5Pcreate(H5P_DATASET_XFER)))
{}
//@-others

}
//@-leo
