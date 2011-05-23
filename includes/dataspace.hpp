//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3028: * @file dataspace.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3030: ** << License >>
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

#ifndef HDFPP_DATASPACE_HPP
#define HDFPP_DATASPACE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3029: ** << Includes >>
#include "error.hpp"
#include "identifiable.hpp"
#include "parameters.hpp"
#include "properties.hpp"
#include "utilities.hpp"

#include <hdf5.h>
#include <vector>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110523113700.2374: ** Exceptions
//@+node:gcross.20110523113700.2376: *3* UnexpectedTensorRankException
struct UnexpectedTensorRankException : public Exception {
    unsigned int expected_rank, actual_rank;
    UnexpectedTensorRankException(unsigned int const expected_rank, unsigned int const actual_rank);
};
//@+node:gcross.20110521115623.3130: ** Dataspace
//@+<< Forward declarations >>
//@+node:gcross.20110521115623.3149: *3* << Forward declarations >>
class Dataset;
//@-<< Forward declarations >>

class Dataspace: public Identifiable {
//@+<< Nested types >>
//@+node:gcross.20110521115623.3132: *3* << Nested types >>
public:

enum Class { ScalarSpace, SimpleSpace, NullSpace };

static H5S_class_t getClassId(Class cls);
//@-<< Nested types >>
//@+others
//@+node:gcross.20110521115623.3131: *3* Constructors
public:

Dataspace(CopyOf<Dataspace const> other);
Dataspace(Class cls);
Dataspace(Dataset const& dataset);
Dataspace(unsigned int rank, hsize_t const* current_dimensions);
Dataspace(unsigned int rank, hsize_t const* current_dimensions, hsize_t const* maximum_dimensions);
Dataspace(std::vector<hsize_t> const& dimensions);
Dataspace(hsize_t dimension);
Dataspace(hsize_t current_dimension, hsize_t maximum_dimension);

template<typename Dimensions> Dataspace(RangeOf<Dimensions> dimensions) {
    using namespace boost;
    HSizeArray dims(*dimensions);
    createAndInitializeSimple(dims.size,dims,dims);
}

protected:

void createAndInitializeSimple(
    unsigned int rank
  , hsize_t const* current_dimensions
  , hsize_t const* maximum_dimensions
);
//@+node:gcross.20110523113700.2373: *3* Informational
public:

std::vector<hsize_t> dimensions() const;
std::vector<hsize_t> dimensionsWithAssertedRank(unsigned int expected_rank) const;
std::vector<hsize_t> maximumDimensions() const;
unsigned int rank() const;
unsigned int selectedSize() const;
unsigned int size() const;
//@-others
};
//@+node:gcross.20110521115623.4245: ** Function
//@+node:gcross.20110521115623.4246: *3* getOptionalDataspaceId
hid_t getOptionalDataspaceId(boost::optional<Dataspace const&> const& dataspace);
//@-others

}

#endif
//@-leo
