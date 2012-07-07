#ifndef HDFPP_IMPLEMENTATION_CONTAINER_HPP
#define HDFPP_IMPLEMENTATION_CONTAINER_HPP

// Includes {{{
#include "file.hpp"
#include "group.hpp"
#include "locatable.hpp"
#include "location.hpp"
#include "parent.hpp"
#include "parameters.hpp"

#include <boost/optional.hpp>
#include <utility>
// Includes }}}

namespace HDF {

class Container: public Contained, public Parent { // {{{
    //   Constructors {{{
    public:

    Container(File const& file);
    Container(Group const& group);
    Container(Location const& location);
    Container(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_creation_properties = boost::none
    );

    protected:

    void initialize(
        Location const& location
      , boost::optional<std::pair<
            boost::optional<LinkCreationProperties const&>
         ,  boost::optional<GroupCreationProperties const&>
        > > const& creation_properties = boost::none
    );
    //   Constructors }}}
    //   Fields {{{
    protected:

    File file;

    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //   Fields }}}
    //   Operators {{{
    public:

    void operator=(File const& file);
    void operator=(Group const& group);
    //   Operators }}}
}; // }}}

}

#endif
