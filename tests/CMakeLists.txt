include_directories(".")
include_directories ( ${Illuminate_INCLUDE_DIRS} )
link_directories ( ${Illuminate_LIBRARY_DIRS} )

set(test-SOURCES
    attributes
    datasets
    dataspace
    datatypes
    files
    filters
    properties
)

add_executable(test EXCLUDE_FROM_ALL ${test-SOURCES})
target_link_libraries(test HDF++ illuminate-main illuminate)
set_property(TARGET test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
