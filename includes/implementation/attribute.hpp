#ifndef HDFPP_IMPLEMENTATION_ATTRIBUTE_HPP
#define HDFPP_IMPLEMENTATION_ATTRIBUTE_HPP

// Includes {{{
#include "attributable.hpp"
#include "contained.hpp"
#include "error.hpp"

#include <boost/optional.hpp>
#include <string>
// Includes }}}

namespace HDF {

// Exceptions {{{
struct NoSuchAttributeException : public Exception { // {{{
    std::string name;
    NoSuchAttributeException(std::string const& name);
    virtual ~NoSuchAttributeException() throw();
}; // }}}
// Exceptions }}}

// Attribute traits {{{
// highlevelAttributeAccessorsOf {{{
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
// highlevelAttributeAccessorsOf }}}
// Attribute traits }}}

class Attribute: public Contained { // {{{
    //   Nested types {{{
    public:

    template<typename T> struct getterOf { typedef void enabled; };

    template<typename T> struct setterOf { typedef void enabled; };
    //   Nested types }}}
    //   Constructors {{{
    public:

    Attribute(Attributable const& parent, char const* name);
    //   Constructors }}}
    //   Fields {{{
    protected:

    std::string name;

    Identity::Ptr parent_identity;

    public:

    std::string const& getName() const;
    //   Fields }}}
    //   Getters {{{
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
    //   Getters }}}
    //   Informational {{{
    public:

    bool exists() const;
    void assertExistence() const;
    //   Informational }}}
    //   Setters {{{
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
    //   Setters }}}
}; // }}}

// Accessor specializations {{{
//   Getters {{{
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
//   Getters }}}
//   Setters {{{
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
//   Setters }}}
// Accessor specializations }}}

}

#endif
