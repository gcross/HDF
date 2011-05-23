//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3057: * @file datatype.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3058: ** << License >>
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

//@+<< Includes >>
//@+node:gcross.20110521115623.3059: ** << Includes >>
#include "datatype.hpp"
#include "error.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3060: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3081: ** Classes
//@+node:gcross.20110521115623.3082: *3* Datatype
//@+node:gcross.20110521115623.3083: *4* Constructors
Datatype::Datatype() {}
//@+node:gcross.20110521115623.3085: *4* Operators
bool Datatype::operator==(Datatype const& other) {
    return getDatatypeId() == other.getDatatypeId();
}
//@+node:gcross.20110521115623.3086: *4* Operations
//@+node:gcross.20110521115623.3112: *5* Compound
void Datatype::insert(char const* name, size_t offset, Datatype const& datatype) {
    assertSuccess(
        "inserting member into datatype",
        H5Tinsert(getDatatypeId(),name,offset,datatype.getDatatypeId())
    );
}
//@+node:gcross.20110521115623.3087: *5* Generic
TransientDatatype Datatype::copy() {
    return TransientDatatype(copyOf(*this));
}

void Datatype::lock() {
    assertSuccess(
        "locking datatype",
        H5Tlock(getDatatypeId())
    );
}
//@+node:gcross.20110521115623.3126: *3* MutableDatatype
//@+node:gcross.20110521115623.3127: *4* Constructors
MutableDatatype::MutableDatatype() {}
//@+node:gcross.20110521115623.3128: *4* Operations
//@+node:gcross.20110521115623.3129: *5* Compound
void MutableDatatype::insert(char const* name, size_t offset, Datatype const& datatype) {
    Datatype::insert(name,offset,datatype);
}
//@+node:gcross.20110521115623.3089: *3* TransientDatatype
//@+node:gcross.20110521115623.3090: *4* Constructors
TransientDatatype::TransientDatatype(CopyOf<Datatype const> other)
  : Identifiable(
        assertSuccess(
            "copying datatype",
            H5Tcopy(other->getDatatypeId())
        ),
        H5Tclose
    )
{}

TransientDatatype::TransientDatatype(H5T_class_t class_id, size_t size)
  : Identifiable(
        assertSuccess(
            "creating datatype",
            H5Tcreate(class_id,size)
        ),
        H5Tclose
    )
{}
//@+node:gcross.20110521115623.3091: *4* Fields
hid_t TransientDatatype::getDatatypeId() const { return getId(); }
//@+node:gcross.20110521115623.3092: *3* PermanentDatatype
PermanentDatatype::PermanentDatatype(hid_t id) : id(id) {}

hid_t PermanentDatatype::getDatatypeId() const { return id; }
//@+node:gcross.20110521115623.3101: ** Type functions
//@+node:gcross.20110521115623.3102: *3* datatypeOf
Datatype const& datatypeOf<char>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_CHAR);
    return datatype;
}
Datatype const& datatypeOf<signed char>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_SCHAR);
    return datatype;
}
Datatype const& datatypeOf<unsigned char>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_UCHAR);
    return datatype;
}
Datatype const& datatypeOf<short>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_SHORT);
    return datatype;
}
Datatype const& datatypeOf<unsigned short>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_USHORT);
    return datatype;
}
Datatype const& datatypeOf<int>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_INT);
    return datatype;
}
Datatype const& datatypeOf<unsigned int>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_UINT);
    return datatype;
}
Datatype const& datatypeOf<long>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_LONG);
    return datatype;
}
Datatype const& datatypeOf<unsigned long>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_ULONG);
    return datatype;
}
Datatype const& datatypeOf<long long>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_LLONG);
    return datatype;
}
Datatype const& datatypeOf<unsigned long long>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_ULLONG);
    return datatype;
}
Datatype const& datatypeOf<float>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_FLOAT);
    return datatype;
}
Datatype const& datatypeOf<double>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_DOUBLE);
    return datatype;
}
Datatype const& datatypeOf<long double>::get() {
    static PermanentDatatype datatype(H5T_NATIVE_LDOUBLE);
    return datatype;
}
//@-others

}
//@-leo
