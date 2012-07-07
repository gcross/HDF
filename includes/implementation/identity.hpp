#ifndef HDFPP_IMPLEMENTATION_IDENTITY_HPP
#define HDFPP_IMPLEMENTATION_IDENTITY_HPP

// Includes {{{
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>
#include <hdf5.h>
// Includes }}}

namespace HDF {

class Identity: boost::noncopyable { // {{{
    // Associated types {{{
    public:

    typedef boost::function<void(hid_t)> Closer;
    typedef boost::shared_ptr<Identity const> Ptr;
    // Associated types }}}
    // Constructors/Destructors {{{
    public:

    Identity(hid_t id, Closer const& close);
    ~Identity();
    // Constructors/Destructors }}}
    // Fields {{{
    protected:

    hid_t id;
    Closer close;

    public:

    virtual hid_t getId() const;
    // Fields }}}
}; // }}}

}

#endif
