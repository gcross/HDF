//@+leo-ver=5-thin
//@+node:gcross.20110524225139.1832: * @file container.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110524225139.1834: ** << License >>
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

#ifndef HDFPP_CONTAINER_HPP
#define HDFPP_CONTAINER_HPP

//@+<< Includes >>
//@+node:gcross.20110524225139.1833: ** << Includes >>
#include "file.hpp"
#include "group.hpp"
#include "locatable.hpp"
#include "location.hpp"
#include "parent.hpp"
#include "parameters.hpp"

#include <boost/optional.hpp>
#include <utility>
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110524225139.1835: ** class Container
class Container: public Containable, public Parent {
    //@+others
    //@+node:gcross.20110524225139.1836: *3* Constructors
    public:

    Container(File const& file);
    Container(Group const& group);
    Container(Location const& location);
    Container(
        CreateAt<Location const> location
      , boost::optional<LinkCreationProperties const&> const& optional_link_creation_properties = boost::none
      , boost::optional<GroupCreationProperties const&> const& optional_creation_properties = boost::none
    );

    protected:

    void initialize(
        Location const& location
      , boost::optional<std::pair<
            boost::optional<LinkCreationProperties const&>
         ,  boost::optional<GroupCreationProperties const&>
        > > const& creation_properties = boost::none
    );
    //@+node:gcross.20110524225139.1837: *3* Fields
    protected:

    File file;

    virtual hid_t getParentId() const;

    public:

    virtual File const& getFile() const;
    virtual Identity::Ptr const& getIdentity() const;
    //@+node:gcross.20110524225139.1856: *3* Operators
    public:

    void operator=(File const& file);
    void operator=(Group const& group);
    //@-others
};
//@-others

}

#endif
//@-leo
