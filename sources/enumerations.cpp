// Includes {{{
#include "implementation/enumerations.hpp"

#include <boost/lexical_cast.hpp>
#include <stdexcept>
// Includes }}}

// Usings {{{
using boost::lexical_cast;

using std::invalid_argument;
using std::string;
// Usings }}}

namespace HDF {

unsigned int getFileCreateModeFlag(FileCreateMode mode) { // {{{
    switch(mode) {
        case FailIfFileExisting: return H5F_ACC_EXCL;
        case TruncateIfFileExisting: return H5F_ACC_TRUNC;
    }
    throw invalid_argument(lexical_cast<string>(mode));
} // }}}

unsigned int getFileOpenModeFlag(FileOpenMode mode) { // {{{
    switch(mode) {
        case OpenReadOnly: return H5F_ACC_RDONLY;
        case OpenReadWrite: return H5F_ACC_RDWR;
    }
    throw invalid_argument(lexical_cast<string>(mode));
} // }}}

}
