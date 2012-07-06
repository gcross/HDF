// Includes {{{
#include "temporary_memory_file.hpp"

#include <cstdio>
// Includes }}}

namespace HDF {

// class TemporaryMemoryFile {{{
// Constructors {{{
TemporaryMemoryFile::TemporaryMemoryFile(
    size_t increment_size_in_bytes
  , boost::optional<FileCreationProperties const&> const& optional_creation_properties
  , boost::optional<FileAccessProperties const&> const& optional_access_properties
)
  : MemoryFile(
        getTemporaryFileName(),
        FailIfFileExisting,
        increment_size_in_bytes,
        false,
        optional_creation_properties,
        optional_access_properties
    )
{}
// Constructors }}}
// Miscellaneous {{{
char const* TemporaryMemoryFile::getTemporaryFileName() {
    static char buffer[L_tmpnam];
    tmpnam(buffer);
    return buffer;
}
// Miscellaneous }}}
// class TemporaryMemoryFile }}}

}
