// Includes {{{
#include "file.hpp"

#include <boost/format.hpp>
#include <hdf5.h>
// Includes }}}

// Usings {{{
using boost::format;
using boost::optional;

using std::string;
// Usings }}}

namespace HDF {

// class File {{{
// Constructors/Destructors {{{
File::File() {}

File::File(Identity::Ptr const& identity)
  : Identified(identity)
{}

File::File(
    const char* filepath
  , FileCreateMode mode
  , optional<FileCreationProperties const&> const& optional_creation_properties
  , optional<FileAccessProperties const&> const& optional_access_properties
) // {{{
  : Identified(
        assertSuccess(
            "creating file",
            H5Fcreate(
                filepath,
                getFileCreateModeFlag(mode),
                getOptionalPropertiesId(optional_creation_properties),
                getOptionalPropertiesId(optional_access_properties)
            )
        ),
        H5Fclose
    )
{} // }}}

File::File(
    const char* filepath
  , FileOpenMode mode
  , optional<FileAccessProperties const&> const& optional_properties
) // {{{
  : Identified(
        assertSuccess(
            "opening file",
            H5Fopen(
                filepath,
                getFileOpenModeFlag(mode),
                getOptionalPropertiesId(optional_properties)
            )
        ),
        H5Fclose
    )
{} // }}}

// Constructors/Destructors }}}
// Fields {{{
File const& File::getFile() const { return *this; }
Identity::Ptr const& File::getIdentity() const { return identity; }
// Fields }}}
// Miscellaneous {{{
void File::flush(FileFlushScope scope) const { // {{{
    assertSuccess(
        "flushing file",
        H5Fflush(getId(),static_cast<H5F_scope_t>(scope))
    );
} // }}}
FileAccessProperties File::getCopyOfAccessProperties() const { // {{{
    return FileAccessProperties(assertSuccess(
        "getting file access properties",
        H5Fget_access_plist(getId())
    ));
} // }}}
FileCreationProperties File::getCopyOfCreationProperties() const { // {{{
    return FileCreationProperties(assertSuccess(
        "getting file creation properties",
        H5Fget_create_plist(getId())
    ));
} // }}}
size_t File::getFreeSpace() const { // {{{
    return assertSuccess(
        "getting file free space",
        H5Fget_freespace(getId())
    );
} // }}}
// Miscellaneous }}}
// class File }}}

}
