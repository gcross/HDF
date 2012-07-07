#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_DATASET_CREATION_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_DATASET_CREATION_HPP

// Includes {{{
#include "../filter.hpp"
#include "../properties.hpp"
// Includes }}}

namespace HDF {

// Exceptions {{{
struct NoSuchFilterException: public Exception { // {{{
    std::string name;
    NoSuchFilterException(std::string const& name);
    virtual ~NoSuchFilterException() throw();
}; // }}}
// Exceptions }}}

// Properties {{{
struct DatasetAccessProperties: public Properties { // {{{
    friend class Dataset;

    DECLARE_PROPERTIES_BOILERPLATE(DatasetAccess)
}; // }}}
// struct DatasetCreationProperties {{{
template<class> struct datatypeOf;
class Datatype;

struct DatasetCreationProperties
  : public virtual Properties
{
    friend class Dataset;

    DECLARE_PROPERTIES_BOILERPLATE(DatasetCreation)

  // allocation mode {{{
    DatasetCreationProperties setAllocationMode(AllocationMode allocation_mode);
    AllocationMode getAllocationMode() const;
  // allocation mode }}}
  // chunk size {{{
    DatasetCreationProperties setChunkSize(hsize_t const chunk_size) const;
    DatasetCreationProperties setChunkSizes(unsigned int rank, hsize_t const* chunk_sizes) const;
    template<typename Dimensions> DatasetCreationProperties setChunkSizes(Dimensions dimensions) const {
        HSizeArray dims(dimensions);
        return setChunkSizes(dims.size,dims);
    }

    std::vector<hsize_t> getChunkSizes() const;
  // chunk size }}}
  // fill mode {{{
    DatasetCreationProperties setFillMode(FillMode fill_mode);
    FillMode getFillMode() const;
  // fill mode }}}
  // fill value {{{
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
  // fill value }}}
  // filters {{{
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
  // filters }}}
  // layout {{{
    DatasetCreationProperties setLayout(DatasetLayout layout) const;

    DatasetLayout getLayout() const;
  // layour }}}
};
// struct DatasetCreationProperties }}}
struct DatasetTransferProperties: public Properties { // {{{
    DECLARE_PROPERTIES_BOILERPLATE(DatasetTransfer)
}; // }}}
// Properties }}}


}

#endif

// Trailing includes {{{
#include "../datatype.hpp"
// Trailing includes }}}
