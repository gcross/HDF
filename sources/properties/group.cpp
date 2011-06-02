//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2213: * @file group.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2214: ** << License >>
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
//@+node:gcross.20110602092541.2215: ** << Includes >>
#include "properties/group.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110602092541.2216: ** << Usings >>
using std::pair;
//@-<< Usings >>

//@+others
//@+node:gcross.20110602092541.2221: ** Properties
//@+node:gcross.20110602092541.2049: *3* GroupCreationProperties
DEFINE_PROPERTIES_BOILERPLATE(GroupCreation,group creation,GROUP_CREATE)

//@+others
//@+node:gcross.20110602121059.2116: *4* estimated link information
GroupCreationProperties GroupCreationProperties::setEstimatedLinkInformation(
    unsigned int estimated_number_of_links,
    unsigned int estimated_average_link_name_lengths
) {
    assertSuccess(
        "setting estimated link information",
        H5Pset_est_link_info(
            getId(),
            estimated_number_of_links,
            estimated_average_link_name_lengths
        )
    );
    return *this;
}

void GroupCreationProperties::getEstimatedLinkInformation(
    unsigned int& estimated_number_of_links,
    unsigned int& estimated_average_link_name_lengths
) const  {
    assertSuccess(
        "setting estimated link information",
        H5Pget_est_link_info(
            getId(),
            &estimated_number_of_links,
            &estimated_average_link_name_lengths
        )
    );
}

pair<unsigned int,unsigned int> GroupCreationProperties::getEstimatedLinkInformation() const {
    pair<unsigned int,unsigned int> estimated_link_information;
    getEstimatedLinkInformation(
        estimated_link_information.first,
        estimated_link_information.second
    );
    return estimated_link_information;
}
//@+node:gcross.20110602092541.2059: *4* link creation order flags
GroupCreationProperties GroupCreationProperties::setLinkCreationOrderTracking(LinkCreationOrderTracking creation_order_tracking) {
    assertSuccess(
        "setting link creation order flags",
        H5Pset_link_creation_order(
            getId(),
            static_cast<unsigned int>(creation_order_tracking)
        )
    );
    return *this;
}

LinkCreationOrderTracking GroupCreationProperties::getLinkCreationOrderTracking() const {
    unsigned int creation_order_flags;
    assertSuccess(
        "getting link creation order flags",
        H5Pget_link_creation_order(
            getId(),
            &creation_order_flags
        )
    );
    return static_cast<LinkCreationOrderTracking>(creation_order_flags);
}
//@+node:gcross.20110602092541.2052: *4* local heap size hint
GroupCreationProperties GroupCreationProperties::setLocalHeapSizeHint(size_t size_hint) {
    assertSuccess(
        "setting local heap size hint",
        H5Pset_local_heap_size_hint(
            getId(),
            size_hint
        )
    );
    return *this;
}

size_t GroupCreationProperties::getLocalHeapSizeHint() const {
    size_t size_hint;
    assertSuccess(
        "getting local heap size hint",
        H5Pget_local_heap_size_hint(
            getId(),
            &size_hint
        )
    );
    return size_hint;
}
//@-others
//@-others

}
//@-leo
