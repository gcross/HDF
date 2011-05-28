//@+leo-ver=5-thin
//@+node:gcross.20110527192131.2335: * @file filter.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110527192131.2337: ** << License >>
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

#ifndef HDFPP_FILTER_HPP
#define HDFPP_FILTER_HPP

//@+<< Includes >>
//@+node:gcross.20110527192131.2336: ** << Includes >>
#include "enumerations.hpp"
#include "error.hpp"

#include <boost/function.hpp>
#include <boost/optional.hpp>
#include <hdf5.h>
#include <map>
#include <memory>
#include <vector>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110527192131.2369: ** Exceptions
//@+node:gcross.20110527192131.2372: *3* WrongNumberOfParametersForFilterException
struct WrongNumberOfParametersForFilterException: public Exception {
    std::string filter_name;
    unsigned int expected_number_of_parameters, actual_number_of_parameters;
    WrongNumberOfParametersForFilterException(
        char const* filter_name
      , unsigned int expected_number_of_parameters
      , unsigned int actual_number_of_parameters
    );
    virtual ~WrongNumberOfParametersForFilterException() throw();
};
//@+node:gcross.20110528133907.2028: ** Classes
//@+node:gcross.20110527192131.2338: *3* Filter
class Filter {
    //@+others
    //@+node:gcross.20110527192131.2340: *4* Constructors / Destructors
    public:

    Filter(
        unsigned int number_of_parameters
      , bool optional_flag
    );

    Filter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    ~Filter();
    //@+node:gcross.20110527192131.2341: *4* Fields
    private:

    std::vector<unsigned int> parameter_data;

    bool optional_flag;

    public:

    size_t numberOfParameters() const;
    unsigned int* parameters();
    unsigned int const* parameters() const;
    unsigned int& operator[](unsigned int index);
    unsigned int const& operator[](unsigned int index) const;

    bool getOptionalFlag() const;
    void setOptionalFlag(bool optional_flag);

    virtual H5Z_filter_t getFilterId() const = 0;
    //@+node:gcross.20110527192131.2368: *4* Miscellaneous
    protected:

    void assertNumberOfParametersIs(unsigned int expected_number_of_parameters);

    public:

    static bool checkAvailabilityOf(H5Z_filter_t filter_id);
    //@+node:gcross.20110527192131.2342: *4* Registry
    public:

    typedef boost::function<std::auto_ptr<Filter> (std::vector<unsigned int> const&,bool)> Factory;

    private:

    static std::map<H5Z_filter_t,Factory> registry;

    protected:

    static void registerFactory(H5Z_filter_t filter_id, Factory const& factory);

    template<typename FilterType> struct RegisterFactory {
        RegisterFactory() {
            Filter::registerFactory(FilterType::filter_id,*this);
        }
        std::auto_ptr<Filter> operator()(
            std::vector<unsigned int> const& parameters
          , bool optional_flag
        ) const {
            return std::auto_ptr<Filter>(new FilterType(parameters,optional_flag));
        }
    };

    static boost::optional<Factory const&> lookupFactory(H5Z_filter_t filter_id);

    public:

    static std::auto_ptr<Filter> construct(
        H5Z_filter_t filter_id
      , std::vector<unsigned int> const& parameters
      , bool optional_flag
    );
    //@-others
};
//@+node:gcross.20110528133907.2027: *3* UnknownFilter
class UnknownFilter: public Filter {
protected:
    H5Z_filter_t filter_id;
public:
    UnknownFilter(
        H5Z_filter_t filter_id
      , std::vector<unsigned int> const& parameters
      , bool optional_flag
    );
    virtual H5Z_filter_t getFilterId() const;
};
//@+node:gcross.20110527192131.2367: ** Macros
#define FILTER_DECLARATION_BOILERPLATE(FilterType) \
    static H5Z_filter_t const filter_id; \
    static bool isAvailable(); \
    virtual H5Z_filter_t getFilterId() const; \
    private: \
    static Filter::RegisterFactory<FilterType> const __factory_registerer;

#define FILTER_DEFINITION_BOILERPLATE(FilterType,filter_id_value) \
    H5Z_filter_t const FilterType::filter_id = filter_id_value; \
    bool FilterType::isAvailable() { return Filter::checkAvailabilityOf(filter_id_value); } \
    H5Z_filter_t FilterType::getFilterId() const { return filter_id_value; } \
    Filter::RegisterFactory<FilterType> const FilterType::__factory_registerer;
//@+node:gcross.20110527192131.2359: ** Filters
//@+node:gcross.20110527192131.2384: *3* DeflateCompressionFilter
struct DeflateCompressionFilter: public Filter {
    DeflateCompressionFilter(
        unsigned int compression_level
      , bool optional_flag = true
    );
    DeflateCompressionFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    unsigned int getCompressionLevel() const;
    void setCompressionLevel(unsigned int compression_level);

    FILTER_DECLARATION_BOILERPLATE(DeflateCompressionFilter);
};
//@+node:gcross.20110527192131.2360: *3* Fletcher32ChecksumFilter
struct Fletcher32ChecksumFilter: public Filter {
    Fletcher32ChecksumFilter();
    Fletcher32ChecksumFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(Fletcher32ChecksumFilter);
};
//@+node:gcross.20110528133907.2039: *3* NBitCompressionFilter
struct NBitCompressionFilter: public Filter {
    NBitCompressionFilter();
    NBitCompressionFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(NBitCompressionFilter);
};
//@+node:gcross.20110527192131.2396: *3* ScaleOffsetCompressionFilter
struct ScaleOffsetCompressionFilter: public Filter {
    ScaleOffsetCompressionFilter(
        ScaleMethod scale_method
      , unsigned int scale_factor
      , bool optional_flag = true
    );
    ScaleOffsetCompressionFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    ScaleMethod getScaleMethod() const;
    void setScaleMethod(ScaleMethod scale_method);

    unsigned int getScaleFactor() const;
    void setScaleFactor(unsigned int scale_factor);

    FILTER_DECLARATION_BOILERPLATE(ScaleOffsetCompressionFilter);
};
//@+node:gcross.20110527192131.2378: *3* ShuffleFilter
struct ShuffleFilter: public Filter {
    ShuffleFilter();
    ShuffleFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(ShuffleFilter);
};
//@+node:gcross.20110527192131.2388: *3* SZIPCompressionFilter
struct SZIPCompressionFilter: public Filter {
    SZIPCompressionFilter(
        SZIPCodingMethod coding_method
      , unsigned int pixels_per_block
      , bool optional_flag = true
    );
    SZIPCompressionFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    SZIPCodingMethod getCodingMethod() const;
    void setCodingMethod(SZIPCodingMethod coding_method);

    unsigned int getPixelsPerBlock() const;
    void setPixelsPerBlock(unsigned int pixels_per_block);

    FILTER_DECLARATION_BOILERPLATE(SZIPCompressionFilter);
};
//@-others

}

#endif
//@-leo
