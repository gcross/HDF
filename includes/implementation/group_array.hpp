//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2983: * @file group_array.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP
#define HDFPP_IMPLEMENTATION_GROUP_ARRAY_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2984: ** << Includes >>
#include "group.hpp"
#include "location_iterator.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2986: ** class GroupArray
class GroupArray: public Group {
    //@+others
    //@+node:gcross.20110521115623.2996: *3* Associated types
    public:

    typedef LocationIterator iterator;
    typedef LocationIterator const_iterator;
    typedef LocationIterator reverse_iterator;
    typedef LocationIterator reverse_const_iterator;
    //@+node:gcross.20110521115623.2988: *3* Constructors
    public:

    GroupArray();

    GroupArray(Location const& location);

    GroupArray(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_group_creation_properties = boost::none
    );
    //@+node:gcross.20110521115623.3002: *3* I/O support
    template<typename T> void operator<<(RangeOf<T> values) const {
        (*this)["size"] = static_cast<unsigned int>(values->size());
        begin() << values;
    }
    //@+node:gcross.20110521115623.2998: *3* Informational
    public:

    unsigned int size() const;
    //@+node:gcross.20110521115623.3000: *3* Range interface
    public:

    iterator begin() const;
    iterator end() const;

    reverse_iterator rbegin() const;
    reverse_iterator rend() const;
    //@-others
};
//@-others

}

#endif
//@-leo
