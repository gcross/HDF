// Includes {{{
#include "implementation/identifiable.hpp"
// Includes }}}

namespace HDF {

// class Identifiable {{{
//     Destructors {{{
Identifiable::~Identifiable() {}
//     Destructors }}}
//     Fields {{{
hid_t Identifiable::getId() const { return getIdentity()->getId(); }
//     Fields }}}
//     Operators {{{
bool Identifiable::operator==(Identifiable const& other) const {
    return getId() == other.getId();
}
//     Operators }}}
// class Identifiable }}}

}
