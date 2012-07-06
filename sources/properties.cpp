// Includes {{{
#include "properties.hpp"

#include <boost/scoped_ptr.hpp>
// Includes }}}

// Usings {{{
using boost::scoped_ptr;

using std::string;
// Usings }}}

namespace HDF {

// class Properties {{{
// Constructors/Destructors {{{
Properties::Properties(hid_t id) : Identified(id,H5Pclose) {}

Properties::Properties() {}
// Constructors/Destructors }}}
// Informational {{{
hid_t Properties::getClassId() const {
    return assertSuccess(
        "getting property list class id",
        H5Pget_class(getId())
    );
}
// Informational }}}
// class Properties }}}

}
