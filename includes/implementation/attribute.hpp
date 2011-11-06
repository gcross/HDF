//@+leo-ver=5-thin
//@+node:gcross.20110521115623.1485: * @file attribute.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.1487: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_ATTRIBUTE_HPP
#define HDFPP_IMPLEMENTATION_ATTRIBUTE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.1486: ** << Includes >>
#include "attributable.hpp"
#include "contained.hpp"
#include "error.hpp"

#include <boost/optional.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2781: ** Exceptions
//@+node:gcross.20110521115623.2780: *3* NoSuchAttributeException
struct NoSuchAttributeException : public Exception {
    std::string name;
    NoSuchAttributeException(std::string const& name);
    virtual ~NoSuchAttributeException() throw();
};
//@+node:gcross.20110521115623.3957: ** Attribute traits
//@+node:gcross.20110521115623.3958: *3* highlevelAttributeAccessorsOf
template<typename T> struct highlevelAttributeAccessorsOf {};

#define DECLARE_HIGH_LEVEL_ACCESSOR(T) \
    template<> struct highlevelAttributeAccessorsOf<T> { \
        static herr_t get(hid_t loc_id, char const* obj_name, char const* attr_name, T* data); \
        static herr_t set(hid_t loc_id, char const* obj_name, char const* attr_name, T const* data, size_t size); \
    };

DECLARE_HIGH_LEVEL_ACCESSOR(char)
DECLARE_HIGH_LEVEL_ACCESSOR(unsigned char)
DECLARE_HIGH_LEVEL_ACCESSOR(short)
DECLARE_HIGH_LEVEL_ACCESSOR(unsigned short)
DECLARE_HIGH_LEVEL_ACCESSOR(int)
DECLARE_HIGH_LEVEL_ACCESSOR(unsigned int)
DECLARE_HIGH_LEVEL_ACCESSOR(long)
DECLARE_HIGH_LEVEL_ACCESSOR(unsigned long)
DECLARE_HIGH_LEVEL_ACCESSOR(long long)
DECLARE_HIGH_LEVEL_ACCESSOR(float)
DECLARE_HIGH_LEVEL_ACCESSOR(double)

#undef DECLARE_HIGH_LEVEL_ACCESSOR
//@+node:gcross.20110521115623.1488: ** class Attribute
class Attribute: public Contained {
    //@+<< Nested types >>
    //@+node:gcross.20110521115623.3944: *3* << Nested types >>
    public:

    template<typename T> struct getterOf { typedef void enabled; };

    template<typename T> struct setterOf { typedef void enabled; };
    //@-<< Nested types >>
    //@+others
    //@+node:gcross.20110521115623.1489: *3* Constructors
    public:

    Attribute(Attributable const& parent, char const* name);
    //@+node:gcross.20110521115623.1490: *3* Fields
    protected:

    std::string name;

    Identity::Ptr parent_identity;

    public:

    std::string const& getName() const;
    //@+node:gcross.20110521115623.1491: *3* Getters
    public:

    template<typename T> T get(
        bool bypass_existence_check=false
      , typename getterOf<T>::enabled dummy = boost::none
    ) const {
        return getterOf<T>::get(*this,bypass_existence_check);
    }

    operator char() const;
    operator unsigned char() const;
    operator short() const;
    operator unsigned short() const;
    operator int() const;
    operator unsigned int() const;
    operator long() const;
    operator unsigned long() const;
    operator long long() const;
    operator float() const;
    operator double() const;
    operator std::string() const;

    operator boost::optional<char>() const;
    operator boost::optional<unsigned char>() const;
    operator boost::optional<short>() const;
    operator boost::optional<unsigned short>() const;
    operator boost::optional<int>() const;
    operator boost::optional<unsigned int>() const;
    operator boost::optional<long>() const;
    operator boost::optional<unsigned long>() const;
    operator boost::optional<long long>() const;
    operator boost::optional<float>() const;
    operator boost::optional<double>() const;
    operator boost::optional<std::string>() const;
    //@+node:gcross.20110521115623.2763: *3* Informational
    public:

