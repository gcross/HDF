//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2245: * @file create_missing_intermediate_groups.cpp
//@@language cplusplus
//@+<< Includes >>
//@+node:gcross.20110602092541.2247: ** << Includes >>
#include "properties/shared/create_missing_intermediate_groups.hpp"
//@-<< Includes >>

namespace HDF {

//@+<< Usings >>
//@+node:gcross.20110602092541.2248: ** << Usings >>
//@-<< Usings >>

//@+others
//@+node:gcross.20110525201928.3116: ** class CreateMissingIntermediateGroupsProperty
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
//@-others

}
//@-leo
