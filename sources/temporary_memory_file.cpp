//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3208: * @file temporary_memory_file.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.3210: ** << Includes >>
#include "temporary_memory_file.hpp"

#include <cstdio>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.3211: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.3214: ** class TemporaryMemoryFile
//@+node:gcross.20110521115623.3215: *3* Constructors
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
//@+node:gcross.20110521115623.3216: *3* Miscellaneous
char const* TemporaryMemoryFile::getTemporaryFileName() {
    static char buffer[L_tmpnam];
    tmpnam(buffer);
    return buffer;
}
//@-others

}
//@-leo
