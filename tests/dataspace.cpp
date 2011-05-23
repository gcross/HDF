//@+leo-ver=5-thin
//@+node:gcross.20110525201928.3072: * @file dataspace.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110525201928.3073: ** << License >>
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
//@+node:gcross.20110525201928.3074: ** << Includes >>
#include "dataspace.hpp"

#include <boost/assign/list_of.hpp>
#include <boost/range/algorithm/equal.hpp>
#include <illuminate.hpp>
//@-<< Includes >>

//@+<< Usings >>
//@+node:gcross.20110525201928.3075: ** << Usings >>
using HDF::Dataspace;

using boost::assign::list_of;
using boost::equal;

using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110525201928.3080: ** Functions
//@+node:gcross.20110525201928.3081: *3* dataspaceIsClosed
bool dataspaceIsClosed(hid_t id) {
    bool result = H5Sclose(id) < 0;
    H5Eclear(H5Eget_current_stack());
    return result;
}
//@+node:gcross.20110525201928.3076: ** Tests
TEST_SUITE(Dataspace) {

//@+others
//@+node:gcross.20110525201928.3084: *3* constructors
TEST_SUITE(constructors) {

//@+others
//@+node:gcross.20110525201928.3077: *4* null
TEST_CASE(null) { hid_t id; {
    Dataspace dataspace(Dataspace::NullSpace);
    id = dataspace.getId();
    ASSERT_EQ(0,dataspace.dimensions().size());
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3083: *4* scalar
TEST_CASE(scalar) { hid_t id; {
    Dataspace dataspace(Dataspace::ScalarSpace);
    id = dataspace.getId();
    ASSERT_EQ(0,dataspace.rank());
    ASSERT_EQ(1,dataspace.size());
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3086: *4* simple
TEST_SUITE(simple) {

//@+others
//@+node:gcross.20110525201928.3088: *5* rank and ptrs to both dimensions
TEST_CASE(rank_and_ptrs_to_both_dimensions) { hid_t id; {
    hsize_t current[] = {1,2}, maximum[] = {3,4};
    Dataspace dataspace(2,current,maximum);
    id = dataspace.getId();
    ASSERT_EQ(2,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),maximum));
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3090: *5* rank and ptr to current dimensions
TEST_CASE(rank_and_ptr_to_current_dimensions) { hid_t id; {
    hsize_t current[] = {1,2};
    Dataspace dataspace(2,current);
    id = dataspace.getId();
    ASSERT_EQ(2,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),current));
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3092: *5* vector with current dimensions
TEST_CASE(vector_with_current_dimensions) { hid_t id; {
    vector<hsize_t> current = list_of(1)(2);
    Dataspace dataspace(current);
    id = dataspace.getId();
    ASSERT_EQ(2,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),current));
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3094: *5* dimension
TEST_CASE(dimension) { hid_t id; {
    Dataspace dataspace(42);
    id = dataspace.getId();
    ASSERT_TRUE(equal(dataspace.dimensions(),list_of(42)));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),list_of(42)));
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@+node:gcross.20110525201928.3096: *5* dimension_and_maximum
TEST_CASE(dimension_and_maximum) { hid_t id; {
    Dataspace dataspace(24,42);
    id = dataspace.getId();
    ASSERT_TRUE(equal(dataspace.dimensions(),list_of(24)));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),list_of(42)));
} ASSERT_TRUE(dataspaceIsClosed(id)); }
//@-others

}
//@-others

}
//@-others

}
//@-others
//@-leo
