//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2148: * @file create_missing_intermediate_groups.hpp
//@@language cplusplus

//@+<< License >>
//@+node:gcross.20110602092541.2150: ** << License >>
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

#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_SHARED_CREATE_MISSING_INTERMEDIATE_GROUPS_TEMPLATE_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_SHARED_CREATE_MISSING_INTERMEDIATE_GROUPS_TEMPLATE_HPP

//@+<< Includes >>
//@+node:gcross.20110602092541.2149: ** << Includes >>
#include "../../properties.hpp"
//@-<< Includes >>

namespace HDF {

//@+others
//@+node:gcross.20110525201928.3114: ** class CreateMissingIntermediateGroupsProperty
class CreateMissingIntermediateGroupsPropertyBase : public virtual Properties {
protected:
    CreateMissingIntermediateGroupsPropertyBase();
    void setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const;
public:
    bool getCreateMissingIntermediateGroups() const;
};

template<typename T> class CreateMissingIntermediateGroupsProperty
  : public CreateMissingIntermediateGroupsPropertyBase
{
private:
    typedef CreateMissingIntermediateGroupsPropertyBase Base;
protected:
    CreateMissingIntermediateGroupsProperty() {}
public:
    T setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const {
        Base::setCreateMissingIntermediateGroups(create_missing_intermediate_groups);
        return *static_cast<T const*>(this);
    }
    T createMissingIntermediateGroups() const {
        return setCreateMissingIntermediateGroups(true);
    }
    T dontCreateMissingIntermediateGroups() const {
        return setCreateMissingIntermediateGroups(false);
    }
};
//@-others

}

#endif
//@-leo
