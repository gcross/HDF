#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_FILE_ACCESS_HPP

// Includes {{{
#include "../properties.hpp"
// Includes }}}

namespace HDF {

// Properties {{{
struct FileAccessProperties: public Properties { // {{{
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileAccess)

    // core driver {{{
    FileAccessProperties useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const;

    void getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const;
    std::pair<size_t,bool> getCoreDriverSettings() const;
    // core driver }}}
}; // }}}
struct FileCreationProperties: public Properties { // {{{
    friend class File;

    DECLARE_PROPERTIES_BOILERPLATE(FileCreation)
};// }}}
// Properties }}}

}

#endif
