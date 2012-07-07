#ifndef HDFPP_IMPLEMENTATION_DATASPACE_HPP
#define HDFPP_IMPLEMENTATION_DATASPACE_HPP

// Includes {{{
#include "enumerations.hpp"
#include "error.hpp"
#include "identified.hpp"
#include "parameters.hpp"
#include "properties.hpp"
#include "utilities.hpp"

#include <hdf5.h>
#include <vector>
// Includes }}}

namespace HDF {

// Exceptions {{{
struct UnexpectedTensorRankException : public Exception { // {{{
    unsigned int expected_rank, actual_rank;
    UnexpectedTensorRankException(unsigned int const expected_rank, unsigned int const actual_rank);
}; // }}}
// Exceptions }}}

// Forward declarations {{{
class Dataset;
// Forward declarations }}}

class Dataspace: public Identified { // {{{
//   Constructors {{{
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
//   Constructors }}}
//   Informational {{{
public:

std::vector<hsize_t> dimensions() const;
std::vector<hsize_t> dimensionsWithAssertedRank(unsigned int expected_rank) const;
std::vector<hsize_t> maximumDimensions() const;
unsigned int rank() const;
unsigned int selectedSize() const;
unsigned int size() const;
//   Informational }}}
}; // }}}

// Functions {{{
hid_t getOptionalDataspaceId(boost::optional<Dataspace const&> const& dataspace);
// Functions }}}

}

#endif
