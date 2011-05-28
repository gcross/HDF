//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1472: * @file properties.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520211700.1473: ** << License >>
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
//@+node:gcross.20110520211700.1474: ** << Includes >>
#include "error.hpp"
#include "properties.hpp"

#include <boost/format.hpp>
#include <boost/variant/get.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1475: ** << Usings >>
using boost::format;
using boost::get;
using boost::optional;
using boost::variant;

using std::make_pair;
using std::pair;
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
//@+node:gcross.20110520211700.1478: ** class Properties
//@+node:gcross.20110520211700.1479: *3* Constructors/Destructors
Properties::Properties(hid_t id) : Identifiable(id,H5Pclose) {}

Properties::Properties() {}
//@+node:gcross.20110526194358.1961: ** Shared properties
//@+node:gcross.20110525201928.3116: *3* CreateMissingIntermediateGroupsProperty
CreateMissingIntermediateGroupsPropertyBase::CreateMissingIntermediateGroupsPropertyBase() {}

void CreateMissingIntermediateGroupsPropertyBase::setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups) const {
    assertSuccess(
        "setting create intermediate groups property",
        H5Pset_create_intermediate_group(
            getId(),
            create_missing_intermediate_groups
        )
    );
}

bool CreateMissingIntermediateGroupsPropertyBase::getCreateMissingIntermediateGroups() const {
    unsigned int create_missing_intermediate_groups;
    assertSuccess(
        "getting create intermediate groups property",
        H5Pget_create_intermediate_group(
            getId(),
            &create_missing_intermediate_groups
        )
    );
    return create_missing_intermediate_groups==1;
}
//@+node:gcross.20110526194358.1963: *3* UseGZIPCompressionProperty
UseGZIPCompressionPropertyBase::UseGZIPCompressionPropertyBase() {}

void UseGZIPCompressionPropertyBase::useGZIPCompression(unsigned int level) const {
    assertSuccess(
        "setting deflate compression",
        H5Pset_deflate(getId(),level)
    );
};
//@+node:gcross.20110520211700.1501: ** Properties
LinkAccessProperties::LinkAccessProperties()
  : Properties(assertSuccess("creating link access properties",H5Pcreate(H5P_LINK_ACCESS)))
{}
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
//@+node:gcross.20110526194358.1975: *4* filter
DatasetFilter DatasetCreationProperties::getFilterInformation(
    variant<unsigned int,DatasetFilter> id
  , unsigned int& flags
  , size_t& parameters_size
  , unsigned int* parameters
  , size_t name_size
  , char* name
  , unsigned int& filter_config
) const {
    DatasetFilter filter;
    switch(id.which()) {
        case 0:
            filter = static_cast<DatasetFilter>(
                assertSuccess(
                    "getting filter information (by index)",
                    H5Pget_filter(
                        getId(),
                        get<unsigned int>(id),
                        &flags,
                        &parameters_size,
                        parameters,
                        name_size,
                        name,
                        &filter_config
                    )
                )
            );
            break;
        case 1:
            filter = get<DatasetFilter>(id);
            assertSuccess(
                "getting filter information (by id)",
                H5Pget_filter_by_id(
                    getId(),
                    static_cast<H5Z_filter_t>(filter),
                    &flags,
                    &parameters_size,
                    parameters,
                    name_size,
                    name,
                    &filter_config
                )
            );
            break;
    }
    return filter;
}

DatasetFilter DatasetCreationProperties::getFilterInformation(
    variant<unsigned int,DatasetFilter> id
  , optional<vector<unsigned int>&> const& optional_parameters
  , optional<unsigned int&> const& optional_flags
  , optional<unsigned int&> const& optional_filter_config
  , optional<pair<size_t,char*> > const& optional_name
) const {
    unsigned int flags, filter_config;
    size_t number_of_parameters = optional_parameters ? optional_parameters->size() : 0;
    DatasetFilter filter = getFilterInformation(
        id,
        optional_flags.get_value_or(flags),
        number_of_parameters,
        optional_parameters ? &optional_parameters->front() : NULL,
        optional_name ? optional_name->first : 0,
        optional_name ? optional_name->second : NULL,
        optional_filter_config.get_value_or(filter_config)
    );
    if(optional_parameters) {
        vector<unsigned int>& parameters = *optional_parameters;
        bool was_too_small = parameters.size() < number_of_parameters;
        parameters.resize(number_of_parameters);
        if(was_too_small) {
            getFilterInformation(
                id,
                flags,
                number_of_parameters,
                &parameters.front(),
                0,
                NULL,
                filter_config
            );
        }
    }
    return filter;
}

vector<unsigned int> DatasetCreationProperties::getFilterParameters(
    variant<unsigned int,DatasetFilter> id
  , unsigned int expected_number
) const {
    vector<unsigned int> parameters(expected_number);
    getFilterInformation(id,parameters);
    return parameters;
}

