#ifndef HDFPP_IMPLEMENTATION_PROPERTIES_SHARED_CREATE_MISSING_INTERMEDIATE_GROUPS_TEMPLATE_HPP
#define HDFPP_IMPLEMENTATION_PROPERTIES_SHARED_CREATE_MISSING_INTERMEDIATE_GROUPS_TEMPLATE_HPP

// Includes {{{
#include "../../properties.hpp"
// Includes }}}

namespace HDF {

class CreateMissingIntermediateGroupsPropertyBase : public virtual Properties { // {{{
protected:
    CreateMissingIntermediateGroupsPropertyBase();
    void setCreateMissingIntermediateGroups(bool create_missing_intermediate_groups=true) const;
public:
    bool getCreateMissingIntermediateGroups() const;
}; // }}}

template<typename T> class CreateMissingIntermediateGroupsProperty // {{{
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
}; // }}}

}

#endif
