#ifndef HDFPP_IMPLEMENTATION_OBJECT_HPP
#define HDFPP_IMPLEMENTATION_OBJECT_HPP

// Includes {{{
#include "attributable.hpp"
#include "contained.hpp"
#include "properties.hpp"

#include <boost/optional.hpp>
#include <string>
// Includes }}}

namespace HDF {

class Object: public Contained, public Attributable { // {{{
    // Constructors {{{
    protected:

    Object();

    public:

    Object(File const& file, hid_t id, Identity::Closer const& closer);
    Object(File const& file, Identity::Ptr const& self_identity);
    Object(Location const& location, boost::optional<LinkAccessProperties> const& optional_properties = boost::none);
    // Constructors }}}
    // Comments {{{
    public:

    std::string getComment() const;

    void setComment(char const* comment) const;
    void setComment(std::string const& comment) const;
    // Comments }}}
    // Fields {{{
    protected:

    virtual Contained const& getAttributeContained() const;
    // Fields }}}
}; // }}}

}

#endif
