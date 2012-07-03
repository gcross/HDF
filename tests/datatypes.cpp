// Includes {{{
#include "datatype.hpp"

#include <complex>
#include <illuminate.hpp>
// Includes }}}

// Usings {{{
using HDF::datatypeOf;

using std::complex;
// Usings }}}

TEST_SUITE(Datatypes) { // {{{
TEST_SUITE(complex_types_created_properly) { // {{{

#define TEST_TYPE(name,type) TEST_CASE(name) { datatypeOf<std::complex<type> >::get(); }

TEST_TYPE(char,char)
TEST_TYPE(unsigned_char,unsigned char)
TEST_TYPE(short,short)
TEST_TYPE(unsigned_short,unsigned short)
TEST_TYPE(int,int)
TEST_TYPE(unsigned_int,unsigned int)
TEST_TYPE(long,long)
TEST_TYPE(unsigned_long,unsigned long)
TEST_TYPE(long_long,long long)
TEST_TYPE(float,float)
TEST_TYPE(double,double)

} // }}}
} // }}}
