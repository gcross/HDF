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
#include "temporary_memory_file.hpp"

#include <hdf5_hl.h>
#include <illuminate.hpp>
// Includes }}}

// Usings {{{
using namespace HDF;

using boost::none;
using boost::optional;

using std::string;
// Usings }}}

TEST_SUITE(Attributes) { // {{{
TEST_SUITE(Required) { // {{{
TEST_SUITE(char) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        char data = 'c';
        H5LTset_attribute_char(file.getId(),".","x",&data,1);
        data = ' ';
        data = file["x"];
        ASSERT_EQ('c',data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 'c';
        char data;
        H5LTget_attribute_char(file.getId(),".","x",&data);
        ASSERT_EQ('c',data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<char>('c');
        ASSERT_EQ('c',static_cast<char>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(unsigned_char) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        unsigned char data = 7;
        H5LTset_attribute_uchar(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(7,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 7;
        unsigned char data;
        H5LTget_attribute_uchar(file.getId(),".","x",&data);
        ASSERT_EQ(7,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned char>(7);
        ASSERT_EQ(7,static_cast<unsigned char>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(short) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        short data = -7;
        H5LTset_attribute_short(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-7,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = -7;
        short data;
        H5LTget_attribute_short(file.getId(),".","x",&data);
        ASSERT_EQ(-7,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<short>(-7);
        ASSERT_EQ(-7,static_cast<short>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(unsigned_short) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        unsigned short data = 7;
        H5LTset_attribute_ushort(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(7,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 7;
        unsigned short data;
        H5LTget_attribute_ushort(file.getId(),".","x",&data);
        ASSERT_EQ(7,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned short>(7);
        ASSERT_EQ(7,static_cast<unsigned short>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(int) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        int data = -42;
        H5LTset_attribute_int(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = -42;
        int data;
        H5LTget_attribute_int(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<int>(-42);
        ASSERT_EQ(-42,static_cast<int>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(unsigned_int) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        unsigned int data = 42;
        H5LTset_attribute_uint(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(42u,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 42;
        unsigned int data;
        H5LTget_attribute_uint(file.getId(),".","x",&data);
        ASSERT_EQ(42u,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned int>(42);
        ASSERT_EQ(42u,static_cast<unsigned int>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(long) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        long data = -42;
        H5LTset_attribute_long(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = -42;
        long data;
        H5LTget_attribute_long(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<long>(-42);
        ASSERT_EQ(-42,static_cast<long>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(unsigned_long) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        unsigned long data = 42;
        H5LTset_attribute_ulong(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(42u,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 42;
        unsigned long data;
        H5LTget_attribute_ulong(file.getId(),".","x",&data);
        ASSERT_EQ(42u,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned long>(42);
        ASSERT_EQ(42u,static_cast<unsigned long>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(long_long) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        long long data = -42;
        H5LTset_attribute_long_long(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = -42;
        long long data;
        H5LTget_attribute_long_long(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<long long>(-42);
        ASSERT_EQ(-42,static_cast<long long>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(float) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        float data = 3.14f;
        H5LTset_attribute_float(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(3.14f,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 3.14f;
        float data;
        H5LTget_attribute_float(file.getId(),".","x",&data);
        ASSERT_EQ(3.14f,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<float>(3.14f);
        ASSERT_EQ(3.14f,static_cast<float>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(double) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        double data = 3.14;
        H5LTset_attribute_double(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(3.14,data);
    } // }}}
    TEST_CASE(encode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = 3.14;
        double data;
        H5LTget_attribute_double(file.getId(),".","x",&data);
        ASSERT_EQ(3.14,data);
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = static_cast<double>(3.14);
        ASSERT_EQ(3.14,static_cast<double>(file["x"]));
    } // }}}
} // }}}
TEST_SUITE(string) { // {{{
    TEST_CASE(decode) { // {{{
        TemporaryMemoryFile file;
        H5LTset_attribute_string(file.getId(),".","x","hello, world!");
        ASSERT_EQ("hello, world!",static_cast<string const&>(file["x"]));
    } // }}}
    TEST_CASE(encode_than_decode) { // {{{
        TemporaryMemoryFile file;
        file["x"] = "hello, world!";
        string s = file["x"];
        ASSERT_EQ("hello, world!",s);
    } // }}}
} // }}}
} // }}}
TEST_SUITE(Optional) { // {{{
TEST_SUITE(char) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<char>(none);
        optional<char> result = file["x"];
        ASSERT_EQ(optional<char>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<char>(42);
        ASSERT_EQ(optional<char>(42),file["x"].get<optional<char> >());
    } // }}}
} // }}}
TEST_SUITE(unsigned_char) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned char>(none);
        optional<unsigned char> result = file["x"];
        ASSERT_EQ(optional<unsigned char>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned char>(42);
        ASSERT_EQ(optional<unsigned char>(42),file["x"].get<optional<unsigned char> >());
    } // }}}
} // }}}
TEST_SUITE(short) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<short>(none);
        optional<short> result = file["x"];
        ASSERT_EQ(optional<short>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<short>(42);
        ASSERT_EQ(optional<short>(42),file["x"].get<optional<short> >());
    } // }}}
} // }}}
TEST_SUITE(unsigned_short) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned short>(none);
        optional<unsigned short> result = file["x"];
        ASSERT_EQ(optional<unsigned short>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned short>(42);
        ASSERT_EQ(optional<unsigned short>(42),file["x"].get<optional<unsigned short> >());
    } // }}}
} // }}}
TEST_SUITE(int) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<int>(none);
        optional<int> result = file["x"];
        ASSERT_EQ(optional<int>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<int>(42);
        ASSERT_EQ(optional<int>(42),file["x"].get<optional<int> >());
    } // }}}
} // }}}
TEST_SUITE(unsigned_int) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned int>(none);
        optional<unsigned int> result = file["x"];
        ASSERT_EQ(optional<unsigned int>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned int>(42);
        ASSERT_EQ(optional<unsigned int>(42),file["x"].get<optional<unsigned int> >());
    } // }}}
} // }}}
TEST_SUITE(long) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<long>(none);
        optional<long> result = file["x"];
        ASSERT_EQ(optional<long>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<long>(42);
        ASSERT_EQ(optional<long>(42),file["x"].get<optional<long> >());
    } // }}}
} // }}}
TEST_SUITE(unsigned_long) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned long>(none);
        optional<unsigned long> result = file["x"];
        ASSERT_EQ(optional<unsigned long>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned long>(42);
        ASSERT_EQ(optional<unsigned long>(42),file["x"].get<optional<unsigned long> >());
    } // }}}
} // }}}
TEST_SUITE(long_long) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<long long>(none);
        optional<long long> result = file["x"];
        ASSERT_EQ(optional<long long>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<long long>(42);
        ASSERT_EQ(optional<long long>(42),file["x"].get<optional<long long> >());
    } // }}}
} // }}}
TEST_SUITE(float) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<float>(none);
        optional<float> result = file["x"];
        ASSERT_EQ(optional<float>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<float>(3.14f);
        ASSERT_EQ(optional<float>(3.14f),file["x"].get<optional<float> >());
    } // }}}
} // }}}
TEST_SUITE(double) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<double>(none);
        optional<double> result = file["x"];
        ASSERT_EQ(optional<double>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<double>(3.14);
        ASSERT_EQ(optional<double>(3.14),file["x"].get<optional<double> >());
    } // }}}
} // }}}
TEST_SUITE(string) { // {{{
    TEST_CASE(none) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<string>(none);
        optional<string> result = file["x"];
        ASSERT_EQ(optional<string>(none),result);
    } // }}}
    TEST_CASE(some) { // {{{
        TemporaryMemoryFile file;
        file["x"] = optional<string>("hello, world!");
        ASSERT_EQ(optional<string>("hello, world!"),file["x"].get<optional<string> >());
    } // }}}
} // }}}
} // }}}
} // }}}

