//@+leo-ver=5-thin
//@+node:gcross.20110524225139.1842: * @file container.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110524225139.1844: ** << Includes >>
#include "container.hpp"
#include "utilities.hpp"

#include <boost/algorithm/string/trim.hpp>
#include <boost/foreach.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110524225139.1845: ** << Usings >>
using boost::algorithm::trim_left_if;
using boost::optional;

using std::make_pair;
using std::pair;
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110524225139.1849: ** class Container
//@+node:gcross.20110524225139.1850: *3* Constructors
Container::Container(File const& file) : Contained(file,file.getIdentity()) {}

Container::Container(Group const& group) : Contained(group) {}

Container::Container(Location const& location)
  : Contained(location.getFile(),Identity::Ptr())
{
    initialize(location);
}

Container::Container(
    CreateAt<Location const> location
  , optional<LinkCreationProperties const&> const& optional_link_creation_properties
  , optional<GroupCreationProperties const&> const& optional_creation_properties
)
  : Contained(location->getFile(),Identity::Ptr())
{
    initialize(*location,make_pair(optional_link_creation_properties,optional_creation_properties));
}

void Container::initialize(
    Location const& location
  , optional<pair<
        optional<LinkCreationProperties const&>
     ,  optional<GroupCreationProperties const&>
    > > const& creation_properties
) {
    string const& name = location.getName();
    string trimmed_name = name;
    trim_left_if(trimmed_name,isSlashOrDot);
    if(trimmed_name.empty()
    && (file.getIdentity() == location.getParentIdentity()
        || (!name.empty() && name[0] == '/')
       )
    ) identity = file.getIdentity();
    else {
        if(creation_properties)
             *this =
                Group(
                    createAt(location),
                    creation_properties->first,
                    creation_properties->second
                );
        else *this = Group(location);
    }
}
//@+node:gcross.20110623234825.1974: *3* Fields
File const& Container::getFile() const { return file; }

Identity::Ptr const& Container::getIdentity() const { return identity; }
//@+node:gcross.20110524225139.1858: *3* Operators
void Container::operator=(File const& file) {
    this->file = file;
    identity = file.getIdentity();
}

void Container::operator=(Group const& group) {
    file = group.getFile();
    identity = group.getIdentity();
}
//@-others

}
//@-leo
