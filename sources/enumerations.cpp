//@+leo-ver=5-thin
//@+node:gcross.20110526150836.1935: * @file enumerations.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110526150836.1937: ** << Includes >>
#include "implementation/enumerations.hpp"

#include <boost/lexical_cast.hpp>
#include <stdexcept>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110526150836.1938: ** << Usings >>
using boost::lexical_cast;

using std::invalid_argument;
using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110526150836.1956: ** Functions
//@+node:gcross.20110526150836.1957: *3* getFileCreateModeFlag
unsigned int getFileCreateModeFlag(FileCreateMode mode) {
    switch(mode) {
        case FailIfFileExisting: return H5F_ACC_EXCL;
        case TruncateIfFileExisting: return H5F_ACC_TRUNC;
    }
    throw invalid_argument(lexical_cast<string>(mode));
}
//@+node:gcross.20110526150836.1958: *3* getFileOpenModeFlag
unsigned int getFileOpenModeFlag(FileOpenMode mode) {
    switch(mode) {
        case OpenReadOnly: return H5F_ACC_RDONLY;
        case OpenReadWrite: return H5F_ACC_RDWR;
    }
    throw invalid_argument(lexical_cast<string>(mode));
}
//@-others

}
//@-leo
