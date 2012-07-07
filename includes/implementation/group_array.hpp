#ifndef HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP
#define HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP

// Includes {{{
#include "group.hpp"
#include "location_iterator.hpp"
// Includes }}}

namespace HDF {

class GroupArray: public Group { // {{{
    // Associated types {{{
    public:

    typedef LocationIterator iterator;
    typedef LocationIterator const_iterator;
    typedef LocationIterator reverse_iterator;
    typedef LocationIterator reverse_const_iterator;
    // Associated types }}}
    // Constructors {{{
    public:

    GroupArray();

    GroupArray(Location const& location);

    GroupArray(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties = boost::none
    );
    // Constructors }}}
    // I/O Support {{{
    template<typename T> void operator<<(RangeOf<T> values) const {
        (*this)["size"] = static_cast<unsigned int>(values->size());
        begin() << values;
    }
    // I/O Support }}}
    // Informational {{{
    public:

    unsigned int size() const;
    // Informational }}}
    // Range interface {{{
    public:

    iterator begin() const;
    iterator end() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    // Range interface }}}
}; // }}}

}

#endif
