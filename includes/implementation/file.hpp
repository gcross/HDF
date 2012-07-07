#ifndef HDFPP_IMPLEMENTATION_FILE_HPP
#define HDFPP_IMPLEMENTATION_FILE_HPP

// Includes {{{
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
// Includes }}}

namespace HDF {

// class File {{{

// Forward declarations {{{
class Contained;
// Forward declarations }}}

class File
  : public Identified
  , public Parent
  , public Attributable
{
    // Constructors {{{
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
    // Constructors }}}
    // Fields {{{
    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    // Fields }}}
    // Friends {{{
    friend class Contained;
    // Friends }}}
    // Miscellaneous {{{
    public:

    void flush(FileFlushScope scope=GlobalFileScope) const;

    FileAccessProperties getCopyOfAccessProperties() const;
    FileCreationProperties getCopyOfCreationProperties() const;
    size_t getFreeSpace() const;
    // Miscellaneous }}}
};
// class Files }}}

}

#endif
