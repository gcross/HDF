#ifndef HDFPP_IMPLEMENTATION_TEMPORARY_MEMORY_FILE_HPP
#define HDFPP_IMPLEMENTATION_TEMPORARY_MEMORY_FILE_HPP

// Includes {{{
#include "memory_file.hpp"
// Includes }}}

namespace HDF {

class TemporaryMemoryFile: public MemoryFile { // {{{
    // Constructors {{{
    public:

    TemporaryMemoryFile(
        size_t increment_size_in_bytes = 4096
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    // Constructors }}}
    // Miscellaneous {{{
    protected:

    static char const* getTemporaryFileName();
    // Miscellaneous }}}
}; // }}}

}

#endif
