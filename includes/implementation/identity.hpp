//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1284: * @file identity.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_IDENTITY_HPP
#define HDFPP_IMPLEMENTATION_IDENTITY_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1285: ** << Includes >>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1287: ** class Identity
class Identity: boost::noncopyable {
    //@+others
    //@+node:gcross.20110520194631.1290: *3* Typedefs
    public:

    typedef boost::function<void(hid_t)> Closer;
    typedef boost::shared_ptr<Identity const> Ptr;
    //@+node:gcross.20110520194631.1289: *3* Constructors/Destructors
    public:

    Identity(hid_t id, Closer const& close);
    ~Identity();
    //@+node:gcross.20110520194631.1288: *3* Fields
    protected:

    hid_t id;
    Closer close;

    public:

    virtual hid_t getId() const;
    //@-others
};
//@-others

}

#endif
//@-leo
