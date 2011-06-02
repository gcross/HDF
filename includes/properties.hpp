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
