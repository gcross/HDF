//@+leo-ver=5-thin
//@+node:gcross.20110523113700.1813: * @file dataset.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110523113700.1814: ** << License >>
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
//@+node:gcross.20110523113700.1815: ** << Includes >>
#include "dataset.hpp"

#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110523113700.1816: ** << Usings >>
using boost::optional;
using boost::make_shared;

using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110523113700.1819: ** class Dataset
//@+node:gcross.20110523113700.1820: *3* Constructors
Dataset::Dataset(
    Location const& location
  , optional<AccessProperties const&> const& optional_access_properties
)
  : Object(
        location.getFileIdentity(),
        assertSuccess(
            "opening dataset",
            H5Dopen(
                location.getParentId(),
                location.getNameAsCStr(),
                getOptionalPropertiesId(optional_access_properties)
            )
        ),
        H5Dclose
    )
{}


Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , Dataspace const& dataspace
  , optional<void const*> const& optional_data
  , optional<CreationProperties const&> const& optional_creation_properties
  , optional<AccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
)
  : Object(location->getFileIdentity(),Identity::Ptr())
{
    createAndInitialize(
        *location,
        datatype,
        dataspace,
        optional_data,
        optional_creation_properties,
        optional_access_properties,
        optional_link_creation_properties
    );
}

Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , unsigned int rank
  , hsize_t const* dimensions
  , optional<void const*> const& optional_data
  , optional<CreationProperties const&> const& optional_creation_properties
  , optional<AccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
)
  : Object(location->getFileIdentity(),Identity::Ptr())
{
    createAndInitialize(
        *location,
        datatype,
        Dataspace(rank,dimensions),
        optional_data,
        optional_creation_properties,
        optional_access_properties,
        optional_link_creation_properties
    );
}

Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , vector<hsize_t> const& dimensions
  , optional<void const*> const& optional_data
  , optional<CreationProperties const&> const& optional_creation_properties
  , optional<AccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
)
  : Object(location->getFileIdentity(),Identity::Ptr())
{
    createAndInitialize(
        *location,
        datatype,
        Dataspace(dimensions),
        optional_data,
        optional_creation_properties,
        optional_access_properties,
        optional_link_creation_properties
    );
}

void Dataset::createAndInitialize(
    Location const& location
  , Datatype const& datatype
  , Dataspace const& dataspace
  , optional<void const*> const& optional_data
  , optional<CreationProperties const&> const& optional_creation_properties
  , optional<AccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
) {
    identity =
        make_shared<Identity>(
            assertSuccess(
                "creating dataset",
                H5Dcreate(
                    location.getParentId(),
                    location.getNameAsCStr(),
                    datatype.getDatatypeId(),
                    dataspace.getId(),
                    getOptionalPropertiesId(optional_link_creation_properties),
                    getOptionalPropertiesId(optional_creation_properties),
                    getOptionalPropertiesId(optional_access_properties)
                )
            ),
            H5Dclose
        );
    if(optional_data) write(*optional_data,datatype);
}
//@+node:gcross.20110523113700.1822: *3* Data access
void Dataset::read(
    void* data
  , Datatype const& datatype
  , optional<Dataspace const&> const& optional_memory_dataspace
  , optional<Dataspace const&> const& optional_dataset_dataspace
  , optional<TransferProperties const&> const& optional_transfer_properties
) const {
    assertSuccess(
        "reading data from the dataset",
        H5Dread(
            getId(),
            datatype.getDatatypeId(),
            getOptionalDataspaceId(optional_memory_dataspace),
            getOptionalDataspaceId(optional_dataset_dataspace),
            getOptionalPropertiesId(optional_transfer_properties),
            data
        )
    );
}

void Dataset::write(
    void const* data
  , Datatype const& datatype
  , optional<Dataspace const&> const& optional_memory_dataspace
  , optional<Dataspace const&> const& optional_dataset_dataspace
  , optional<TransferProperties const&> const& optional_transfer_properties
) const {
    assertSuccess(
        "writing data to the dataset",
        H5Dwrite(
            getId(),
            datatype.getDatatypeId(),
            getOptionalDataspaceId(optional_memory_dataspace),
            getOptionalDataspaceId(optional_dataset_dataspace),
            getOptionalPropertiesId(optional_transfer_properties),
            data
        )
    );
}
//@+node:gcross.20110523113700.2385: *3* Informational
vector<hsize_t> Dataset::dimensions() const {
    return Dataspace(*this).dimensions();
}
vector<hsize_t> Dataset::dimensionsWithAssertedRank(unsigned int expected_rank) const {
    return Dataspace(*this).dimensionsWithAssertedRank(expected_rank);
}

unsigned int Dataset::rank() const { return Dataspace(*this).rank(); }
unsigned int Dataset::size() const { return Dataspace(*this).size(); }
//@+node:gcross.20110523113700.1824: *3* Nested types
Dataset::AccessProperties::AccessProperties()
  : Properties(assertSuccess("creating dataset access properties",H5Pcreate(H5P_DATASET_ACCESS)))
{}

Dataset::TransferProperties::TransferProperties()
  : Properties(assertSuccess("creating dataset transfer properties",H5Pcreate(H5P_DATASET_XFER)))
{}

//@+others
//@+node:gcross.20110524225139.1867: *4* CreationProperties
//@+node:gcross.20110524225139.1868: *5* Constructors
Dataset::CreationProperties::CreationProperties()
  : Properties(assertSuccess("creating dataset creation properties",H5Pcreate(H5P_DATASET_CREATE)))
{}
//@+node:gcross.20110524225139.1869: *5* Chunk
Dataset::CreationProperties Dataset::CreationProperties::setChunk(hsize_t const chunk_size) const {
    return setChunk(1,&chunk_size);
}

Dataset::CreationProperties Dataset::CreationProperties::setChunk(unsigned int rank, hsize_t const* chunk_sizes) const {
    assertSuccess(
        "setting dataset chunk sizes",
        H5Pset_chunk(getId(),rank,chunk_sizes)
    );
    return *this;
}
//@-others
//@+node:gcross.20110523113700.2371: *3* Resizing
void Dataset::resize(hsize_t const* dimensions) const {
    assertSuccess(
        "resizing dataset",
        H5Dset_extent(getId(),dimensions)
    );
}
void Dataset::resize(hsize_t const dimension) const {
    resize(&dimension);
}
//@-others

}
//@-leo
