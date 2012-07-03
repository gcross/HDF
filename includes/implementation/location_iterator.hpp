//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2929: * @file location_iterator.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_LOCATION_ITERATOR_HPP
#define HDFPP_IMPLEMENTATION_LOCATION_ITERATOR_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2931: ** << Includes >>
#include "location.hpp"
#include "parameters.hpp"
#include "parent.hpp"

#include <boost/iterator/iterator_facade.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm/for_each.hpp>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2940: ** class LocationIterator
class LocationIterator
  : public boost::iterator_facade<
         LocationIterator
        ,Location const
        ,boost::random_access_traversal_tag
        ,Location const&
        ,int
    >
{
    //@+others
    //@+node:gcross.20110521115623.2941: *3* Constructors
    public:

    LocationIterator();
    LocationIterator(Locatable const& parent, int index=0, int direction=1);
    //@+node:gcross.20110521115623.2942: *3* Fields
    protected:

    Location location;
    int index, direction;
    //@+node:gcross.20110521115623.2943: *3* Facade requirements
    public:

    Location const& dereference() const;
    bool equal(LocationIterator const& other) const;
    void increment();
    void decrement();
    void advance(int n);
    int distance_to(LocationIterator const& other) const;
    //@+node:gcross.20110521115623.2944: *3* Miscellaneous
    protected:

    void updateMyLocation();
    //@+node:gcross.20110521115623.2945: *3* I/O
    public:

    template<typename T> LocationIterator& operator<<(T const& value) {
        dereference() << value;
        increment();
        return *this;
    }

    template<typename T> LocationIterator& operator>>(T& value) {
        dereference() >> value;
        increment();
        return *this;
    }

    template<typename T> LocationIterator& operator<<(RangeOf<T> values) {
        boost::for_each(*values,boost::lambda::var(*this) << boost::lambda::_1);
        return *this;
    }
    //@-others
};
//@-others

}

#endif
//@-leo
