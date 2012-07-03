//@+leo-ver=5-thin
//@+node:gcross.20111106135914.2089: * @file parameters.hpp
//@@language cplusplus
#ifndef HDFPP_PARAMETERS_HPP
#define HDFPP_PARAMETERS_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2881: ** << Includes >>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2883: ** Parameter wrappers
template<typename T> class ConstructorParameter {
private:
    //! The data wrapped by this class.
    T& data;
protected:
    //! Wrap \c data in this class.
    explicit ConstructorParameter(T& data) : data(data) {}
public:
    //! Get a reference to the wrapped data.
    T& operator*() const { return data; }
    //! Access a field of the wrapped data.
    T* operator->() const { return &data; }
};


#define DEFINE_TEMPLATIZED_PARAMETER(ParameterName,parameterName) \
    template<typename T> struct ParameterName : public ConstructorParameter<T> { \
        explicit ParameterName(T& data) : ConstructorParameter<T>(data) {} \
        template<typename U> ParameterName(ParameterName<U>& other) : ConstructorParameter<T>(*other) {} \
        template<typename U> operator ParameterName<U>() const { return ParameterName<U>(static_cast<U&>(**this)); } \
    }; \
    template<typename T> ParameterName<T> parameterName(T& data) { return ParameterName<T>(data); } \
    template<typename T> ParameterName<T const> parameterName(T const& data) { return ParameterName<T const>(data); }

DEFINE_TEMPLATIZED_PARAMETER(CopyOf,copyOf)
DEFINE_TEMPLATIZED_PARAMETER(CreateAt,createAt)
DEFINE_TEMPLATIZED_PARAMETER(RangeOf,rangeOf)
DEFINE_TEMPLATIZED_PARAMETER(TakeOwnershipOf,takeOwnershipOf)
//@+node:gcross.20110521115623.3174: ** Macros
#define GET_OPTIONAL_OR(optional,alternative) (optional ? (*optional) : alternative)
//@-others

}

#endif
//@-leo
