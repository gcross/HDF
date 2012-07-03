//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3157: * @file memory_file.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_MEMORY_FILE_HPP
#define HDFPP_IMPLEMENTATION_MEMORY_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3158: ** << Includes >>
#include "file.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.3160: ** class MemoryFile
class MemoryFile: public File {
    //@+others
    //@+node:gcross.20110521115623.3161: *3* Constructors
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
    //@-others
};
//@-others

}

#endif
//@-leo
