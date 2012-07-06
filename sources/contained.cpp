// Includes {{{
#include "contained.hpp"

#include <boost/make_shared.hpp>
// Includes }}}

// Usings {{{
using boost::make_shared;
// Usings }}}

namespace HDF {

// class Contained {{{
//     Constructors {{{
Contained::Contained() {}

Contained::Contained(File const& file, hid_t id, Identity::Closer const& closer)
  : Identified(make_shared<Identity>(id,closer))
  , file(file)
{}

Contained::Contained(File const& file, Identity::Ptr const& identity)
  : Identified(identity)
  , file(file)
{}
//     Constructors }}}
//     Fields {{{
File const& Contained::getFile() const { return file; }
Identity::Ptr const& Contained::getIdentity() const { return identity; }
//     Fields }}}
// class Contained }}}

}
