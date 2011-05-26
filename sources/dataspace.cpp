//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3137: * @file dataspace.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.3138: ** << License >>
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
//@+node:gcross.20110521115623.3139: ** << Includes >>
#include "dataset.hpp"
#include "dataspace.hpp"
#include "error.hpp"

#include <boost/format.hpp>
#include <boost/make_shared.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3140: ** << Usings >>
using boost::format;
using boost::make_shared;
using boost::optional;

using std::vector;
//@-<< Usings >>

//@+others
//@+node:gcross.20110523113700.2379: ** Exceptions
//@+node:gcross.20110523113700.2380: *3* UnexpectedTensorRankException
UnexpectedTensorRankException::UnexpectedTensorRankException(unsigned int const expected_rank, unsigned int const actual_rank)
  : Exception((format("Expected a tensor with rank %1% but encountered a tensor with rank %2%.") % expected_rank % actual_rank).str())
  , expected_rank(expected_rank)
  , actual_rank(actual_rank)
{}
//@+node:gcross.20110521115623.3144: ** Dataspace
//@+node:gcross.20110521115623.3146: *3* Constructors
Dataspace::Dataspace(CopyOf<Dataspace const> other)
  : Identifiable(
        assertSuccess(
            "copying dataspace",
            H5Scopy(other->getId())
        ),
        H5Sclose
    )
{}

Dataspace::Dataspace(Dataset const& dataset)
  : Identifiable(
        assertSuccess(
            "opening dataspace of dataset",
            H5Dget_space(dataset.getId())
        ),
        H5Sclose
    )
{}

Dataspace::Dataspace(DataspaceClass cls)
  : Identifiable(
        assertSuccess(
            "creating empty dataspace",
            H5Screate(static_cast<H5S_class_t>(cls))
        ),
        H5Sclose
    )
{}

Dataspace::Dataspace(unsigned int rank, hsize_t const* current_dimensions) {
    createAndInitializeSimple(rank,current_dimensions,current_dimensions);
}

Dataspace::Dataspace(unsigned int rank, hsize_t const* current_dimensions, hsize_t const* maximum_dimensions) {
    createAndInitializeSimple(rank,current_dimensions,maximum_dimensions);
}

Dataspace::Dataspace(vector<hsize_t> const& dimensions) {
    createAndInitializeSimple(dimensions.size(),&dimensions.front(),&dimensions.front());
}

Dataspace::Dataspace(hsize_t dimension) {
    createAndInitializeSimple(1,&dimension,&dimension);
}

Dataspace::Dataspace(hsize_t current_dimension, hsize_t maximum_dimension) {
    createAndInitializeSimple(1,&current_dimension,&maximum_dimension);
}

void Dataspace::createAndInitializeSimple(unsigned int rank,hsize_t const* current_dimensions,hsize_t const* maximum_dimensions) {
    identity =
        make_shared<Identity>(
            assertSuccess(
                "creating simple dataspace",
                H5Screate_simple(rank,current_dimensions,maximum_dimensions)
            ),
            H5Sclose
        );
}
//@+node:gcross.20110523113700.2382: *3* Informational
vector<hsize_t> Dataspace::dimensions() const {
    vector<hsize_t> dims(rank());
    assertSuccess(
        "reading dataspace dimensions",
        H5Sget_simple_extent_dims(getId(),&dims.front(),NULL)
    );
    return dims;
}

vector<hsize_t> Dataspace::dimensionsWithAssertedRank(unsigned int const expected_rank) const {
    unsigned int const actual_rank = rank();
    if(expected_rank != actual_rank)
        throw UnexpectedTensorRankException(expected_rank,actual_rank);
    else
        return dimensions();
}

vector<hsize_t> Dataspace::maximumDimensions() const {
    vector<hsize_t> dims(rank());
    assertSuccess(
        "reading dataspace maximum dimensions",
        H5Sget_simple_extent_dims(getId(),NULL,&dims.front())
    );
    return dims;
}

unsigned int Dataspace::rank() const {
    return
        assertSuccess(
            "obtaining dataspace rank",
            H5Sget_simple_extent_ndims(getId())
        );
}

unsigned int Dataspace::selectedSize() const {
    return
        assertSuccess(
            "obtaining dataspace selection size",
            H5Sget_select_npoints(getId())
        );
}

unsigned int Dataspace::size() const {
    return
        assertSuccess(
            "obtaining dataspace size",
            H5Sget_simple_extent_npoints(getId())
        );
}
//@+node:gcross.20110521115623.4249: ** Function
//@+node:gcross.20110521115623.4250: *3* getOptionalDataspaceId
hid_t getOptionalDataspaceId(optional<Dataspace const&> const& dataspace) {
    if(dataspace)
        return dataspace->getId();
    else
        return H5S_ALL;
}
//@-others

}
//@-leo
