#ifndef HDFPP_IMPLEMENTATION_DATATYPE_HPP
#define HDFPP_IMPLEMENTATION_DATATYPE_HPP

// Includes {{{
#include "error.hpp"
#include "identified.hpp"
#include "parameters.hpp"

#include <complex>
#include <hdf5.h>
// Includes }}}

namespace HDF {

// Classes {{{
// Datatype {{{
// Forward declarations {{{
class TransientDatatype;
// Forward declarations }}}

class Datatype {
    // Constructors {{{
    protected:

    Datatype();
    // Constructors }}}
    // Fields {{{
    public:

    virtual hid_t getDatatypeId() const = 0;
    // Fields }}}
    // Operations {{{
    //   Compound {{{
    protected:

    void insert(char const* name, size_t offset, Datatype const& datatype);
    //   Compound }}}
    //     Generic {{{
    public:

    TransientDatatype copy();

    protected:

    void lock();
    //     Generic }}}
    // Operations }}}
    // Operators {{{
    bool operator==(Datatype const& other);
    // Operators }}}
};
// Datatype }}}
// MutableDatatype {{{
class MutableDatatype: public Datatype {
    // Constructors {{{
    protected:

    MutableDatatype();
    // Constructors }}}
    // Operators {{{
    public:

    void insert(char const* name, size_t offset, Datatype const& datatype);
    // Operators }}}
};
// MutableDatatype }}}
// TransientDatatype {{{
class TransientDatatype: public MutableDatatype, public Identified {
    // Constructors {{{
    public:

    TransientDatatype(CopyOf<Datatype const> other);

    TransientDatatype(H5T_class_t class_id, size_t size);
    // Constructors }}}
    // Fields {{{
    public:

    virtual hid_t getDatatypeId() const;
    // Fields }}}
};
// TransientDatatype }}}
// PermanentDatatype {{{
class PermanentDatatype: public Datatype {
    // Constructors {{{
    public:

    PermanentDatatype(hid_t id);
    // Constructors }}}
    // Fields {{{
    protected:

    hid_t id;

    public:

    virtual hid_t getDatatypeId() const;
    // Fields }}}
};
// PermanentDatatype }}}
// Classes }}}

// Type functions {{{
// datatypeOf {{{
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
// datatypeOf }}}
// Type functions }}}

}

#endif
