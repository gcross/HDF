//@+leo-ver=5-thin
//@+node:gcross.20110523113700.1804: * @file dataset.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110523113700.1806: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_DATASET_HPP
#define HDFPP_IMPLEMENTATION_DATASET_HPP

//@+<< Includes >>
//@+node:gcross.20110523113700.1805: ** << Includes >>
#include "dataspace.hpp"
#include "datatype.hpp"
#include "object.hpp"
#include "parameters.hpp"
#include "properties/dataset.hpp"
#include "properties/link.hpp"

#include <boost/optional.hpp>
#include <boost/range/value_type.hpp>
#include <vector>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110523113700.1807: ** class Dataset
class Dataset: public Object {
    //@+others
    //@+node:gcross.20110523113700.1808: *3* Constructors
    public:

    Dataset(
        Location const& location
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
    );

    Dataset(
        CreateAt<Location const> location
      , Datatype const& datatype
      , Dataspace const& dataspace
      , boost::optional<void const*> const& optional_data = boost::none
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    );

    Dataset(
        CreateAt<Location const> location
      , Datatype const& datatype
      , unsigned int rank
      , hsize_t const* dimensions
      , boost::optional<void const*> const& optional_data = boost::none
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    );

    Dataset(
        CreateAt<Location const> location
      , Datatype const& datatype
      , std::vector<hsize_t> const& dimensions
      , boost::optional<void const*> const& optional_data = boost::none
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    );

    template<typename T>
    Dataset(
        CreateAt<Location const> location
      , unsigned int rank
      , hsize_t const* dimensions
      , T const* data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    )
      : Object(location->getFile(),Identity::Ptr())
    {
        createAndInitialize(
            *location,
            datatypeOf<T>::get(),
            Dataspace(rank,dimensions),
            data,
            optional_creation_properties,
            optional_access_properties,
            optional_link_creation_properties
        );
    }


    template<typename Dimensions, typename T>
    Dataset(
        CreateAt<Location const> location
      , std::vector<hsize_t> const& dimensions
      , T const* data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    )
      : Object(location->getFile(),Identity::Ptr())
    {
        createAndInitialize(
            *location,
            datatypeOf<T>::get(),
            Dataspace(dimensions),
            data,
            optional_creation_properties,
            optional_access_properties,
            optional_link_creation_properties
        );
    }

    template<typename Dimensions, typename T>
    Dataset(
        CreateAt<Location const> location
      , RangeOf<Dimensions> dimensions
      , T const* data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    )
      : Object(location->getFile(),Identity::Ptr())
    {
        createAndInitialize(
            *location,
            datatypeOf<T>::get(),
            Dataspace(dimensions),
            data,
            optional_creation_properties,
            optional_access_properties,
            optional_link_creation_properties
        );
    }

    template<typename T>
    Dataset(
        CreateAt<Location const> location
      , hsize_t const dimension
      , T const* data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    )
      : Object(location->getFile(),Identity::Ptr())
    {
        createAndInitialize(
            *location,
            datatypeOf<T>::get(),
            Dataspace(1,&dimension),
            data,
            optional_creation_properties,
            optional_access_properties,
            optional_link_creation_properties
        );
    }

    template<typename DataRange>
    Dataset(
        CreateAt<Location const> location
      , RangeOf<DataRange> data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties = boost::none
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
    )
      : Object(location->getFile(),Identity::Ptr())
    {
        typedef typename boost::range_value<DataRange>::type T;
        TemporaryArray<T> array(*data);
        createAndInitialize(
            *location,
            datatypeOf<T>::get(),
            Dataspace(array.size),
            array.data.get(),
            optional_creation_properties,
            optional_access_properties,
            optional_link_creation_properties
        );
    }

    protected:

    void createAndInitialize(
        Location const& location
      , Datatype const& datatype
      , Dataspace const& dataspace
      , boost::optional<void const*> const& optional_data
      , boost::optional<DatasetCreationProperties const&> const& optional_creation_properties
      , boost::optional<DatasetAccessProperties const&> const& optional_access_properties
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties
    );
    //@+node:gcross.20110523113700.1826: *3* Data access
    public:

    void read(
        void* data
      , Datatype const& datatype
      , boost::optional<Dataspace const&> const& optional_memory_dataspace = boost::none
      , boost::optional<Dataspace const&> const& optional_dataset_dataspace = boost::none
      , boost::optional<DatasetTransferProperties const&> const& optional_transfer_properties = boost::none
    ) const;

    template<typename T> void read(
        T* data
      , boost::optional<Dataspace const&> const& optional_memory_dataspace = boost::none
      , boost::optional<Dataspace const&> const& optional_dataset_dataspace = boost::none
      , boost::optional<DatasetTransferProperties const&> const& optional_transfer_properties = boost::none
    ) const {
        read(data,datatypeOf<T>::get(),optional_memory_dataspace,optional_dataset_dataspace,optional_transfer_properties);
    }

    template<typename T> std::vector<T> readVector(
        boost::optional<Dataspace const&> const& optional_dataset_dataspace = boost::none
      , boost::optional<DatasetTransferProperties const&> const& optional_transfer_properties = boost::none
    ) const {
        std::vector<T> data(
            optional_dataset_dataspace
                ? optional_dataset_dataspace->selectedSize()
                : size()
        );
        read(&data.front(),boost::none,optional_dataset_dataspace,optional_transfer_properties);
        return data;
    }

    void write(
        void const* data
      , Datatype const& datatype
      , boost::optional<Dataspace const&> const& optional_memory_dataspace = boost::none
      , boost::optional<Dataspace const&> const& optional_dataset_dataspace = boost::none
      , boost::optional<DatasetTransferProperties const&> const& optional_transfer_properties = boost::none
    ) const;

    template<typename T> void write(
        T const* data
      , boost::optional<Dataspace const&> const& optional_memory_dataspace = boost::none
      , boost::optional<Dataspace const&> const& optional_dataset_dataspace = boost::none
      , boost::optional<DatasetTransferProperties const&> const& optional_transfer_properties = boost::none
    ) const {
        write(data,datatypeOf<T>::get(),optional_memory_dataspace,optional_dataset_dataspace,optional_transfer_properties);
    }
    //@+node:gcross.20110523113700.2383: *3* Informational
    public:

    std::vector<hsize_t> dimensions() const;
    std::vector<hsize_t> dimensionsWithAssertedRank(unsigned int expected_rank) const;
    unsigned int rank() const;
    unsigned int size() const;

    SpaceAllocationStatus getSpaceAllocationStatus() const;

    DatasetAccessProperties getCopyOfAccessProperties() const;
    DatasetCreationProperties getCopyOfCreationProperties() const;

    size_t getStorageSize() const;
    //@+node:gcross.20110523113700.2370: *3* Resizing
    public:

    void resize(hsize_t const* dimensions) const;
    void resize(hsize_t dimension) const;
    template<typename Dimensions> void resize(RangeOf<Dimensions> dimensions) const {
        HSizeArray dims(*dimensions);
        resize(dims);
    }
    //@-others
};
//@-others

}

#endif
//@-leo
