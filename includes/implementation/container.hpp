//@+leo-ver=5-thin
//@+node:gcross.20110524225139.1832: * @file container.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_CONTAINER_HPP
#define HDFPP_IMPLEMENTATION_CONTAINER_HPP

//@+<< Includes >>
//@+node:gcross.20110524225139.1833: ** << Includes >>
#include "file.hpp"
#include "group.hpp"
#include "locatable.hpp"
#include "location.hpp"
#include "parent.hpp"
#include "parameters.hpp"

#include <boost/optional.hpp>
#include <utility>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110524225139.1835: ** class Container
class Container: public Contained, public Parent {
    //@+others
    //@+node:gcross.20110524225139.1836: *3* Constructors
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
    //@+node:gcross.20110524225139.1837: *3* Fields
    protected:

    File file;

    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //@+node:gcross.20110524225139.1856: *3* Operators
    public:

    void operator=(File const& file);
    void operator=(Group const& group);
    //@-others
};
//@-others

}

#endif
//@-leo
