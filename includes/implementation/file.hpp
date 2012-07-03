//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1392: * @file file.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_FILE_HPP
#define HDFPP_IMPLEMENTATION_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1393: ** << Includes >>
#include "attributable.hpp"
#include "error.hpp"
#include "locatable.hpp"
#include "parameters.hpp"
#include "parent.hpp"
#include "properties/file.hpp"
#include "properties/link.hpp"

#include <boost/optional.hpp>
#include <hdf5.h>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1395: ** class File
//@+<< Forward declarations >>
//@+node:gcross.20110529102535.2040: *3* << Forward declarations >>
class Contained;
//@-<< Forward declarations >>

class File
  : public Identified
  , public Parent
  , public Attributable
{
    //@+others
    //@+node:gcross.20110520194631.1424: *3* Constructors
    protected:

    File(hid_t id);
    File(Identity::Ptr const& identity);

    public:

    File();

    File(
        char const* filepath
      , FileOpenMode mode
      , boost::optional<FileAccessProperties const&> const& optional_properties = boost::none
    );

    File(
        char const* filepath
      , FileCreateMode mode
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    //@+node:gcross.20110523113700.1690: *3* Fields
    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //@+node:gcross.20110520211700.1487: *3* Friends
    friend class Contained;
    //@+node:gcross.20110521115623.3023: *3* Miscellaneous
    public:

    void flush(FileFlushScope scope=GlobalFileScope) const;

    FileAccessProperties getCopyOfAccessProperties() const;
    FileCreationProperties getCopyOfCreationProperties() const;
    size_t getFreeSpace() const;
    //@-others
};
//@-others

}

#endif
//@-leo
