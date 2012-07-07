#ifndef HDFPP_IMPLEMENTATION_LOCATION_ITERATOR_HPP
#define HDFPP_IMPLEMENTATION_LOCATION_ITERATOR_HPP

// Includes {{{
#include "location.hpp"
#include "parameters.hpp"
#include "parent.hpp"

#include <boost/iterator/iterator_facade.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/range/algorithm/for_each.hpp>
// Includes }}}

namespace HDF {

class LocationIterator // {{{
  : public boost::iterator_facade<
         LocationIterator
        ,Location const
        ,boost::random_access_traversal_tag
        ,Location const&
        ,int
    >
{
    // Constructors {{{
    public:

    LocationIterator();
    LocationIterator(Locatable const& parent, int index=0, int direction=1);
    // Constructors }}}
    // Fields {{{
    protected:

    Location location;
    int index, direction;
    // Fields }}}
    // Facade requirements {{{
    public:

    Location const& dereference() const;
    bool equal(LocationIterator const& other) const;
    void increment();
    void decrement();
    void advance(int n);
    int distance_to(LocationIterator const& other) const;
    // Facade requirements }}}
    // Miscellaneous {{{
    protected:

    void updateMyLocation();
    // Miscellaneous }}}
    // I/O {{{
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
    // I/O }}}
}; // }}}

}

#endif
