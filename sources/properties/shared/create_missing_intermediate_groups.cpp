// Includes {{{
#include "properties/shared/create_missing_intermediate_groups.hpp"
// Includes }}}

namespace HDF {

CreateMissingIntermediateGroupsPropertyBase::CreateMissingIntermediateGroupsPropertyBase() {}

void CreateMissingIntermediateGroupsPropertyBase::setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups) const {
    assertSuccess(
        "setting create intermediate groups property",
        H5Pset_create_intermediate_group(
            getId(),
            create_missing_intermediate_groups
        )
    );
}

bool CreateMissingIntermediateGroupsPropertyBase::getCreateMissingIntermediateGroups() const {
    unsigned int create_missing_intermediate_groups;
    assertSuccess(
        "getting create intermediate groups property",
        H5Pget_create_intermediate_group(
            getId(),
            &create_missing_intermediate_groups
        )
    );
    return create_missing_intermediate_groups==1;
}

}
