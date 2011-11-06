//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2072: * @file dataset.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2074: ** << License >>
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

#ifndef HDFPP_PROPERTIES_DATASET_CREATION_HPP
#define HDFPP_PROPERTIES_DATASET_CREATION_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2073: ** << Includes >>
#include "../filter.hpp"
#include "../properties.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110526194358.1968: ** Exception
//@+node:gcross.20110526194358.1969: *3* NoSuchFilterException
struct NoSuchFilterException: public Exception {
    std::string name;
    NoSuchFilterException(std::string const& name);
    virtual ~NoSuchFilterException() throw();
};
//@+node:gcross.20110602092541.2151: ** Properties
//@+node:gcross.20110526150836.1961: *3* DatasetAccessProperties
struct DatasetAccessProperties: public Properties {
    friend class Dataset;

    DECLARE_PROPERTIES_BOILERPLATE(DatasetAccess)
};
//@+node:gcross.20110526150836.1972: *3* DatasetCreationProperties
//@+<< Forward declarations >>
//@+node:gcross.20110527143225.1997: *4* << Forward declarations >>
template<class> struct datatypeOf;
class Datatype;
//@-<< Forward declarations >>

struct DatasetCreationProperties
  : public virtual Properties
{
    friend class Dataset;

    DECLARE_PROPERTIES_BOILERPLATE(DatasetCreation)

    //@+others
    //@+node:gcross.20110528133907.2062: *4* allocation mode
    DatasetCreationProperties setAllocationMode(AllocationMode allocation_mode);
    AllocationMode getAllocationMode() const;
    //@+node:gcross.20110526194358.1942: *4* chunk
    DatasetCreationProperties setChunkSize(hsize_t const chunk_size) const;
    DatasetCreationProperties setChunkSizes(unsigned int rank, hsize_t const* chunk_sizes) const;
    template<typename Dimensions> DatasetCreationProperties setChunkSizes(Dimensions dimensions) const {
        HSizeArray dims(dimensions);
        return setChunkSizes(dims.size,dims);
    }

    std::vector<hsize_t> getChunkSizes() const;
    //@+node:gcross.20110528133907.2054: *4* fill mode
    DatasetCreationProperties setFillMode(FillMode fill_mode);
    FillMode getFillMode() const;
    //@+node:gcross.20110527143225.1994: *4* fill value
    DatasetCreationProperties setFillValue(Datatype const& datatype, void const* value) const;

    template<typename T> DatasetCreationProperties setFillValue(T const& value) const {
        return setFillValue(datatypeOf<T>::get(),&value);
    }

    void getFillValue(Datatype const& datatype, void* value) const;

    template<typename T> void getFillValue(T& value) const {
        getFillValue(datatypeOf<T>::get(),&value);
    }

    template<typename T> T getFillValue() const {
        T value;
        getFillValue(value);
        return value;
    }

    FillValueStatus getFillValueStatus() const;
    //@+node:gcross.20110528133907.2023: *4* filter
    bool allAddedFiltersAreAvailable() const;

    DatasetCreationProperties appendFilter(Filter const& filter) const;

    std::auto_ptr<Filter> getFilterAtIndex(unsigned int index) const;

    std::auto_ptr<Filter> getFilterWithId(H5Z_filter_t filter_id) const;

    void modifyFilter(Filter const& filter) const;

    template<typename FilterType> FilterType getFilterOfType() const {
        return FilterType(dynamic_cast<FilterType&>(*getFilterWithId(FilterType::filter_id)));
    }

    void removeFilterWithId(H5Z_filter_t filter_id) const;

    template<typename FilterType> void removeFilterOfType() const{
        removeFilterWithId(FilterType::filter_id);
    }
    //@+node:gcross.20110526194358.1953: *4* layout
    DatasetCreationProperties setLayout(DatasetLayout layout) const;

    DatasetLayout getLayout() const;
    //@-others
};
//@+node:gcross.20110526150836.1962: *3* DatasetTransferProperties
struct DatasetTransferProperties: public Properties {
    DECLARE_PROPERTIES_BOILERPLATE(DatasetTransfer)
};
//@-others

}

#endif

//@+<< Trailing includes >>
//@+node:gcross.20110527143225.1998: ** << Trailing includes >>
#include "datatype.hpp"
//@-<< Trailing includes >>
//@-leo