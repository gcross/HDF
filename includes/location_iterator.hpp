//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2929: * @file location_iterator.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110521115623.2930: ** << License >>
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

#ifndef HDFPP_LOCATION_ITERATOR_HPP
#define HDFPP_LOCATION_ITERATOR_HPP

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

    Locatable parent;
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