DatasetFilter DatasetCreationProperties::getFilterTypeAtIndex(
    unsigned int index
) const {
    return getFilterInformation(index);
}
//@+node:gcross.20110526194358.1986: *5* Fletcher32
DatasetCreationProperties DatasetCreationProperties::addFletcher32ChecksumFilter() const {
    assertSuccess(
        "adding Fletcher32 checksum filter",
        H5Pset_fletcher32(getId())
    );
    return *this;
}
//@+node:gcross.20110526194358.1977: *5* GZIP
DatasetCreationProperties DatasetCreationProperties::addGZIPCompressionFilter(unsigned int level) const {
    return useGZIPCompression(level);
}

unsigned int DatasetCreationProperties::getGZIPCompressionLevel(optional<unsigned int> const& optional_index) const {
    if(optional_index)
        return getFilterParameters(*optional_index,1)[0];
    else
        return getFilterParameters(GZIPFilter,1)[0];
}
//@+node:gcross.20110526194358.1998: *5* NBit
DatasetCreationProperties DatasetCreationProperties::addNBitCompressionFilter() const {
    assertSuccess(
        "adding NBit checksum filter",
        H5Pset_nbit(getId())
    );
    return *this;
}
//@+node:gcross.20110526194358.2002: *5* ScaleOffset
DatasetCreationProperties DatasetCreationProperties::addScaleOffsetCompressionFilter(
    ScaleOperationType scale_type
  , unsigned int scale_factor
) const {
    assertSuccess(
        "adding scale offset checksum filter",
        H5Pset_scaleoffset(getId(),static_cast<H5Z_SO_scale_type_t>(scale_type),scale_factor)
    );
    return *this;
}

pair<ScaleOperationType,unsigned int> DatasetCreationProperties::getScaleOffsetFilterParameters(
    optional<unsigned int> const& optional_index
) const {
    vector<unsigned int> parameters(2);
    if(optional_index) {
        getFilterInformation(*optional_index,parameters);
    } else {
        getFilterInformation(ScaleOffsetFilter,parameters);
    }
    return make_pair(static_cast<ScaleOperationType>(parameters[0]),parameters[1]);
}
//@+node:gcross.20110526194358.1982: *5* Shuffle
DatasetCreationProperties DatasetCreationProperties::addShuffleFilter() const {
    assertSuccess(
        "adding shuffle filter",
        H5Pset_shuffle(getId())
    );
    return *this;
}
//@+node:gcross.20110527143225.1983: *5* SZIP
DatasetCreationProperties DatasetCreationProperties::addSZIPCompressionFilter(
    SZIPCodingMethod coding_method
  , unsigned int pixels_per_block
) const {
    assertSuccess(
        "adding SZIP checksum filter",
        H5Pset_szip(getId(),static_cast<unsigned int>(coding_method),pixels_per_block)
    );
    return *this;
}

pair<SZIPCodingMethod,unsigned int> DatasetCreationProperties::getSZIPFilterParameters(
    optional<unsigned int> const& optional_index
) const {
    vector<unsigned int> parameters(2);
    if(optional_index) {
        getFilterInformation(*optional_index,parameters);
    } else {
        getFilterInformation(SZIPFilter,parameters);
    }
    return make_pair(static_cast<SZIPCodingMethod>(parameters[0]),parameters[1]);
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
//@+node:gcross.20110526150836.1977: *3* FileAccessProperties
FileAccessProperties::FileAccessProperties()
  : Properties(assertSuccess("creating file access properties",H5Pcreate(H5P_FILE_ACCESS)))
{}

//@+others
//@+node:gcross.20110526194358.1938: *4* CoreDriver
FileAccessProperties FileAccessProperties::useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const {
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pset_fapl_core(getId(),increment_size_in_bytes,write_to_backing_store)
    );
    return *this;
}

void FileAccessProperties::getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const {
    hbool_t write_to_backing_store_temp;
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pget_fapl_core(getId(),&increment_size_in_bytes,&write_to_backing_store_temp)
    );
    write_to_backing_store = write_to_backing_store_temp;
}

pair<size_t,bool> FileAccessProperties::getCoreDriverSettings() const {
    pair<size_t,bool> result;
    getCoreDriverSettings(result.first,result.second);
    return result;
}
//@-others
//@+node:gcross.20110526150836.1979: *3* FileCreationProperties
FileCreationProperties::FileCreationProperties()
  : Properties(assertSuccess("creating file creation properties",H5Pcreate(H5P_FILE_CREATE)))
{}
//@+node:gcross.20110525201928.3099: *3* LinkCreationProperties
LinkCreationProperties::LinkCreationProperties()
  : Properties(assertSuccess("creating link creation properties",H5Pcreate(H5P_LINK_CREATE)))
{}

LinkCreationProperties LinkCreationProperties::setCharacterEncoding(CharacterEncoding encoding) const {
    assertSuccess(
        "setting character encoding property",
        H5Pset_char_encoding(
            getId(),
            static_cast<H5T_cset_t>(encoding)
        )
    );
    return *this;
}

CharacterEncoding LinkCreationProperties::getCharacterEncoding() const {
    H5T_cset_t id;
    assertSuccess(
        "getting character encoding property",
        H5Pget_char_encoding(
            getId(),
            &id
        )
    );
    return static_cast<CharacterEncoding>(id);
}
//@-others

}
//@-leo
