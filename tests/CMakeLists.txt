#@+leo-ver=5-thin
#@+node:gcross.20110521115623.3222: * @file CMakeLists.txt
include_directories(".")

set(test-SOURCES
    attributes
    datasets
    dataspace
    datatypes
    files
    properties
)

add_executable(test EXCLUDE_FROM_ALL ${test-SOURCES})
target_link_libraries(test HDF++ ${Boost_LIBRARIES} illuminate-main illuminate)
set_property(TARGET test PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR})
#@-leo
