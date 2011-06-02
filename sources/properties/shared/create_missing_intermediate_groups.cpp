//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2245: * @file create_missing_intermediate_groups.cpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2246: ** << License >>
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
