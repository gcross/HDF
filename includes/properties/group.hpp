//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2124: * @file group.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2126: ** << License >>
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

#ifndef HDFPP_PROPERTIES_GROUP_CREATION_HPP
#define HDFPP_PROPERTIES_GROUP_CREATION_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2125: ** << Includes >>
#include "../properties.hpp"
#include "shared/create_missing_intermediate_groups.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110526150836.1960: ** class GroupCreationProperties
struct GroupCreationProperties
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<GroupCreationProperties>
{
    friend class Group;

    DECLARE_PROPERTIES_BOILERPLATE(GroupCreation)
 
    //@+others
    //@+node:gcross.20110602121059.2114: *3* estimated link information
    GroupCreationProperties setEstimatedLinkInformation(
        unsigned int estimated_number_of_links,
        unsigned int estimated_average_link_name_lengths
    );

    void getEstimatedLinkInformation(
        unsigned int& estimated_number_of_links,
        unsigned int& estimated_average_link_name_lengths
    ) const;

    std::pair<unsigned int,unsigned int> getEstimatedLinkInformation() const;
    //@+node:gcross.20110602092541.2057: *3* link creation order
    GroupCreationProperties setLinkCreationOrderTracking(LinkCreationOrderTracking creation_order_tracking);
    LinkCreationOrderTracking getLinkCreationOrderTracking() const;
    //@+node:gcross.20110602092541.2048: *3* local heap size hint
    GroupCreationProperties setLocalHeapSizeHint(size_t size_hint);
    size_t getLocalHeapSizeHint() const;
    //@-others
};
//@-others

}

#endif
//@-leo
