#@+leo-ver=5-thin
#@+node:gcross.20110520211700.1444: * @file CMakeLists.txt
add_library(HDF++
    attribute
    attributable
    containable
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
    identity
    location
    location_iterator
    locatable
    memory_file
    object
    parent
    properties
    temporary_memory_file
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
