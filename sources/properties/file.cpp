// Includes {{{
#include "properties/file.hpp"
// Includes }}}

// Usings {{{
using std::pair;
// Usings }}}

namespace HDF {

// Properties {{{
//     file access {{{
DEFINE_PROPERTIES_BOILERPLATE(FileAccess,file access,FILE_ACCESS)

//         core driver {{{
FileAccessProperties FileAccessProperties::useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const { // {{{
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pset_fapl_core(getId(),increment_size_in_bytes,write_to_backing_store)
    );
    return *this;
} // }}}

void FileAccessProperties::getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const { // {{{
    hbool_t write_to_backing_store_temp;
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pget_fapl_core(getId(),&increment_size_in_bytes,&write_to_backing_store_temp)
    );
    write_to_backing_store = write_to_backing_store_temp;
} // }}}

pair<size_t,bool> FileAccessProperties::getCoreDriverSettings() const { // {{{
    pair<size_t,bool> result;
    getCoreDriverSettings(result.first,result.second);
    return result;
} // }}}
//         core driver }}}

//     files access }}}
//     file creation {{{
DEFINE_PROPERTIES_BOILERPLATE(FileCreation,file creation,FILE_CREATE)
//     file creation }}}
// Properties }}}

}
