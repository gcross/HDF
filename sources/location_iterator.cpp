//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2953: * @file location_iterator.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.2955: ** << Includes >>
#include "implementation/location_iterator.hpp"

#include <boost/lexical_cast.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2956: ** << Usings >>
using boost::lexical_cast;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2963: ** class LocationIterator
//@+node:gcross.20110521115623.2964: *3* Constructors
LocationIterator::LocationIterator() {}

LocationIterator::LocationIterator(Locatable const& parent, int index, int direction)
  : location(parent.getLocation())
  , index(index)
  , direction(direction)
{
    updateMyLocation();
}
//@+node:gcross.20110521115623.2966: *3* Facade requirements
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
//@+node:gcross.20110521115623.2967: *3* Miscellaneous
void LocationIterator::updateMyLocation() {
    location %= lexical_cast<string>(index);
}
//@-others

}
//@-leo
