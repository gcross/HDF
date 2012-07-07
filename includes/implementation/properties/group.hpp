#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_GROUP_CREATION_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_GROUP_CREATION_HPP

// Includes {{{
#include "../properties.hpp"
#include "shared/create_missing_intermediate_groups.hpp"
// Includes }}}

namespace HDF {

struct GroupCreationProperties // {{{
  : public virtual Properties
  , public CreateMissingIntermediateGroupsProperty<GroupCreationProperties>
{
    friend class Group;

    DECLARE_PROPERTIES_BOILERPLATE(GroupCreation)
 
  // estimated link informations {{{
    GroupCreationProperties setEstimatedLinkInformation(
        unsigned int estimated_number_of_links,
        unsigned int estimated_average_link_name_lengths
    );

    void getEstimatedLinkInformation(
        unsigned int& estimated_number_of_links,
        unsigned int& estimated_average_link_name_lengths
    ) const;

    std::pair<unsigned int,unsigned int> getEstimatedLinkInformation() const;
  // estimated link informations }}}
  // link creation order {{{
    GroupCreationProperties setLinkCreationOrderTracking(LinkCreationOrderTracking creation_order_tracking);
    LinkCreationOrderTracking getLinkCreationOrderTracking() const;
  // link creation order }}}
  // local heap size hint {{{
    GroupCreationProperties setLocalHeapSizeHint(size_t size_hint);
    size_t getLocalHeapSizeHint() const;
  // local heap size hint }}}
}; // }}}

}

#endif
