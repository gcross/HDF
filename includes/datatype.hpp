//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3034: * @file datatype.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3036: ** << License >>
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

#ifndef HDFPP_DATATYPE_HPP
#define HDFPP_DATATYPE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3035: ** << Includes >>
#include "error.hpp"
#include "identified.hpp"
#include "parameters.hpp"

#include <complex>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.3037: ** Classes
//@+node:gcross.20110521115623.3038: *3* Datatype
//@+<< Forward declarations >>
//@+node:gcross.20110521115623.3061: *4* << Forward declarations >>
class TransientDatatype;
//@-<< Forward declarations >>

class Datatype {
    //@+others
    //@+node:gcross.20110521115623.3040: *4* Constructors
    protected:

    Datatype();
    //@+node:gcross.20110521115623.3039: *4* Fields
    public:

    virtual hid_t getDatatypeId() const = 0;
    //@+node:gcross.20110521115623.3041: *4* Operations
    //@+others
    //@+node:gcross.20110521115623.3110: *5* Compound
    protected:

    void insert(char const* name, size_t offset, Datatype const& datatype);
    //@+node:gcross.20110521115623.3042: *5* Generic
    public:

    TransientDatatype copy();

    protected:

    void lock();
    //@-others
    //@+node:gcross.20110521115623.3043: *4* Operators
    bool operator==(Datatype const& other);
    //@-others
};
//@+node:gcross.20110521115623.3113: *3* MutableDatatype
class MutableDatatype: public Datatype {
    //@+others
    //@+node:gcross.20110521115623.3121: *4* Constructors
    protected:

    MutableDatatype();
    //@+node:gcross.20110521115623.3117: *4* Operations
    //@+others
    //@+node:gcross.20110521115623.3118: *5* Compound
    public:

    void insert(char const* name, size_t offset, Datatype const& datatype);
    //@-others
    //@-others
};
//@+node:gcross.20110521115623.3044: *3* TransientDatatype
class TransientDatatype: public MutableDatatype, public Identified {
    //@+others
    //@+node:gcross.20110521115623.3045: *4* Constructors
    public:

    TransientDatatype(CopyOf<Datatype const> other);

    TransientDatatype(H5T_class_t class_id, size_t size);
    //@+node:gcross.20110521115623.3063: *4* Fields
    public:

    virtual hid_t getDatatypeId() const;
    //@-others
};
//@+node:gcross.20110521115623.3062: *3* PermanentDatatype
class PermanentDatatype: public Datatype {
    //@+others
    //@+node:gcross.20110521115623.3066: *4* Constructors
    public:

    PermanentDatatype(hid_t id);
    //@+node:gcross.20110521115623.3064: *4* Fields
    protected:

    hid_t id;

    public:

    virtual hid_t getDatatypeId() const;
    //@-others
};
//@+node:gcross.20110521115623.3095: ** Type functions
//@+node:gcross.20110521115623.3096: *3* datatypeOf
template<typename T> struct datatypeOf {};

template<> struct datatypeOf<char> { static Datatype const& get(); };
template<> struct datatypeOf<signed char> { static Datatype const& get(); };
template<> struct datatypeOf<unsigned char> { static Datatype const& get(); };
template<> struct datatypeOf<short> { static Datatype const& get(); };
template<> struct datatypeOf<unsigned short> { static Datatype const& get(); };
template<> struct datatypeOf<int> { static Datatype const& get(); };
template<> struct datatypeOf<unsigned int> { static Datatype const& get(); };
template<> struct datatypeOf<long> { static Datatype const& get(); };
template<> struct datatypeOf<unsigned long> { static Datatype const& get(); };
template<> struct datatypeOf<long long> { static Datatype const& get(); };
template<> struct datatypeOf<unsigned long long> { static Datatype const& get(); };
template<> struct datatypeOf<float> { static Datatype const& get(); };
template<> struct datatypeOf<double> { static Datatype const& get(); };
template<> struct datatypeOf<long double> { static Datatype const& get(); };

template<typename T> struct datatypeOf<std::complex<T> > { static Datatype const& get(); };

template<typename T> Datatype const& datatypeOf<std::complex<T> >::get() {
    static struct ComplexDatatype: public PermanentDatatype {
        ComplexDatatype()
          : PermanentDatatype(
                assertSuccess(
                    "creating complex datatype",
                    H5Tcreate(H5T_COMPOUND,sizeof(std::complex<T>))
                )
            )
        {
            std::complex<T> c;
            Datatype const& member_datatype = datatypeOf<T>::get();
            insert("r",0u,member_datatype);
            insert("i",sizeof(T),member_datatype);
            lock();
        }
    } datatype;
    return datatype;
}
//@-others

}

#endif
//@-leo
