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

#ifndef HDFPP_PROPERTIES_HPP
#define HDFPP_PROPERTIES_HPP

//@+<< Includes >>
//@+node:gcross.20110520211700.1464: ** << Includes >>
#include "enumerations.hpp"
#include "identifiable.hpp"
#include "utilities.hpp"

#include <boost/optional.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520211700.1466: ** class Properties
class Properties: public Identifiable {
    //@+others
    //@+node:gcross.20110520211700.1467: *3* Constructors/Destructors
    protected:

    Properties(hid_t id);
    Properties();
    //@-others
};
//@+node:gcross.20110526150836.1975: ** Shared properties
//@+node:gcross.20110525201928.3113: *3* CreateMissingIntermediateGroupsPropertyBase
class CreateMissingIntermediateGroupsPropertyBase : public virtual Properties {
protected:
    CreateMissingIntermediateGroupsPropertyBase();
    void setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const;
public:
    bool getCreateMissingIntermediateGroups() const;
};
//@+node:gcross.20110525201928.3114: *3* CreateMissingIntermediateGroupsProperty
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
struct DatasetCreationProperties: Properties {
    DatasetCreationProperties();

    //@+others
    //@+node:gcross.20110526194358.1942: *4* Chunk
    DatasetCreationProperties setChunkSize(hsize_t const chunk_size) const;
    DatasetCreationProperties setChunkSizes(unsigned int rank, hsize_t const* chunk_sizes) const;
    template<typename Dimensions> DatasetCreationProperties setChunkSizes(Dimensions dimensions) const {
        HSizeArray dims(dimensions);
        return setChunkSizes(dims.size,dims);
    }

    std::vector<hsize_t> getChunkSizes() const;
    //@-others
};
//@+node:gcross.20110526150836.1962: *3* DatasetTransferProperties
struct DatasetTransferProperties: public Properties {
    DatasetTransferProperties();
};
//@+node:gcross.20110526150836.1974: *3* FileAccessProperties
struct FileAccessProperties: public Properties {
    FileAccessProperties();

    FileAccessProperties useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const;
    void getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const;
    std::pair<size_t,bool> getCoreDriverSettings() const;

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
