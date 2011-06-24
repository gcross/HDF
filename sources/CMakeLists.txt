#@+leo-ver=5-thin
#@+node:gcross.20110520211700.1444: * @file CMakeLists.txt
add_library(HDF++
    attributable
    attribute
    contained
    container
    dataset
    dataspace
    datatype
    enumerations
    error
    file
    filter
    group
    group_array
    identifiable
    identified
    identity
    locatable
    location
    location_iterator
    memory_file
    object
    parent
    properties.cpp
    temporary_memory_file
    properties/dataset
    properties/file
    properties/group
    properties/link
    properties/shared/create_missing_intermediate_groups
)
target_link_libraries(HDF++
    ${HDF5_LIBRARIES}
)
install (
    TARGETS HDF++
    DESTINATION lib/HDF++-${version}
    EXPORT HDF++-targets
)
#@-leo
