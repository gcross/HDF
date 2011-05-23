//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2768: * @file attribute.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2769: ** << License >>
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
//@+node:gcross.20110521115623.2770: ** << Includes >>
#include "attribute.hpp"

#include <boost/format.hpp>
#include <boost/scoped_array.hpp>
#include <hdf5_hl.h>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2771: ** << Usings >>
using boost::format;
using boost::none;
using boost::optional;
using boost::scoped_array;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2779: ** Exceptions
//@+node:gcross.20110521115623.2783: *3* NoSuchAttributeException
NoSuchAttributeException::NoSuchAttributeException(string const& name)
  : Exception((format("No such attribute named %1%") % name).str())
  , name(name)
{}

NoSuchAttributeException::~NoSuchAttributeException() throw() {}
//@+node:gcross.20110521115623.2772: ** class Attribute
//@+node:gcross.20110521115623.2774: *3* Constructors
Attribute::Attribute(Containable const& parent, char const* name)
  : Containable(parent)
  , name(name)
{}
//@+node:gcross.20110521115623.2785: *3* Fields
string const& Attribute::getName() const { return name; }
//@+node:gcross.20110521115623.3961: *3* Getters
template<typename T> T getAttributeValueUsingHighLevelAccessor(Attribute const& attribute, bool bypass_existence_check) {
    if(!bypass_existence_check) attribute.assertExistence();
    T value;
    assertSuccess(
        "retrieving attribute value",
        highlevelAttributeAccessorsOf<T>::get(
            attribute.getId(),".",
            attribute.getName().c_str(),
            &value
        )
    );
    return value;
};

#define DEFINE_GETTER(T) \
    T Attribute::getterOf<T>::get(Attribute const& attribute, bool bypass_existence_check) { \
        return getAttributeValueUsingHighLevelAccessor<T>(attribute,bypass_existence_check); \
    }

DEFINE_GETTER(char)
DEFINE_GETTER(unsigned char)
DEFINE_GETTER(short)
DEFINE_GETTER(unsigned short)
DEFINE_GETTER(int)
DEFINE_GETTER(unsigned int)
DEFINE_GETTER(long)
DEFINE_GETTER(unsigned long)
DEFINE_GETTER(long long)
DEFINE_GETTER(float)
DEFINE_GETTER(double)

#undef DEFINE_GETTER


string Attribute::getterOf<string>::get(
    Attribute const& attribute
  , bool bypass_existence_check
) {
    if(!bypass_existence_check) attribute.assertExistence();
    hsize_t dummy1;
    H5T_class_t dummy2;
    size_t buffer_size;
    assertSuccess(
        "retrieving string attribute length",
        H5LTget_attribute_info(
            attribute.getId(),".",
            attribute.getName().c_str(),
            &dummy1,&dummy2,&buffer_size
        )
    );
    scoped_array<char> buffer(new char[buffer_size]);

    assertSuccess(
        "retrieving string attribute value",
        H5LTget_attribute_string(
            attribute.getId(),".",
            attribute.getName().c_str(),
            buffer.get()
        )
    );

    return string(buffer.get());
}

Attribute::operator char() const { return get<char>(); }
Attribute::operator unsigned char() const { return get<unsigned char>(); }
Attribute::operator short() const { return get<short>(); }
Attribute::operator unsigned short() const { return get<unsigned short>(); }
Attribute::operator int() const { return get<int>(); }
Attribute::operator unsigned int() const { return get<unsigned int>(); }
Attribute::operator long() const { return get<long>(); }
Attribute::operator unsigned long() const { return get<unsigned long>(); }
Attribute::operator long long() const { return get<long long>(); }
Attribute::operator float() const { return get<float>(); }
Attribute::operator double() const { return get<double>(); }
Attribute::operator string() const { return get<string>(); }

Attribute::operator optional<char>() const { return get<optional<char> >(); }
Attribute::operator optional<unsigned char>() const { return get<optional<unsigned char> >(); }
Attribute::operator optional<short>() const { return get<optional<short> >(); }
Attribute::operator optional<unsigned short>() const { return get<optional<unsigned short> >(); }
Attribute::operator optional<int>() const { return get<optional<int> >(); }
Attribute::operator optional<unsigned int>() const { return get<optional<unsigned int> >(); }
Attribute::operator optional<long>() const { return get<optional<long> >(); }
Attribute::operator optional<unsigned long>() const { return get<optional<unsigned long> >(); }
Attribute::operator optional<long long>() const { return get<optional<long long> >(); }
Attribute::operator optional<float>() const { return get<optional<float> >(); }
Attribute::operator optional<double>() const { return get<optional<double> >(); }
Attribute::operator optional<string>() const { return get<optional<string> >(); }
//@+node:gcross.20110521115623.2778: *3* Informational
bool Attribute::exists() const {
    return 
        assertSuccess(
            "querying attribute existence",
            H5LTfind_attribute(getId(),name.c_str())
        ) == 1;
}

