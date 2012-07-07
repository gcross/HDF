#ifndef HDFPP_IMPLEMENTATION_FILTER_HPP
#define HDFPP_IMPLEMENTATION_FILTER_HPP

// Includes {{{
#include "enumerations.hpp"
#include "error.hpp"

#include <boost/function.hpp>
#include <boost/optional.hpp>
#include <hdf5.h>
#include <map>
#include <memory>
#include <vector>
// Includes }}}

namespace HDF {

// Exceptions {{{
struct WrongNumberOfParametersForFilterException: public Exception { // {{{
    std::string filter_name;
    unsigned int expected_number_of_parameters, actual_number_of_parameters;
    WrongNumberOfParametersForFilterException(
        char const* filter_name
      , unsigned int expected_number_of_parameters
      , unsigned int actual_number_of_parameters
    );
    virtual ~WrongNumberOfParametersForFilterException() throw();
}; // }}}
// Exceptions }}}

// Classes {{{
class Filter { // {{{
    // Constructors/Destructors {{{
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
    // Constructors/Destructors }}}
    // Fields {{{
    private:

    std::vector<unsigned int> parameters;

    bool optional_flag;

    public:

    size_t getNumberOfParameters() const;
    std::vector<unsigned int> const& getParameters() const;
    unsigned int const* getParameterData() const;
    unsigned int& operator[](unsigned int index);
    unsigned int const& operator[](unsigned int index) const;

    bool getOptionalFlag() const;
    void setOptionalFlag(bool optional_flag);

    unsigned int getFlags() const;

    virtual H5Z_filter_t getFilterId() const = 0;
    // Fields }}}
    // Miscellaneous {{{
    protected:

    void assertNumberOfParametersIs(unsigned int expected_number_of_parameters);

    public:

    static bool checkAvailabilityOf(H5Z_filter_t filter_id);
    // Miscellaneous }}}
    // Registry {{{
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
    // Registry }}}
}; // }}}
class UnknownFilter: public Filter { // {{{
protected:
    H5Z_filter_t filter_id;
public:
    UnknownFilter(
        H5Z_filter_t filter_id
      , std::vector<unsigned int> const& parameters
      , bool optional_flag
    );
    virtual H5Z_filter_t getFilterId() const;
}; // }}}
// Classes }}}

// Macros {{{
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
// Macros }}}

// Filters {{{
struct DeflateCompressionFilter: public Filter { // {{{
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
}; // }}}
struct Fletcher32ChecksumFilter: public Filter { // {{{
    Fletcher32ChecksumFilter();
    Fletcher32ChecksumFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(Fletcher32ChecksumFilter);
}; // }}}
struct NBitCompressionFilter: public Filter { // {{{
    NBitCompressionFilter();
    NBitCompressionFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(NBitCompressionFilter);
}; // }}}
struct ScaleOffsetCompressionFilter: public Filter { // {{{
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
}; // }}}
struct ShuffleFilter: public Filter { // {{{
    ShuffleFilter();
    ShuffleFilter(
        std::vector<unsigned int> const& parameters
      , bool optional_flag
    );

    FILTER_DECLARATION_BOILERPLATE(ShuffleFilter);
}; // }}}
struct SZIPCompressionFilter: public Filter { // {{{
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
}; // }}}
// Filters }}}

}

#endif
