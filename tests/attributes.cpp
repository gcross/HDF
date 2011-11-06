//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3235: * @file attributes.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3236: ** << License >>
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
//@+node:gcross.20110521115623.3237: ** << Includes >>
#include "temporary_memory_file.hpp"

#include <hdf5_hl.h>
#include <illuminate.hpp>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110521115623.3238: ** << Usings >>
using namespace HDF;

using boost::none;
using boost::optional;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3239: ** Tests
TEST_SUITE(Attributes) {

//@+others
//@+node:gcross.20110521115623.3733: *3* Required
TEST_SUITE(Required) {

//@+others
//@+node:gcross.20110521115623.3240: *4* char
TEST_SUITE(char) {
    //@+others
    //@+node:gcross.20110523113700.1710: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        char data = 'c';
        H5LTset_attribute_char(file.getId(),".","x",&data,1);
        data = ' ';
        data = file["x"];
        ASSERT_EQ('c',data);
    }
    //@+node:gcross.20110521115623.3241: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 'c';
        char data;
        H5LTget_attribute_char(file.getId(),".","x",&data);
        ASSERT_EQ('c',data);
    }
    //@+node:gcross.20110523113700.1712: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<char>('c');
        ASSERT_EQ('c',static_cast<char>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1717: *4* unsigned char
TEST_SUITE(unsigned_char) {
    //@+others
    //@+node:gcross.20110523113700.1718: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        unsigned char data = 7;
        H5LTset_attribute_uchar(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(7,data);
    }
    //@+node:gcross.20110523113700.1719: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 7;
        unsigned char data;
        H5LTget_attribute_uchar(file.getId(),".","x",&data);
        ASSERT_EQ(7,data);
    }
    //@+node:gcross.20110523113700.1720: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned char>(7);
        ASSERT_EQ(7,static_cast<unsigned char>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1725: *4* short
TEST_SUITE(short) {
    //@+others
    //@+node:gcross.20110523113700.1726: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        short data = -7;
        H5LTset_attribute_short(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-7,data);
    }
    //@+node:gcross.20110523113700.1727: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = -7;
        short data;
        H5LTget_attribute_short(file.getId(),".","x",&data);
        ASSERT_EQ(-7,data);
    }
    //@+node:gcross.20110523113700.1728: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<short>(-7);
        ASSERT_EQ(-7,static_cast<short>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1733: *4* unsigned short
TEST_SUITE(unsigned_short) {
    //@+others
    //@+node:gcross.20110523113700.1734: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        unsigned short data = 7;
        H5LTset_attribute_ushort(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(7,data);
    }
    //@+node:gcross.20110523113700.1735: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 7;
        unsigned short data;
        H5LTget_attribute_ushort(file.getId(),".","x",&data);
        ASSERT_EQ(7,data);
    }
    //@+node:gcross.20110523113700.1736: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned short>(7);
        ASSERT_EQ(7,static_cast<unsigned short>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1741: *4* int
TEST_SUITE(int) {
    //@+others
    //@+node:gcross.20110523113700.1742: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        int data = -42;
        H5LTset_attribute_int(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1743: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = -42;
        int data;
        H5LTget_attribute_int(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1744: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<int>(-42);
        ASSERT_EQ(-42,static_cast<int>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1749: *4* unsigned int
TEST_SUITE(unsigned_int) {
    //@+others
    //@+node:gcross.20110523113700.1750: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        unsigned int data = 42;
        H5LTset_attribute_uint(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(42u,data);
    }
    //@+node:gcross.20110523113700.1751: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 42;
        unsigned int data;
        H5LTget_attribute_uint(file.getId(),".","x",&data);
        ASSERT_EQ(42u,data);
    }
    //@+node:gcross.20110523113700.1752: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned int>(42);
        ASSERT_EQ(42u,static_cast<unsigned int>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1757: *4* long
TEST_SUITE(long) {
    //@+others
    //@+node:gcross.20110523113700.1758: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        long data = -42;
        H5LTset_attribute_long(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1759: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = -42;
        long data;
        H5LTget_attribute_long(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1760: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<long>(-42);
        ASSERT_EQ(-42,static_cast<long>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1765: *4* unsigned long
TEST_SUITE(unsigned_long) {
    //@+others
    //@+node:gcross.20110523113700.1766: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        unsigned long data = 42;
        H5LTset_attribute_ulong(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(42u,data);
    }
    //@+node:gcross.20110523113700.1767: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 42;
        unsigned long data;
        H5LTget_attribute_ulong(file.getId(),".","x",&data);
        ASSERT_EQ(42u,data);
    }
    //@+node:gcross.20110523113700.1768: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<unsigned long>(42);
        ASSERT_EQ(42u,static_cast<unsigned long>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1773: *4* long long
TEST_SUITE(long_long) {
    //@+others
    //@+node:gcross.20110523113700.1774: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        long long data = -42;
        H5LTset_attribute_long_long(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1775: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = -42;
        long long data;
        H5LTget_attribute_long_long(file.getId(),".","x",&data);
        ASSERT_EQ(-42,data);
    }
    //@+node:gcross.20110523113700.1776: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<long long>(-42);
        ASSERT_EQ(-42,static_cast<long long>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1781: *4* float
TEST_SUITE(float) {
    //@+others
    //@+node:gcross.20110523113700.1782: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        float data = 3.14f;
        H5LTset_attribute_float(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(3.14f,data);
    }
    //@+node:gcross.20110523113700.1783: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 3.14f;
        float data;
        H5LTget_attribute_float(file.getId(),".","x",&data);
        ASSERT_EQ(3.14f,data);
    }
    //@+node:gcross.20110523113700.1784: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<float>(3.14f);
        ASSERT_EQ(3.14f,static_cast<float>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1789: *4* double
TEST_SUITE(double) {
    //@+others
    //@+node:gcross.20110523113700.1790: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        double data = 3.14;
        H5LTset_attribute_double(file.getId(),".","x",&data,1);
        data = 0;
        data = file["x"];
        ASSERT_EQ(3.14,data);
    }
    //@+node:gcross.20110523113700.1791: *5* encode
    TEST_CASE(encode) {
        TemporaryMemoryFile file;
        file["x"] = 3.14;
        double data;
        H5LTget_attribute_double(file.getId(),".","x",&data);
        ASSERT_EQ(3.14,data);
    }
    //@+node:gcross.20110523113700.1792: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = static_cast<double>(3.14);
        ASSERT_EQ(3.14,static_cast<double>(file["x"]));
    }
    //@-others
}
//@+node:gcross.20110523113700.1797: *4* string
TEST_SUITE(string) {
    //@+others
    //@+node:gcross.20110523113700.1798: *5* decode
    TEST_CASE(decode) {
        TemporaryMemoryFile file;
        H5LTset_attribute_string(file.getId(),".","x","hello, world!");
        ASSERT_EQ("hello, world!",static_cast<string const&>(file["x"]));
    }
    //@+node:gcross.20110523113700.1800: *5* encode than decode
    TEST_CASE(encode_than_decode) {
        TemporaryMemoryFile file;
        file["x"] = "hello, world!";
        string s = file["x"];
        ASSERT_EQ("hello, world!",s);
    }
    //@-others
}
//@-others

}
//@+node:gcross.20110521115623.3932: *3* Optional
TEST_SUITE(Optional) {

//@+others
//@+node:gcross.20110521115623.3879: *4* char
TEST_SUITE(char) {
    //@+others
    //@+node:gcross.20110521115623.3931: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<char>(none);
        optional<char> result = file["x"];
        ASSERT_EQ(optional<char>(none),result);
    }
    //@+node:gcross.20110521115623.3882: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<char>(42);
        ASSERT_EQ(optional<char>(42),file["x"].get<optional<char> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4182: *4* unsigned char
TEST_SUITE(unsigned_char) {
    //@+others
    //@+node:gcross.20110521115623.4183: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned char>(none);
        optional<unsigned char> result = file["x"];
        ASSERT_EQ(optional<unsigned char>(none),result);
    }
    //@+node:gcross.20110521115623.4184: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned char>(42);
        ASSERT_EQ(optional<unsigned char>(42),file["x"].get<optional<unsigned char> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4188: *4* short
TEST_SUITE(short) {
    //@+others
    //@+node:gcross.20110521115623.4189: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<short>(none);
        optional<short> result = file["x"];
        ASSERT_EQ(optional<short>(none),result);
    }
    //@+node:gcross.20110521115623.4190: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<short>(42);
        ASSERT_EQ(optional<short>(42),file["x"].get<optional<short> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4194: *4* unsigned short
TEST_SUITE(unsigned_short) {
    //@+others
    //@+node:gcross.20110521115623.4195: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned short>(none);
        optional<unsigned short> result = file["x"];
        ASSERT_EQ(optional<unsigned short>(none),result);
    }
    //@+node:gcross.20110521115623.4196: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned short>(42);
        ASSERT_EQ(optional<unsigned short>(42),file["x"].get<optional<unsigned short> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4200: *4* int
TEST_SUITE(int) {
    //@+others
    //@+node:gcross.20110521115623.4201: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<int>(none);
        optional<int> result = file["x"];
        ASSERT_EQ(optional<int>(none),result);
    }
    //@+node:gcross.20110521115623.4202: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<int>(42);
        ASSERT_EQ(optional<int>(42),file["x"].get<optional<int> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4206: *4* unsigned int
TEST_SUITE(unsigned_int) {
    //@+others
    //@+node:gcross.20110521115623.4207: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned int>(none);
        optional<unsigned int> result = file["x"];
        ASSERT_EQ(optional<unsigned int>(none),result);
    }
    //@+node:gcross.20110521115623.4208: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned int>(42);
        ASSERT_EQ(optional<unsigned int>(42),file["x"].get<optional<unsigned int> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4212: *4* long
TEST_SUITE(long) {
    //@+others
    //@+node:gcross.20110521115623.4213: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<long>(none);
        optional<long> result = file["x"];
        ASSERT_EQ(optional<long>(none),result);
    }
    //@+node:gcross.20110521115623.4214: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<long>(42);
        ASSERT_EQ(optional<long>(42),file["x"].get<optional<long> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4218: *4* unsigned long
TEST_SUITE(unsigned_long) {
    //@+others
    //@+node:gcross.20110521115623.4219: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned long>(none);
        optional<unsigned long> result = file["x"];
        ASSERT_EQ(optional<unsigned long>(none),result);
    }
    //@+node:gcross.20110521115623.4220: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<unsigned long>(42);
        ASSERT_EQ(optional<unsigned long>(42),file["x"].get<optional<unsigned long> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4224: *4* long long
TEST_SUITE(long_long) {
    //@+others
    //@+node:gcross.20110521115623.4225: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<long long>(none);
        optional<long long> result = file["x"];
        ASSERT_EQ(optional<long long>(none),result);
    }
    //@+node:gcross.20110521115623.4226: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<long long>(42);
        ASSERT_EQ(optional<long long>(42),file["x"].get<optional<long long> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4230: *4* float
TEST_SUITE(float) {
    //@+others
    //@+node:gcross.20110521115623.4231: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<float>(none);
        optional<float> result = file["x"];
        ASSERT_EQ(optional<float>(none),result);
    }
    //@+node:gcross.20110521115623.4232: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<float>(3.14f);
        ASSERT_EQ(optional<float>(3.14f),file["x"].get<optional<float> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4236: *4* double
TEST_SUITE(double) {
    //@+others
    //@+node:gcross.20110521115623.4237: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<double>(none);
        optional<double> result = file["x"];
        ASSERT_EQ(optional<double>(none),result);
    }
    //@+node:gcross.20110521115623.4238: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<double>(3.14);
        ASSERT_EQ(optional<double>(3.14),file["x"].get<optional<double> >());
    }
    //@-others
}
//@+node:gcross.20110521115623.4242: *4* string
TEST_SUITE(string) {
    //@+others
    //@+node:gcross.20110521115623.4243: *5* none
    TEST_CASE(none) {
        TemporaryMemoryFile file;
        file["x"] = optional<string>(none);
        optional<string> result = file["x"];
        ASSERT_EQ(optional<string>(none),result);
    }
    //@+node:gcross.20110521115623.4244: *5* some
    TEST_CASE(some) {
        TemporaryMemoryFile file;
        file["x"] = optional<string>("hello, world!");
        ASSERT_EQ(optional<string>("hello, world!"),file["x"].get<optional<string> >());
    }
    //@-others
}
//@-others

}
//@-others

}
//@-others
//@-leo