void Attribute::assertExistence() const {
    if(!exists()) throw NoSuchAttributeException(name);
}
//@+node:gcross.20110521115623.3943: *3* Setters
template<typename T> void setAttributeValueUsingHighLevelAccessor(Attribute const& attribute, T value) {
    assertSuccess(
        "storing attribute value",
        highlevelAttributeAccessorsOf<T>::set(
            attribute.getId(),".",
            attribute.getName().c_str(),
            &value,
            1u
        )
    );
};

#define DEFINE_SETTER(T) \
    void Attribute::setterOf<T>::set(Attribute const& attribute, T value) { \
        return setAttributeValueUsingHighLevelAccessor<T>(attribute,value); \
    }

DEFINE_SETTER(char)
DEFINE_SETTER(unsigned char)
DEFINE_SETTER(short)
DEFINE_SETTER(unsigned short)
DEFINE_SETTER(int)
DEFINE_SETTER(unsigned int)
DEFINE_SETTER(long)
DEFINE_SETTER(unsigned long)
DEFINE_SETTER(long long)
DEFINE_SETTER(float)
DEFINE_SETTER(double)

#undef DEFINE_SETTER

void Attribute::setterOf<char const*>::set(Attribute const& attribute, char const* value) {
    assertSuccess(
        "writing string attribute to the object",
        H5LTset_attribute_string(attribute.getId(),".",attribute.getName().c_str(),value)
    );
}

void Attribute::setterOf<std::string const&>::set(Attribute const& attribute, string const& value) {
    assertSuccess(
        "writing string attribute to the object",
        H5LTset_attribute_string(attribute.getId(),".",attribute.getName().c_str(),value.c_str())
    );
}

void Attribute::operator=(char value) const { set(value); }
void Attribute::operator=(unsigned char value) const { set(value); }
void Attribute::operator=(short value) const { set(value); }
void Attribute::operator=(unsigned short value) const { set(value); }
void Attribute::operator=(int value) const { set(value); }
void Attribute::operator=(unsigned int value) const { set(value); }
void Attribute::operator=(long value) const { set(value); }
void Attribute::operator=(unsigned long value) const { set(value); }
void Attribute::operator=(long long value) const { set(value); }
void Attribute::operator=(float value) const { set(value); }
void Attribute::operator=(double value) const { set(value); }
void Attribute::operator=(char const* value) const { set(value); }
void Attribute::operator=(std::string const& value) const { set<string const&>(value); }

void Attribute::operator=(optional<char> const& value) const { set(value); }
void Attribute::operator=(optional<unsigned char> const& value) const { set(value); }
void Attribute::operator=(optional<short> const& value) const { set(value); }
void Attribute::operator=(optional<unsigned short> const& value) const { set(value); }
void Attribute::operator=(optional<int> const& value) const { set(value); }
void Attribute::operator=(optional<unsigned int> const& value) const { set(value); }
void Attribute::operator=(optional<long> const& value) const { set(value); }
void Attribute::operator=(optional<unsigned long> const& value) const { set(value); }
void Attribute::operator=(optional<long long> const& value) const { set(value); }
void Attribute::operator=(optional<float> const& value) const { set(value); }
void Attribute::operator=(optional<double> const& value) const { set(value); }
void Attribute::operator=(optional<char const*> const& value) const { set(value); }
void Attribute::operator=(optional<string> const& value) const { if(value) set<string const&>(*value); }
void Attribute::operator=(optional<string const&> const& value) const { set(value); }
//@+node:gcross.20110521115623.3941: ** Attribute traits
//@+node:gcross.20110521115623.3942: *3* highlevelAttributeAccessorsOf
#define DEFINE_HIGH_LEVEL_ACCESSOR(T,name) \
    herr_t highlevelAttributeAccessorsOf<T>::get(hid_t loc_id, char const* obj_name, char const* attr_name, T* data) { return H5LTget_attribute_##name(loc_id,obj_name,attr_name,data); } \
    herr_t highlevelAttributeAccessorsOf<T>::set(hid_t loc_id, char const* obj_name, char const* attr_name, T const* data, size_t size) { return H5LTset_attribute_##name(loc_id,obj_name,attr_name,data,size); }

DEFINE_HIGH_LEVEL_ACCESSOR(char,char)
DEFINE_HIGH_LEVEL_ACCESSOR(unsigned char,uchar)
DEFINE_HIGH_LEVEL_ACCESSOR(short,short)
DEFINE_HIGH_LEVEL_ACCESSOR(unsigned short,ushort)
DEFINE_HIGH_LEVEL_ACCESSOR(int,int)
DEFINE_HIGH_LEVEL_ACCESSOR(unsigned int,uint)
DEFINE_HIGH_LEVEL_ACCESSOR(long,long)
DEFINE_HIGH_LEVEL_ACCESSOR(unsigned long,ulong)
DEFINE_HIGH_LEVEL_ACCESSOR(long long,long_long)
DEFINE_HIGH_LEVEL_ACCESSOR(float,float)
DEFINE_HIGH_LEVEL_ACCESSOR(double,double)

#undef DEFINE_HIGH_LEVEL_ACCESSOR
//@-others

}
//@-leo
