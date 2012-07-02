
// License {{{
/*
Copyright (c) 2011, Gregory Crosswhite
All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
// License }}}

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
