// Includes {{{
#include "dataspace.hpp"

#include <boost/assign/list_of.hpp>
#include <boost/range/algorithm/equal.hpp>
#include <illuminate.hpp>
// Includes }}}

// Usings {{{
using HDF::Dataspace;
using HDF::NullSpace;
using HDF::ScalarSpace;

using boost::assign::list_of;
using boost::equal;

using std::vector;
// Usings }}}

// Helper Functions {{{
bool dataspaceIsClosed(hid_t id) { // {{{
    bool result = H5Sclose(id) < 0;
    H5Eclear2(H5Eget_current_stack());
    return result;
} // }}}
// Helper Functions }}}
TEST_SUITE(Dataspace) { // {{{
TEST_SUITE(constructors) { // {{{
TEST_CASE(null) { hid_t id; { // {{{
    Dataspace dataspace(NullSpace);
    id = dataspace.getId();
    ASSERT_EQ(0u,dataspace.dimensions().size());
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_CASE(scalar) { hid_t id; { // {{{
    Dataspace dataspace(ScalarSpace);
    id = dataspace.getId();
    ASSERT_EQ(0u,dataspace.rank());
    ASSERT_EQ(1u,dataspace.size());
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_SUITE(simple) { // {{{
TEST_CASE(rank_and_ptrs_to_both_dimensions) { hid_t id; { // {{{
    hsize_t current[] = {1,2}, maximum[] = {3,4};
    Dataspace dataspace(2,current,maximum);
    id = dataspace.getId();
    ASSERT_EQ(2u,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),maximum));
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_CASE(rank_and_ptr_to_current_dimensions) { hid_t id; { // {{{
    hsize_t current[] = {1,2};
    Dataspace dataspace(2,current);
    id = dataspace.getId();
    ASSERT_EQ(2u,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),current));
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_CASE(vector_with_current_dimensions) { hid_t id; { // {{{
    vector<hsize_t> current = list_of(1)(2);
    Dataspace dataspace(current);
    id = dataspace.getId();
    ASSERT_EQ(2u,dataspace.rank());
    ASSERT_TRUE(equal(dataspace.dimensions(),current));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),current));
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_CASE(dimension) { hid_t id; { // {{{
    Dataspace dataspace(42);
    id = dataspace.getId();
    ASSERT_TRUE(equal(dataspace.dimensions(),list_of(42)));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),list_of(42)));
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
TEST_CASE(dimension_and_maximum) { hid_t id; { // {{{
    Dataspace dataspace(24,42);
    id = dataspace.getId();
    ASSERT_TRUE(equal(dataspace.dimensions(),list_of(24)));
    ASSERT_TRUE(equal(dataspace.maximumDimensions(),list_of(42)));
} ASSERT_TRUE(dataspaceIsClosed(id)); } // }}}
} // }}}
} // }}}
} // }}}
