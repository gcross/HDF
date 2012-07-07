#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_HPP

// Includes {{{
#include "enumerations.hpp"
#include "error.hpp"
#include "identified.hpp"
#include "utilities.hpp"

#include <boost/optional.hpp>
#include <boost/variant/variant.hpp>
#include <hdf5.h>
// Includes }}}

namespace HDF {

class Properties: public Identified { // {{{
    // Constructors/Destructors {{{
    protected:

    Properties(hid_t id);
    Properties();
    // Constructors/Destructors }}}
    // Informational {{{
    public:

    hid_t getClassId() const;
    // Informational }}}
}; // }}}

// Functions {{{
// getOptionalPropertiesId {{{
template<typename PropertiesType>
hid_t getOptionalPropertiesId(boost::optional<PropertiesType> const& optional_properties) {
    if(optional_properties)
        return optional_properties->getId();
    else
        return H5P_DEFAULT;
} // }}}
// Functions }}}

// Macros {{{
#define DECLARE_PROPERTIES_BOILERPLATE(Name) \
    public: \
    Name##Properties(); \
    Name##Properties copy() const; \
    protected: \
    Name##Properties(hid_t id); \
    public:

#define DEFINE_PROPERTIES_BOILERPLATE(Name,string_name,class_name) \
    Name##Properties::Name##Properties() \
      : Properties( \
          assertSuccess( \
            "creating " \
            #string_name \
            " properties", \
            H5Pcreate(H5P_##class_name) \
          ) \
        ) \
    {} \
     \
    Name##Properties::Name##Properties(hid_t id) \
      : Properties(id) \
    {} \
     \
    Name##Properties Name##Properties::copy() const { \
        return Name##Properties(\
            assertSuccess( \
                "copying " \
                #string_name \
                " properties", \
                H5Pcopy(getId()) \
            ) \
        ); \
    } \
// Macros }}}

}

#endif
