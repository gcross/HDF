//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3028: * @file dataspace.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_DATASPACE_HPP
#define HDFPP_IMPLEMENTATION_DATASPACE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3029: ** << Includes >>
#include "enumerations.hpp"
#include "error.hpp"
#include "identified.hpp"
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

class Dataspace: public Identified {
//@+others
//@+node:gcross.20110521115623.3131: *3* Constructors
public:

Dataspace(CopyOf<Dataspace const> other);
Dataspace(DataspaceClass cls);
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