    bool exists() const;
    void assertExistence() const;
    //@+node:gcross.20110521115623.3960: *3* Setters
    public:

    template<typename T> void set(
        T value
      , typename setterOf<T>::enabled dummy = boost::none
    ) const {
        setterOf<T>::set(*this,value);
    }

    template<typename T> void set(
        boost::optional<T> const& value
      , typename setterOf<T>::enabled dummy = boost::none
    ) const {
        if(value) setterOf<T>::set(*this,*value);
    }

    void operator=(char value) const;
    void operator=(unsigned char value) const;
    void operator=(short value) const;
    void operator=(unsigned short value) const;
    void operator=(int value) const;
    void operator=(unsigned int value) const;
    void operator=(long value) const;
    void operator=(unsigned long value) const;
    void operator=(long long value) const;
    void operator=(float value) const;
    void operator=(double value) const;
    void operator=(char const* value) const;
    void operator=(std::string const& value) const;

    void operator=(boost::optional<char> const& value) const;
    void operator=(boost::optional<unsigned char> const& value) const;
    void operator=(boost::optional<short> const& value) const;
    void operator=(boost::optional<unsigned short> const& value) const;
    void operator=(boost::optional<int> const& value) const;
    void operator=(boost::optional<unsigned int> const& value) const;
    void operator=(boost::optional<long> const& value) const;
    void operator=(boost::optional<unsigned long> const& value) const;
    void operator=(boost::optional<long long> const& value) const;
    void operator=(boost::optional<float> const& value) const;
    void operator=(boost::optional<double> const& value) const;
    void operator=(boost::optional<char const*> const& value) const;
    void operator=(boost::optional<std::string> const& value) const;
    void operator=(boost::optional<std::string const&> const& value) const;
    //@-others
};

//@+<< Accessor specializations >>
//@+node:gcross.20110521115623.3962: *3* << Accessor specializations >>
//@+others
//@+node:gcross.20110521115623.4802: *4* Getters
#define DECLARE_GETTER(T) \
    template<> struct Attribute::getterOf<T> { \
        typedef boost::none_t enabled; \
        static T get(Attribute const& attribute, bool bypass_existence_check=false); \
    };

DECLARE_GETTER(char)
DECLARE_GETTER(unsigned char)
DECLARE_GETTER(short)
DECLARE_GETTER(unsigned short)
DECLARE_GETTER(int)
DECLARE_GETTER(unsigned int)
DECLARE_GETTER(long)
DECLARE_GETTER(unsigned long)
DECLARE_GETTER(long long)
DECLARE_GETTER(float)
DECLARE_GETTER(double)
DECLARE_GETTER(std::string)

#undef DECLARE_GETTER

template<typename T> struct Attribute::getterOf<boost::optional<T> > {
    typedef typename Attribute::getterOf<T>::enabled enabled;
    static boost::optional<T> get(
        Attribute const& attribute
      , bool bypass_existence_check=false
    ) {
        if(!attribute.exists())
            return boost::none;
        else
            return getterOf<T>::get(attribute,true);
    }
};
//@+node:gcross.20110521115623.4803: *4* Setters
#define DECLARE_SETTER(T) \
    template<> struct Attribute::setterOf<T> { \
        typedef boost::none_t enabled; \
        static void set(Attribute const& attribute, T value); \
    };

DECLARE_SETTER(char)
DECLARE_SETTER(unsigned char)
DECLARE_SETTER(short)
DECLARE_SETTER(unsigned short)
DECLARE_SETTER(int)
DECLARE_SETTER(unsigned int)
DECLARE_SETTER(long)
DECLARE_SETTER(unsigned long)
DECLARE_SETTER(long long)
DECLARE_SETTER(float)
DECLARE_SETTER(double)
DECLARE_SETTER(char const*)
DECLARE_SETTER(std::string const&)

#undef DECLARE_SETTER
//@-others
//@-<< Accessor specializations >>
//@-others

}

#endif
//@-leo
