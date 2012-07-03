//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1463: * @file properties.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_HPP

//@+<< Includes >>
//@+node:gcross.20110520211700.1464: ** << Includes >>
#include "enumerations.hpp"
#include "error.hpp"
#include "identified.hpp"
#include "utilities.hpp"

#include <boost/optional.hpp>
#include <boost/variant/variant.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520211700.1466: ** class Properties
class Properties: public Identified {
    //@+others
    //@+node:gcross.20110520211700.1467: *3* Constructors/Destructors
    protected:

    Properties(hid_t id);
    Properties();
    //@+node:gcross.20110602121059.2131: *3* Informational
    public:

    hid_t getClassId() const;
    //@-others
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
//@+node:gcross.20110602121059.2125: ** Macros
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
//@-others

}

#endif
//@-leo
