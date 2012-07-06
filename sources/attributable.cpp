// Includes {{{
#include "attributable.hpp"

#include <string>
// Includes }}}

// Usings {{{
using std::string;
// Usings }}}

namespace HDF {

// class Attributable {{{
//     Operators {{{
Attribute Attributable::operator[] (char const* name) const {
    return Attribute(*this,name);
}
//     }}}
// }}}

}
