// Includes {{{
#include "implementation/identified.hpp"

#include <boost/make_shared.hpp>
// Includes }}}

// Usings {{{
using boost::make_shared;
// Usings }}}

namespace HDF {

// class Identified {{{
// Constructors {{{
Identified::Identified() {}

Identified::Identified(Identity::Ptr const& identity)
  : identity(identity)
{}

Identified::Identified(hid_t id, Identity::Closer const& closer)
  : identity(make_shared<Identity>(id,closer))
{}
// Constructors }}}
// Fields {{{
Identity::Ptr const& Identified::getIdentity() const { return identity; }
// Fields }}}
// class Identified }}}

}
