//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2124: * @file group.hpp
//@@language cplusplus
#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_GROUP_CREATION_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_GROUP_CREATION_HPP

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
