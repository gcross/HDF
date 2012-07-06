// Includes {{{
#include "properties/group.hpp"
// Includes }}}

// Usings {{{
using std::pair;
// Usings }}}

namespace HDF {

// Properties {{{
// group creation {{{
DEFINE_PROPERTIES_BOILERPLATE(GroupCreation,group creation,GROUP_CREATE)

//         estimated link information {{{
GroupCreationProperties GroupCreationProperties::setEstimatedLinkInformation(
    unsigned int estimated_number_of_links,
    unsigned int estimated_average_link_name_lengths
) { // {{{
    assertSuccess(
        "setting estimated link information",
        H5Pset_est_link_info(
            getId(),
            estimated_number_of_links,
            estimated_average_link_name_lengths
        )
    );
    return *this;
} // }}}

void GroupCreationProperties::getEstimatedLinkInformation(
    unsigned int& estimated_number_of_links,
    unsigned int& estimated_average_link_name_lengths
) const  { // {{{
    assertSuccess(
        "setting estimated link information",
        H5Pget_est_link_info(
            getId(),
            &estimated_number_of_links,
            &estimated_average_link_name_lengths
        )
    );
} // }}}

pair<unsigned int,unsigned int> GroupCreationProperties::getEstimatedLinkInformation() const { // {{{
    pair<unsigned int,unsigned int> estimated_link_information;
    getEstimatedLinkInformation(
        estimated_link_information.first,
        estimated_link_information.second
    );
    return estimated_link_information;
} // }}}
//         estimated link information }}}
//         link creation order flags {{{
GroupCreationProperties GroupCreationProperties::setLinkCreationOrderTracking(LinkCreationOrderTracking creation_order_tracking) { // {{{
    assertSuccess(
        "setting link creation order flags",
        H5Pset_link_creation_order(
            getId(),
            static_cast<unsigned int>(creation_order_tracking)
        )
    );
    return *this;
} // }}}

LinkCreationOrderTracking GroupCreationProperties::getLinkCreationOrderTracking() const { // {{{
    unsigned int creation_order_flags;
    assertSuccess(
        "getting link creation order flags",
        H5Pget_link_creation_order(
            getId(),
            &creation_order_flags
        )
    );
    return static_cast<LinkCreationOrderTracking>(creation_order_flags);
} // }}}
//         link creation order flags }}}
//         local heap size hint {{{
GroupCreationProperties GroupCreationProperties::setLocalHeapSizeHint(size_t size_hint) { // {{{
    assertSuccess(
        "setting local heap size hint",
        H5Pset_local_heap_size_hint(
            getId(),
            size_hint
        )
    );
    return *this;
} // }}}

size_t GroupCreationProperties::getLocalHeapSizeHint() const { // {{{
    size_t size_hint;
    assertSuccess(
        "getting local heap size hint",
        H5Pget_local_heap_size_hint(
            getId(),
            &size_hint
        )
    );
    return size_hint;
} // }}}
//         local heap size hint }}}

// group creation }}}
// Properties }}}

}
