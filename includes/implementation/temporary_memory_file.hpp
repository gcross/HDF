//@+leo-ver=5-thin
//@+node:gcross.20110521115623.3198: * @file temporary_memory_file.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_TEMPORARY_MEMORY_FILE_HPP
#define HDFPP_IMPLEMENTATION_TEMPORARY_MEMORY_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.3199: ** << Includes >>
#include "memory_file.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.3201: ** class TemporaryMemoryFile
class TemporaryMemoryFile: public MemoryFile {
    //@+others
    //@+node:gcross.20110521115623.3203: *3* Constructors
    public:

    TemporaryMemoryFile(
        size_t increment_size_in_bytes = 4096
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    //@+node:gcross.20110521115623.3219: *3* Miscellaneous
    protected:

    static char const* getTemporaryFileName();
    //@-others
};
//@-others

}

#endif
//@-leo
