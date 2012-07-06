#ifndef HDFPP_PARAMETERS_HPP
#define HDFPP_PARAMETERS_HPP

namespace HDF {

// Parameter wrappers {{{
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
// Parameter wrappers }}}

// Macros {{{
#define GET_OPTIONAL_OR(optional,alternative) (optional ? (*optional) : alternative)
// Macros }}}

}

#endif
