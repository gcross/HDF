#ifndef HDFPP_IMPLEMENTATION_LOCATION_HPP
#define HDFPP_IMPLEMENTATION_LOCATION_HPP

// Includes {{{
#include "file.hpp"
#include "identity.hpp"
#include "properties.hpp"

#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
// Includes }}}

namespace HDF {

class Location { // {{{
    // Constructors/Destructors {{{
    public:

    Location();

    Location(
        File const& file
      , Identity::Ptr const& parent_identity
      , boost::shared_ptr<std::string const> const name_ptr
    );
    // Constructors/Destructors }}}
    // Fields {{{
    protected:

    File file;
    Identity::Ptr parent_identity;
    boost::shared_ptr<std::string const> name;

    public:

    File const& getFile() const;
    Identity::Ptr const& getParentIdentity() const;
    std::string const& getName() const;

    hid_t getParentId() const;
    char const* getNameAsCStr() const;
    // Fields }}}
    // Operators {{{
    public:

    Location operator/(char const* subname) const;
    Location operator/(std::string const& subname) const;
    Location& operator/=(char const* subname);
    Location& operator/=(std::string const& subname);

    Location operator%(char const* subname) const;
    Location operator%(std::string const& subname) const;
    Location& operator%=(char const* subname);
    Location& operator%=(std::string const& subname);
    // Operators }}}
    // Values {{{
    public:

    static boost::shared_ptr<std::string const> const dot, slash;
    // Values }}}
    // Informational {{{
    public:

    bool exists(boost::optional<LinkAccessProperties const&> const& optional_link_access_properties=boost::none) const;
    // Informational }}}
}; // }}}

}

#endif
