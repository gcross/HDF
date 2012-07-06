// Includes {{{
#include "implementation/error.hpp"
#include "implementation/location.hpp"

#include <boost/format.hpp>
#include <boost/make_shared.hpp>
// Includes }}}

// Usings {{{
using boost::format;
using boost::make_shared;
using boost::optional;
using boost::shared_ptr;

using std::string;
// Usings }}}

namespace HDF {

// class Location {{{
// Constructors/Destructors {{{
Location::Location() {}

Location::Location(
    File const& file
  , Identity::Ptr const& parent_identity
  , shared_ptr<string const> const name_ptr
)
  : file(file)
  , parent_identity(parent_identity)
  , name(name_ptr)
{}
// Constructors/Destructors }}}
// Fields {{{
File const& Location::getFile() const { return file; }
Identity::Ptr const& Location::getParentIdentity() const { return parent_identity; }
string const& Location::getName() const { return *name; }

hid_t Location::getParentId() const { return parent_identity->getId(); }
char const* Location::getNameAsCStr() const { return getName().c_str(); }
// Fields }}}
// Informational {{{
bool Location::exists(optional<LinkAccessProperties const&> const& optional_link_access_properties) const {
    string const& name = *(this->name);
    if(name == "." || name == "/") return true;
    return
        assertSuccess(
            "ascertaining location existence",
            H5Lexists(
                getParentId(),
                name.c_str(),
                getOptionalPropertiesId(optional_link_access_properties)
            )
        ) == 1;
}
// Informational }}}
// Operators {{{
Location Location::operator/(char const* subname) const {
    return Location(
        file,
        parent_identity,
        make_shared<string>((format("%1%/%2%") % getName() % subname).str())
    );
}

Location Location::operator/(string const& subname) const {
    return Location(
        file,
        parent_identity,
        make_shared<string>((format("%1%/%2%") % getName() % subname).str())
    );
}

Location& Location::operator/=(char const* subname) {
    name = make_shared<string>((format("%1%/%2%") % *name % subname).str());
    return *this;
}

Location& Location::operator/=(string const& subname) {
    name = make_shared<string>((format("%1%/%2%") % *name % subname).str());
    return *this;
}

Location Location::operator%(char const* subname) const {
    return Location(
        file,
        parent_identity,
        make_shared<string>(subname)
    );
}

Location Location::operator%(string const& subname) const {
    return Location(
        file,
        parent_identity,
        make_shared<string>(subname)
    );
}

Location& Location::operator%=(char const* subname) {
    name = make_shared<string>(subname);
    return *this;
}

Location& Location::operator%=(string const& subname) {
    name = make_shared<string>(subname);
    return *this;
}
// Operators }}}
// Values {{{
shared_ptr<string const> const
    Location::dot(new string("."))
  , Location::slash(new string("/"))
  ;
// Values }}}
// class Location }}}

}
