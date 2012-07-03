//@+leo-ver=5-thin
//@+node:gcross.20110602092541.2148: * @file create_missing_intermediate_groups.hpp
//@@language cplusplus
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
