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
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1475: ** << Usings >>
using boost::optional;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1478: ** class Properties
//@+node:gcross.20110520211700.1479: *3* Constructors/Destructors
Properties::Properties(hid_t id) : Identifiable(id,H5Pclose) {}

Properties::Properties() {}
//@+node:gcross.20110520211700.1501: ** Properties
LinkAccessProperties::LinkAccessProperties()
  : Properties(assertSuccess("creating link access properties",H5Pcreate(H5P_LINK_ACCESS)))
{}
//@+node:gcross.20110525201928.3116: *3* CreateMissingIntermediateGroupsPropertyBase
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

DatasetCreationProperties DatasetCreationProperties::setChunk(hsize_t const chunk_size) const {
    return setChunk(1,&chunk_size);
}

DatasetCreationProperties DatasetCreationProperties::setChunk(unsigned int rank, hsize_t const* chunk_sizes) const {
    assertSuccess(
        "setting dataset chunk sizes",
        H5Pset_chunk(getId(),rank,chunk_sizes)
    );
    return *this;
}
//@+node:gcross.20110526150836.1971: *3* DatasetTransferProperties
DatasetTransferProperties::DatasetTransferProperties()
  : Properties(assertSuccess("creating dataset transfer properties",H5Pcreate(H5P_DATASET_XFER)))
{}
//@+node:gcross.20110526150836.1977: *3* FileAccessProperties
FileAccessProperties::FileAccessProperties()
  : Properties(assertSuccess("creating file access properties",H5Pcreate(H5P_FILE_ACCESS)))
{}

FileAccessProperties FileAccessProperties::useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const {
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pset_fapl_core(getId(),increment_size_in_bytes,write_to_backing_store)
    );
    return *this;
}
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
