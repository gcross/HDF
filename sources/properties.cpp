//@+leo-ver=5-thin
//@+node:gcross.20110520211700.1472: * @file properties.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110520211700.1474: ** << Includes >>
#include "properties.hpp"

#include <boost/scoped_ptr.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520211700.1475: ** << Usings >>
using boost::scoped_ptr;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520211700.1478: ** class Properties
//@+node:gcross.20110520211700.1479: *3* Constructors/Destructors
Properties::Properties(hid_t id) : Identified(id,H5Pclose) {}

Properties::Properties() {}
//@+node:gcross.20110602121059.2133: *3* Informational
hid_t Properties::getClassId() const {
    return assertSuccess(
        "getting property list class id",
        H5Pget_class(getId())
    );
}
//@-others

}
//@-leo
