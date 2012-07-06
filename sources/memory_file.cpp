// Includes {{{
#include "implementation/memory_file.hpp"
// Includes }}}

namespace HDF {

// class MemoryFile {{{
// Constructors {{{
MemoryFile::MemoryFile(
    char const* filepath
  , FileOpenMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileAccessProperties const&> const& optional_properties
) // {{{
  : File(
        filepath,
        mode,
        GET_OPTIONAL_OR(optional_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{} // }}}

MemoryFile::MemoryFile(
    char const* filepath
  , FileCreateMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileCreationProperties const&> const& optional_creation_properties
  , boost::optional<FileAccessProperties const&> const& optional_access_properties
) // {{{
  : File(
        filepath,
        mode,
        optional_creation_properties,
        GET_OPTIONAL_OR(optional_access_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{} // }}}
// Constructors }}}
// class MemoryFile }}}

}
