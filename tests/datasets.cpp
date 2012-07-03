// Includes {{{
#include "dataset.hpp"
#include "temporary_memory_file.hpp"

#include <boost/assign/list_of.hpp>
#include <illuminate.hpp>
#include <vector>
// Includes }}}

// Usings {{{
using HDF::createAt;
using HDF::Dataset;
using HDF::Dataspace;
using HDF::datatypeOf;
using HDF::Location;
using HDF::rangeOf;
using HDF::TemporaryMemoryFile;

using boost::assign::list_of;

using std::vector;
// Usings }}}

TEST_SUITE(Datasets) { // {{{
TEST_SUITE(write_than_read) { // {{{
TEST_CASE(singleton) { // {{{
    TemporaryMemoryFile file;
    Location location(file / "here");
    Dataset dataset(createAt(location),datatypeOf<unsigned int>::get(),Dataspace(1));
    unsigned int one = 1;
    dataset.write(&one);
    one = 0;
    dataset.read(&one);
    ASSERT_EQ(1u,one);
} // }}}
TEST_CASE(singleton_using_ranges) { // {{{
    TemporaryMemoryFile file;
    Location location(file / "here");
    Dataset dataset(createAt(location),rangeOf(list_of(1u)));
    vector<unsigned int> data = dataset.readVector<unsigned int>();
    ASSERT_EQ(1u,data.size());
    ASSERT_EQ(1u,data[0]);
} // }}}
} // }}}
} // }}}
