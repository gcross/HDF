//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1429: * @file file.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1430: ** << License >>
//@+at
// Copyright (c) 2011, Gregory Crosswhite
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
// 
//     * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//@@c
//@-<< License >>

//@+<< Includes >>
//@+node:gcross.20110520194631.1431: ** << Includes >>
#include "file.hpp"

#include <boost/format.hpp>
#include <hdf5.h>
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110520194631.1432: ** << Usings >>
using boost::format;
using boost::optional;

using std::string;
//@-<< Usings >>

//@+others
//@+node:gcross.20110520194631.1433: ** class File
//@+node:gcross.20110520194631.1435: *3* Constructors/Destructors
File::File() {}

File::File(Identity::Ptr const& identity)
  : Locatable(identity)
{}

//@+others
//@+node:gcross.20110520211700.1389: *4* Create
File::File(
    const char* filepath
  , FileCreateMode mode
  , optional<CreationProperties const&> const& optional_creation_properties
  , optional<AccessProperties const&> const& optional_access_properties
) 
  : Locatable(
        assertSuccess(
            "creating file",
            H5Fcreate(
                filepath,
                getFileCreateModeFlag(mode),
                getOptionalPropertiesId(optional_creation_properties),
                getOptionalPropertiesId(optional_access_properties)
            )
        ),
        H5Fclose
    )
{}
//@+node:gcross.20110520211700.1493: *4* Open
File::File(
    const char* filepath
  , FileOpenMode mode
  , optional<AccessProperties const&> const& optional_properties
)
  : Locatable(
        assertSuccess(
            "opening file",
            H5Fopen(
                filepath,
                getFileOpenModeFlag(mode),
                getOptionalPropertiesId(optional_properties)
            )
        ),
        H5Fclose
    )
{}
//@-others
//@+node:gcross.20110520211700.1480: *3* Nested types
//@+node:gcross.20110521115623.3152: *4* Access Properties
File::AccessProperties::AccessProperties()
  : Properties(assertSuccess("creating file access properties",H5Pcreate(H5P_FILE_ACCESS)))
{}

File::AccessProperties File::AccessProperties::useCoreDriver(size_t increment_size_in_bytes, bool write_to_backing_store) const {
    assertSuccess(
        "setting file to use CORE (memory) driver",
        H5Pset_fapl_core(getId(),increment_size_in_bytes,write_to_backing_store)
    );
    return *this;
}
//@+node:gcross.20110521115623.3153: *4* Creation Properties
File::CreationProperties::CreationProperties()
  : Properties(assertSuccess("creating file creation properties",H5Pcreate(H5P_FILE_CREATE)))
{}
//@+node:gcross.20110523113700.1688: *3* Fields
Containable const& File::getAttributeContainable() const { return *this; }
hid_t File::getParentId() const { return getId(); }
//@+node:gcross.20110521115623.3024: *3* Miscellaneous
void File::flush(FileFlushScope scope) const {
    assertSuccess(
        "flushing file",
        H5Fflush(getId(),static_cast<H5F_scope_t>(scope))
    );
}
//@-others

}
//@-leo
