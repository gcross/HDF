// Includes {{{
#include "properties/dataset.hpp"

#include <boost/format.hpp>
// Includes }}}

// Usings {{{
using boost::format;

using std::string;
using std::vector;
// Usings }}}

namespace HDF {

// Exceptions {{{
// NoSuchFilterException {{{
NoSuchFilterException::NoSuchFilterException(string const& name)
  : Exception((format("No filter named '%1%' was added.'") % name).str())
  , name(name)
{}

NoSuchFilterException::~NoSuchFilterException() throw() {}
// NoSuchFilterException }}}
// Exceptions }}}

// Properties {{{
//   dataset access {{{
DEFINE_PROPERTIES_BOILERPLATE(DatasetAccess,dataset access,DATASET_ACCESS)
//   dataset access }}}
//     dataset creation {{{
DEFINE_PROPERTIES_BOILERPLATE(DatasetCreation,dataset creation,DATASET_CREATE)

// allocation mode {{{
DatasetCreationProperties DatasetCreationProperties::setAllocationMode(AllocationMode allocation_mode) { // {{{
    assertSuccess(
        "setting fill time (mode)",
        H5Pset_alloc_time(
            getId(),
            static_cast<H5D_alloc_time_t>(allocation_mode)
        )
    );
    return *this;
} // }}}
AllocationMode DatasetCreationProperties::getAllocationMode() const { // {{{
    H5D_alloc_time_t allocation_mode;
    assertSuccess(
        "getting dataset fill value status",
        H5Pget_alloc_time(
            getId(),
            &allocation_mode
        )
    );
    return static_cast<AllocationMode>(allocation_mode);
} // }}}
// allocation mode }}}
// chunk {{{
DatasetCreationProperties DatasetCreationProperties::setChunkSize(hsize_t const chunk_size) const { // {{{
    return setChunkSizes(1,&chunk_size);
} // }}}
DatasetCreationProperties DatasetCreationProperties::setChunkSizes(unsigned int rank, hsize_t const* chunk_sizes) const { // {{{
    assertSuccess(
        "setting dataset chunk sizes",
        H5Pset_chunk(getId(),rank,chunk_sizes)
    );
    return *this;
} // }}}
vector<hsize_t> DatasetCreationProperties::getChunkSizes() const { // {{{
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
} // }}}
// chunk }}}
// fill mode {{{
DatasetCreationProperties DatasetCreationProperties::setFillMode(FillMode fill_mode) { // {{{
    assertSuccess(
        "setting fill time (mode)",
        H5Pset_fill_time(
            getId(),
            static_cast<H5D_fill_time_t>(fill_mode)
        )
    );
    return *this;
} // }}}
FillMode DatasetCreationProperties::getFillMode() const { // {{{
    H5D_fill_time_t fill_mode;
    assertSuccess(
        "getting dataset fill value status",
        H5Pget_fill_time(
            getId(),
            &fill_mode
        )
    );
    return static_cast<FillMode>(fill_mode);
} // }}}
// fill mode }}}
// fill values {{{
DatasetCreationProperties DatasetCreationProperties::setFillValue(Datatype const& datatype, void const* value) const { // {{{
    assertSuccess(
        "setting dataset fill value",
        H5Pset_fill_value(
            getId(),
            datatype.getDatatypeId(),
            value
        )
    );
    return *this;
} // }}}
void DatasetCreationProperties::getFillValue(Datatype const& datatype, void* value) const { // {{{
    assertSuccess(
        "setting dataset fill value",
        H5Pget_fill_value(
            getId(),
            datatype.getDatatypeId(),
            value
        )
    );
} // }}}
FillValueStatus DatasetCreationProperties::getFillValueStatus() const { // {{{
    H5D_fill_value_t fill_value_status;
    assertSuccess(
        "getting dataset fill value status",
        H5Pfill_value_defined(
            getId(),
            &fill_value_status
        )
    );
    return static_cast<FillValueStatus>(fill_value_status);
} // }}}
// fill values }}}
// filter {{{
bool DatasetCreationProperties::allAddedFiltersAreAvailable() const { // {{{
    return assertSuccess(
        "checking that all added filters are available",
        H5Pall_filters_avail(getId())
    ) == 1;
} // }}}
DatasetCreationProperties DatasetCreationProperties::appendFilter(Filter const& filter) const { // {{{
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
} // }}}
std::auto_ptr<Filter> DatasetCreationProperties::getFilterAtIndex(unsigned int index) const { // {{{
    size_t number_of_parameters = 0;
    unsigned int flags, filter_config;
    assertSuccess(
        "getting filter (by index)",
        H5Pget_filter2(
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
        H5Pget_filter2(
            getId(),
            index,
            &flags,
            &number_of_parameters, &parameters.front(),
            0, NULL,
            &filter_config
        )
    );
    return Filter::construct(filter_id,parameters,flags & H5Z_FLAG_OPTIONAL);
} // }}}
std::auto_ptr<Filter> DatasetCreationProperties::getFilterWithId(H5Z_filter_t filter_id) const { // {{{
    size_t number_of_parameters = 0;
    unsigned int flags, filter_config;
    assertSuccess(
        "getting filter (by index)",
        H5Pget_filter_by_id2(
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
        H5Pget_filter_by_id2(
            getId(),
            filter_id,
            &flags,
            &number_of_parameters, &parameters.front(),
            0, NULL,
            &filter_config
        )
    );
    return Filter::construct(filter_id,parameters,flags & H5Z_FLAG_OPTIONAL);
} // }}}
void DatasetCreationProperties::modifyFilter(Filter const& filter) const { // {{{
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
} // }}}
void DatasetCreationProperties::removeFilterWithId(H5Z_filter_t filter_id) const { // {{{
    assertSuccess(
        "removing filter",
        H5Premove_filter(
            getId(),
            filter_id
        )
    );
} // }}}
// filter }}}
// layout {{{
DatasetCreationProperties DatasetCreationProperties::setLayout(DatasetLayout layout) const { // {{{
    assertSuccess(
        "setting dataset layout",
        H5Pset_layout(getId(),static_cast<H5D_layout_t>(layout))
    );
    return *this;
} // }}}
DatasetLayout DatasetCreationProperties::getLayout() const { // {{{
    return static_cast<DatasetLayout>(
        assertSuccess(
            "getting dataset layout",
            H5Pget_layout(getId())
        )
    );
} // }}}
// layout }}}

//     dataset creation }}}
//     dataset transfer {{{
DEFINE_PROPERTIES_BOILERPLATE(DatasetTransfer,dataset transfer,DATASET_XFER)
//     dataset transfer }}}
// Properties }}}

}
