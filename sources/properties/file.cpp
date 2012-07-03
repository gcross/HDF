//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2184: * @file file.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110602092541.2186: ** << Includes >>
#include "properties/file.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110602092541.2187: ** << Usings >>
using std::pair;
//@-<< Usings >>

//@+others
//@+node:gcross.20110602092541.2204: ** Properties
//@+node:gcross.20110526150836.1977: *3* FileAccessProperties
DEFINE_PROPERTIES_BOILERPLATE(FileAccess,file access,FILE_ACCESS)

//@+others
//@+node:gcross.20110526194358.1938: *4* CoreDriver
FileAccessProperties FileAccessProperties::useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const {
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pset_fapl_core(getId(),increment_size_in_bytes,write_to_backing_store)
    );
    return *this;
}

void FileAccessProperties::getCoreDriverSettings(size_t &increment_size_in_bytes, bool &write_to_backing_store) const {
    hbool_t write_to_backing_store_temp;
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pget_fapl_core(getId(),&increment_size_in_bytes,&write_to_backing_store_temp)
    );
    write_to_backing_store = write_to_backing_store_temp;
}

pair<size_t,bool> FileAccessProperties::getCoreDriverSettings() const {
    pair<size_t,bool> result;
    getCoreDriverSettings(result.first,result.second);
    return result;
}
//@-others
//@+node:gcross.20110526150836.1979: *3* FileCreationProperties
DEFINE_PROPERTIES_BOILERPLATE(FileCreation,file creation,FILE_CREATE)

//@+others
//@-others
//@-others

}
//@-leo
