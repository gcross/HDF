//@+leo-ver=5-thin
//@+node:gcross.20110521115623.2866: * @file object.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110521115623.2868: ** << Includes >>
#include "implementation/object.hpp"

#include <boost/scoped_array.hpp>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110521115623.2869: ** << Usings >>
using boost::optional;
using boost::scoped_array;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110521115623.2873: ** class Object
//@+node:gcross.20110521115623.2874: *3* Constructors
Object::Object() {}

Object::Object(File const& file, hid_t id, Identity::Closer const& closer)
  : Contained(file,id,closer)
{}

Object::Object(File const& file, Identity::Ptr const& self_identity)
  : Contained(file,self_identity)
{}

Object::Object(
    Location const& location
  , optional<LinkAccessProperties> const& optional_properties
) : Contained(
        location.getFile(),
        assertSuccess(
            "opening object",
            H5Oopen(
                location.getParentId(),
                location.getNameAsCStr(),
                getOptionalPropertiesId(optional_properties)
            )
        ),
        H5Oclose
    )
{}
//@+node:gcross.20110521115623.2875: *3* Comments
string Object::getComment() const {
    size_t comment_size =
        assertSuccess(
            "getting object comment length",
            H5Oget_comment(getId(),NULL,0)
        );
    if(comment_size == 0) return string();

    scoped_array<char> buffer(new char[comment_size+1]);
    assertSuccess(
        "getting object comment",
        H5Oget_comment(getId(),buffer.get(),comment_size+1)
    );
    return string(buffer.get());
}

void Object::setComment(char const* comment) const {
    assertSuccess(
        "setting object comment",
        H5Oset_comment(getId(),comment)
    );
}

void Object::setComment(std::string const& comment) const {
    setComment(comment.c_str());
}
//@+node:gcross.20110523113700.1692: *3* Fields
Contained const& Object::getAttributeContained() const { return *this; }
//@-others

}
//@-leo
