//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1402: * @file parent.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110520194631.1404: ** << Includes >>
#include "implementation/parent.hpp"

#include <boost/format.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1405: ** << Usings >>
using boost::format;
using boost::optional;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1509: ** Exceptions
//@+node:gcross.20110520211700.1510: *3* LinkRemoveError
LinkRemoveError::LinkRemoveError(char const* name)
  : Error((format("deleting name %1%") % name).str())
  , name(name)
{}

LinkRemoveError::~LinkRemoveError() throw() {}
//@+node:gcross.20110520211700.1499: ** class Parent
//@+node:gcross.20110523113700.1697: *3* Miscellaneous
void Parent::remove(char const* name, optional<LinkAccessProperties const&> const& optional_properties) const {
    if(H5Ldelete(
        getId(),
        name,
        getOptionalPropertiesId(optional_properties)
       ) < 0
    ) throw LinkRemoveError(name);
}

void Parent::remove(string const& name, optional<LinkAccessProperties const&> const& optional_properties) const {
    remove(name.c_str(),optional_properties);
}
//@-others

}
//@-leo
