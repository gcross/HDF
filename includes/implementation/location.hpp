//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1362: * @file location.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_LOCATION_HPP
#define HDFPP_IMPLEMENTATION_LOCATION_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1363: ** << Includes >>
#include "file.hpp"
#include "identity.hpp"
#include "properties.hpp"

#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1365: ** class Location
class Location {
    //@+others
    //@+node:gcross.20110520194631.1367: *3* Constructors/Destructors
    public:

    Location();

    Location(
        File const& file
      , Identity::Ptr const& parent_identity
      , boost::shared_ptr<std::string const> const name_ptr
    );
    //@+node:gcross.20110520194631.1368: *3* Fields
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
    //@+node:gcross.20110520194631.1369: *3* Operators
    public:

    Location operator/(char const* subname) const;
    Location operator/(std::string const& subname) const;
    Location& operator/=(char const* subname);
    Location& operator/=(std::string const& subname);

    Location operator%(char const* subname) const;
    Location operator%(std::string const& subname) const;
    Location& operator%=(char const* subname);
    Location& operator%=(std::string const& subname);
    //@+node:gcross.20110520194631.1370: *3* Values
    public:

    static boost::shared_ptr<std::string const> const dot, slash;
    //@+node:gcross.20110523113700.2388: *3* Informational
    public:

    bool exists(boost::optional<LinkAccessProperties const&> const& optional_link_access_properties=boost::none) const;
    //@-others
};
//@-others

}

#endif
//@-leo
