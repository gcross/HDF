//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3166: * @file memory_file.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.3168: ** << Includes >>
#include "implementation/memory_file.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3169: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3172: ** class MemoryFile
//@+node:gcross.20110521115623.3173: *3* Constructors
MemoryFile::MemoryFile(
    char const* filepath
  , FileOpenMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileAccessProperties const&> const& optional_properties
)
  : File(
        filepath,
        mode,
        GET_OPTIONAL_OR(optional_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{}

MemoryFile::MemoryFile(
    char const* filepath
  , FileCreateMode mode
  , size_t increment_size_in_bytes
  , bool write_data_to_filepath
  , boost::optional<FileCreationProperties const&> const& optional_creation_properties
  , boost::optional<FileAccessProperties const&> const& optional_access_properties
)
  : File(
        filepath,
        mode,
        optional_creation_properties,
        GET_OPTIONAL_OR(optional_access_properties,FileAccessProperties())
            .useCoreDriver(increment_size_in_bytes,write_data_to_filepath)
    )
{}
//@-others

}
//@-leo
