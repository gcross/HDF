// Includes {{{
#include "implementation/location_iterator.hpp"

#include <boost/lexical_cast.hpp>
#include <string>
// Includes }}}

// Usings {{{
using boost::lexical_cast;

using std::string;
// Usings }}}

namespace HDF {

// class LocationIterator {{{
// Constructors {{{
LocationIterator::LocationIterator() {}

LocationIterator::LocationIterator(Locatable const& parent, int index, int direction)
  : location(parent.getLocation())
  , index(index)
  , direction(direction)
{
    updateMyLocation();
}
// Constructors }}}
// Facade requirements {{{
Location const& LocationIterator::dereference() const { return location; }

bool LocationIterator::equal(LocationIterator const& other) const {
    return index == other.index
        && location.getParentId() == other.location.getParentId()
        && location.getFile() == other.location.getFile()
           ;
}

void LocationIterator::increment() { advance(1); }
void LocationIterator::decrement() { advance(-1); }
void LocationIterator::advance(int n) { index += n*direction; updateMyLocation(); }

int LocationIterator::distance_to(LocationIterator const& other) const {
    return (other.index - index)*direction;
}
// Facade requirements }}}
// Miscellaneous {{{
void LocationIterator::updateMyLocation() {
    location %= lexical_cast<string>(index);
}
// Miscellaneous }}}
// class LocationIterator }}}

}
