// Includes {{{
#include "dataset.hpp"

#include <boost/make_shared.hpp>
// Includes }}}

// Usings {{{
using boost::optional;
using boost::make_shared;

using std::vector;
// Usings }}}

namespace HDF {

// class Dataset {{{
//      Constructors {{{
Dataset::Dataset(
    Location const& location
  , optional<DatasetAccessProperties const&> const& optional_access_properties
) // {{{
  : Object(
        location.getFile(),
        assertSuccess(
            "opening dataset",
            H5Dopen2(
                location.getParentId(),
                location.getNameAsCStr(),
                getOptionalPropertiesId(optional_access_properties)
            )
        ),
        H5Dclose
    )
{}  // }}}

Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , Dataspace const& dataspace
  , optional<void const*> const& optional_data
  , optional<DatasetCreationProperties const&> const& optional_creation_properties
  , optional<DatasetAccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
) // {{{
  : Object(location->getFile(),Identity::Ptr())
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
} // }}}

Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , unsigned int rank
  , hsize_t const* dimensions
  , optional<void const*> const& optional_data
  , optional<DatasetCreationProperties const&> const& optional_creation_properties
  , optional<DatasetAccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
) // {{{
  : Object(location->getFile(),Identity::Ptr())
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
} // }}}

Dataset::Dataset(
    CreateAt<Location const> location
  , Datatype const& datatype
  , vector<hsize_t> const& dimensions
  , optional<void const*> const& optional_data
  , optional<DatasetCreationProperties const&> const& optional_creation_properties
  , optional<DatasetAccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
) // {{{
  : Object(location->getFile(),Identity::Ptr())
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
} // }}}

void Dataset::createAndInitialize(
    Location const& location
  , Datatype const& datatype
  , Dataspace const& dataspace
  , optional<void const*> const& optional_data
  , optional<DatasetCreationProperties const&> const& optional_creation_properties
  , optional<DatasetAccessProperties const&> const& optional_access_properties
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
) { // {{{
    identity =
        make_shared<Identity>(
            assertSuccess(
                "creating dataset",
                H5Dcreate2(
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
} // }}}
//      Constructors }}}
//      Data access {{{
void Dataset::read(
    void* data
  , Datatype const& datatype
  , optional<Dataspace const&> const& optional_memory_dataspace
  , optional<Dataspace const&> const& optional_dataset_dataspace
  , optional<DatasetTransferProperties const&> const& optional_transfer_properties
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
  , optional<DatasetTransferProperties const&> const& optional_transfer_properties
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
//      Data access }}}
//      Informational {{{
vector<hsize_t> Dataset::dimensions() const { // {{{
    return Dataspace(*this).dimensions();
} // }}}
vector<hsize_t> Dataset::dimensionsWithAssertedRank(unsigned int expected_rank) const { // {{{
    return Dataspace(*this).dimensionsWithAssertedRank(expected_rank);
} // }}}
DatasetAccessProperties Dataset::getCopyOfAccessProperties() const { // {{{
    return DatasetAccessProperties(assertSuccess(
        "getting dataset access properties",
        H5Dget_access_plist(getId())
    ));
} // }}}
DatasetCreationProperties Dataset::getCopyOfCreationProperties() const { // {{{
    return DatasetCreationProperties(assertSuccess(
        "getting dataset creation properties",
        H5Dget_create_plist(getId())
    ));
} // }}}
SpaceAllocationStatus Dataset::getSpaceAllocationStatus() const { // {{{
    H5D_space_status_t status;
    assertSuccess(
        "getting dataset space allocation status",
        H5Dget_space_status(getId(),&status)
    );
    return static_cast<SpaceAllocationStatus>(status);
} // }}}
size_t Dataset::getStorageSize() const { // {{{
    return assertSuccess(
        "getting dataset storage size",
        H5Dget_storage_size(getId())
    );
} // }}}
unsigned int Dataset::rank() const { return Dataspace(*this).rank(); } 
unsigned int Dataset::size() const { return Dataspace(*this).size(); }
//      Informational }}}
//      Resizing {{{
void Dataset::resize(hsize_t const* dimensions) const {
    assertSuccess(
        "resizing dataset",
        H5Dset_extent(getId(),dimensions)
    );
}
void Dataset::resize(hsize_t const dimension) const {
    resize(&dimension);
}
//      Resizing }}}
// class Dataset }}}

}
