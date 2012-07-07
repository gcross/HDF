#ifndef HDFPP_IMPLEMENTATION_MEMORY_FILE_HPP
#define HDFPP_IMPLEMENTATION_MEMORY_FILE_HPP

// Includes {{{
#include "file.hpp"
// Includes }}}

namespace HDF {

class MemoryFile: public File { // {{{
    // Constructors {{{
    public:

    MemoryFile(
        char const* filepath
      , FileOpenMode mode
      , size_t increment_size_in_bytes = 4096
      , bool write_data_to_filepath = false
      , boost::optional<FileAccessProperties const&> const& optional_properties = boost::none
    );

    MemoryFile(
        char const* filepath
      , FileCreateMode mode
      , size_t increment_size_in_bytes = 4096
      , bool write_data_to_filepath = false
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    // Constructors }}}
}; // }}}

}

#endif
