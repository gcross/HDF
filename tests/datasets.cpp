
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
