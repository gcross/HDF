//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2880: * @file parameters.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2882: ** << License >>
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
