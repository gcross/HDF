// Includes {{{
#include "implementation/identity.hpp"
// Includes }}}

namespace HDF {

// class Identity {{{
// Constructors/Destructors {{{
Identity::Identity(hid_t id, Closer const& close)
  : id(id)
  , close(close)
{}

Identity::~Identity() { close(id); }
// Constructors/Destructors }}}
// Fields {{{
hid_t Identity::getId() const { return id; }
// Fields }}}
// class Identity }}}

}
