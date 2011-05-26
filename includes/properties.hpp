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
#include "identifiable.hpp"

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
//@+node:gcross.20110521115623.2860: ** Properties
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
//@+node:gcross.20110525201928.3097: *3* LinkAccessProperties
struct LinkAccessProperties: public Properties { LinkAccessProperties(); };
//@+node:gcross.20110525201928.3098: *3* LinkCreationProperties
struct LinkCreationProperties
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<LinkCreationProperties>
{
    LinkCreationProperties();

    enum CharacterEncoding { ASCIIEncoding, UTF8Encoding };
    static H5T_cset_t getCharacterEncodingId(CharacterEncoding encoding);
    static CharacterEncoding getCharacterEncodingFromId(H5T_cset_t id);

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
