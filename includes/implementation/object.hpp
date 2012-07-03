//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2852: * @file object.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_OBJECT_HPP
#define HDFPP_IMPLEMENTATION_OBJECT_HPP

//@+<< Includes >>
//@+node:gcross.20110521115623.2853: ** << Includes >>
#include "attributable.hpp"
#include "contained.hpp"
#include "properties.hpp"

#include <boost/optional.hpp>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110521115623.2855: ** class Object
class Object: public Contained, public Attributable {
    //@+others
    //@+node:gcross.20110521115623.2856: *3* Constructors
    protected:

    Object();

    public:

    Object(File const& file, hid_t id, Identity::Closer const& closer);
    Object(File const& file, Identity::Ptr const& self_identity);
    Object(Location const& location, boost::optional<LinkAccessProperties> const& optional_properties = boost::none);
    //@+node:gcross.20110521115623.2861: *3* Comments
    public:

    std::string getComment() const;

    void setComment(char const* comment) const;
    void setComment(std::string const& comment) const;
    //@+node:gcross.20110523113700.1693: *3* Fields
    protected:

    virtual Contained const& getAttributeContained() const;
    //@-others
};
//@-others

}

#endif
//@-leo
