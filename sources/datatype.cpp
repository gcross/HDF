// Includes {{{
#include "implementation/datatype.hpp"
#include "implementation/error.hpp"
// Includes }}}

namespace HDF {

// Datatype Classes {{{
// Datatype {{{
//   Constructors {{{
Datatype::Datatype() {}
//   Constructors }}}
//   Operators {{{
bool Datatype::operator==(Datatype const& other) {
    return getDatatypeId() == other.getDatatypeId();
}
//   Operators }}}
//   Operations {{{
//     Compound {{{
void Datatype::insert(char const* name, size_t offset, Datatype const& datatype) {
    assertSuccess(
        "inserting member into datatype",
        H5Tinsert(getDatatypeId(),name,offset,datatype.getDatatypeId())
    );
}
//     Compound }}}
//     Generic {{{
TransientDatatype Datatype::copy() {
    return TransientDatatype(copyOf(*this));
}

void Datatype::lock() {
    assertSuccess(
        "locking datatype",
        H5Tlock(getDatatypeId())
    );
}
//     Generic }}}
//   Operations }}}
// Datatype }}}
// MutableDatatype {{{
//   Constructors {{{
MutableDatatype::MutableDatatype() {}
//   Constructors }}}
//   Operations {{{
//     Compound {{{
void MutableDatatype::insert(char const* name, size_t offset, Datatype const& datatype) {
    Datatype::insert(name,offset,datatype);
}
//     Compound }}}
//   Operations }}}
// MutableDatatype }}}
// TransientDatatype {{{
//   Constructors {{{
TransientDatatype::TransientDatatype(CopyOf<Datatype const> other) // {{{
  : Identified(
        assertSuccess(
            "copying datatype",
            H5Tcopy(other->getDatatypeId())
        ),
        H5Tclose
    )
{} // }}}

TransientDatatype::TransientDatatype(H5T_class_t class_id, size_t size) // {{{
  : Identified(
        assertSuccess(
            "creating datatype",
            H5Tcreate(class_id,size)
        ),
        H5Tclose
    )
{} // }}}
//   Constructors }}}
//   Fields {{{
hid_t TransientDatatype::getDatatypeId() const { return getId(); }
//   Fields }}}
// TransientDatatype }}}
// PermanentDatatype {{{
PermanentDatatype::PermanentDatatype(hid_t id) : id(id) {}

hid_t PermanentDatatype::getDatatypeId() const { return id; }
// PermanentDatatype }}}
// Datatype Classes }}}

// Type functions {{{
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
// Type functions }}}

}
