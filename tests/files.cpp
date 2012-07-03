// Includes {{{
#include "dataset.hpp"
#include "temporary_memory_file.hpp"

#include <boost/assign/list_of.hpp>
#include <illuminate.hpp>
// Includes }}}

// Usings {{{
using HDF::createAt;
using HDF::Dataset;
using HDF::rangeOf;
using HDF::TemporaryMemoryFile;

using boost::assign::list_of;
// Usings }}}

// Helper Functions {{{
bool fileIdIsInvalid(hid_t id) {
    bool result = H5Fclose(id) < 0;
    H5Eclear2(H5Eget_current_stack());
    return result;
}
// Helper Functions }}}

TEST_SUITE(Files) { // {{{
TEST_SUITE(Closing) { // {{{
TEST_CASE(trivial_case) { // {{{
    hid_t id = TemporaryMemoryFile().getId();
    ASSERT_TRUE(fileIdIsInvalid(id));
} // }}}
TEST_CASE(after_creating_dataset) { // {{{
    hid_t id;
    {
        TemporaryMemoryFile file;
        Dataset(createAt(file / "x marks the spot"),rangeOf(list_of(1)));
        id = file.getId();
    }
    ASSERT_TRUE(fileIdIsInvalid(id));
} // }}}
} // }}}
} // }}}
