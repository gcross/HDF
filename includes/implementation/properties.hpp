//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1463: * @file properties.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520211700.1465: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_HPP

//@+<< Includes >>
//@+node:gcross.20110520211700.1464: ** << Includes >>
#include "enumerations.hpp"
#include "error.hpp"
#include "filter.hpp"
#include "identified.hpp"
#include "utilities.hpp"

#include <boost/optional.hpp>
#include <boost/variant/variant.hpp>
#include <hdf5.h>
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
//@+node:gcross.20110520211700.1466: ** class Properties
class Properties: public Identified {
    //@+others
    //@+node:gcross.20110520211700.1467: *3* Constructors/Destructors
    protected:

    Properties(hid_t id);
    Properties();
    //@-others
};
//@+node:gcross.20110526150836.1975: ** Shared properties
//@+node:gcross.20110525201928.3114: *3* CreateMissingIntermediateGroupsProperty
class CreateMissingIntermediateGroupsPropertyBase : public virtual Properties {
protected:
    CreateMissingIntermediateGroupsPropertyBase();
    void setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const;
public:
    bool getCreateMissingIntermediateGroups() const;
};

template<typename T> class CreateMissingIntermediateGroupsProperty
  : public CreateMissingIntermediateGroupsPropertyBase
{
private:
    typedef CreateMissingIntermediateGroupsPropertyBase Base;
protected:
    CreateMissingIntermediateGroupsProperty() {}
public:
    T setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const {
        Base::setCreateMissingIntermediateGroups(create_missing_intermediate_groups);
        return *static_cast<T const*>(this);
    }
    T createMissingIntermediateGroups() const {
        return setCreateMissingIntermediateGroups(true);
    }
    T dontCreateMissingIntermediateGroups() const {
        return setCreateMissingIntermediateGroups(false);
    }
};
//@+node:gcross.20110521115623.2860: ** Properties
//@+node:gcross.20110526150836.1961: *3* DatasetAccessProperties
struct DatasetAccessProperties: public Properties {
    DatasetAccessProperties();
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
    DatasetCreationProperties();

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
    DatasetTransferProperties();
};
//@+node:gcross.20110526150836.1974: *3* FileAccessProperties
struct FileAccessProperties: public Properties {
    FileAccessProperties();

    //@+others
    //@+node:gcross.20110526194358.1949: *4* core driver
    FileAccessProperties useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const;

    void getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const;
    std::pair<size_t,bool> getCoreDriverSettings() const;
    //@-others
};
//@+node:gcross.20110526150836.1973: *3* FileCreationProperties
struct FileCreationProperties: public Properties {
    FileCreationProperties();
};
//@+node:gcross.20110526150836.1960: *3* GroupCreationProperties
struct GroupCreationProperties
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<GroupCreationProperties>
{
    GroupCreationProperties();

    //@+others
    //@+node:gcross.20110602092541.2048: *4* local heap size hint
    GroupCreationProperties setLocalHeapSizeHint(size_t size_hint);
    size_t getLocalHeapSizeHint() const;
    //@-others
};
//@+node:gcross.20110525201928.3097: *3* LinkAccessProperties
struct LinkAccessProperties: public Properties {
    LinkAccessProperties();
};
//@+node:gcross.20110525201928.3098: *3* LinkCreationProperties
struct LinkCreationProperties
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<LinkCreationProperties>
{
    LinkCreationProperties();

    LinkCreationProperties setCharacterEncoding(CharacterEncoding encoding) const;
    CharacterEncoding getCharacterEncoding() const;
};
//@+node:gcross.20110521115623.2914: ** Functions
//@+node:gcross.20110521115623.2917: *3* getOptionalPropertiesId
template<typename PropertiesType>
hid_t getOptionalPropertiesId(boost::optional<PropertiesType> const& optional_properties) {
    if(optional_properties)
        return optional_properties->getId();
    else
        return H5P_DEFAULT;
}
//@-others

}

#endif
//@-leo
