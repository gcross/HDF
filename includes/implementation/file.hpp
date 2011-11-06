//@+leo-ver=5-thin
//@+node:gcross.20110520194631.1392: * @file file.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110520194631.1394: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_FILE_HPP
#define HDFPP_IMPLEMENTATION_FILE_HPP

//@+<< Includes >>
//@+node:gcross.20110520194631.1393: ** << Includes >>
#include "attributable.hpp"
#include "error.hpp"
#include "locatable.hpp"
#include "parameters.hpp"
#include "parent.hpp"
#include "properties/file.hpp"
#include "properties/link.hpp"

#include <boost/optional.hpp>
#include <hdf5.h>
#include <string>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110520194631.1395: ** class File
//@+<< Forward declarations >>
//@+node:gcross.20110529102535.2040: *3* << Forward declarations >>
class Contained;
//@-<< Forward declarations >>

class File
  : public Identified
  , public Parent
  , public Attributable
{
    //@+others
    //@+node:gcross.20110520194631.1424: *3* Constructors
    protected:

    File(hid_t id);
    File(Identity::Ptr const& identity);

    public:

    File();

    File(
        char const* filepath
      , FileOpenMode mode
      , boost::optional<FileAccessProperties const&> const& optional_properties = boost::none
    );

    File(
        char const* filepath
      , FileCreateMode mode
      , boost::optional<FileCreationProperties const&> const& optional_creation_properties = boost::none
      , boost::optional<FileAccessProperties const&> const& optional_access_properties = boost::none
    );
    //@+node:gcross.20110523113700.1690: *3* Fields
    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //@+node:gcross.20110520211700.1487: *3* Friends
    friend class Contained;
    //@+node:gcross.20110521115623.3023: *3* Miscellaneous
    public:

    void flush(FileFlushScope scope=GlobalFileScope) const;

    FileAccessProperties getCopyOfAccessProperties() const;
    FileCreationProperties getCopyOfCreationProperties() const;
    size_t getFreeSpace() const;
    //@-others
};
//@-others

}

#endif
//@-leo
