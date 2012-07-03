//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2106: * @file file.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2107: ** << Includes >>
#include "../properties.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110602092541.2152: ** Properties
//@+node:gcross.20110526150836.1974: *3* FileAccessProperties
struct FileAccessProperties: public Properties {
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileAccess)

    //@+others
    //@+node:gcross.20110526194358.1949: *4* core driver
    FileAccessProperties useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const;

    void getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const;
    std::pair<size_t,bool> getCoreDriverSettings() const;
    //@-others
};
//@+node:gcross.20110526150836.1973: *3* FileCreationProperties
struct FileCreationProperties: public Properties {
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileCreation)

    //@+others
    //@-others
};
//@-others

}

#endif
//@-leo
