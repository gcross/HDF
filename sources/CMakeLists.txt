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
install (TARGETS HDF++ LIBRARY DESTINATION lib)
install (
    TARGETS HDF++
    DESTINATION lib
    EXPORT HDF++-targets
)
