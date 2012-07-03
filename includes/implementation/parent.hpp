//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1343: * @file parent.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_PARENT_HPP
#define HDFPP_IMPLEMENTATION_PARENT_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1344: ** << Includes >>
#include "error.hpp"
#include "locatable.hpp"
#include "parent.hpp"
#include "properties/link.hpp"

#include <hdf5.h>
#include <boost/optional.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520211700.1505: ** Exceptions
//@+node:gcross.20110520211700.1506: *3* LinkRemoveError
struct LinkRemoveError : public Error {
    std::string name;
    LinkRemoveError(char const* name);
    virtual ~LinkRemoveError() throw();
};
//@+node:gcross.20110520194631.1346: ** class Parent
class Parent: public virtual Identifiable {
    //@+others
    //@+node:gcross.20110523113700.1681: *3* Miscellaneous
    public:
        void remove(char const* name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
        void remove(std::string const& name, boost::optional<LinkAccessProperties const&> const& optional_properties = boost::none) const;
    //@-others
};
//@-others

}

#endif
//@-leo
