#@+leo-ver=5-thin
#@+node:gcross.20110520211700.1428: * @file CMakeLists.txt
cmake_minimum_required (VERSION 2.8)
project (HDF++ C CXX)
set (version 0.2)

#@+<< Settings >>
#@+node:gcross.20110520211700.1429: ** << Settings >>
set (LIBRARY_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH
    "Single directory for all libraries."
    )

set (EXECUTABLE_OUTPUT_PATH
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single directory for all executables."
    )

mark_as_advanced(
    LIBRARY_OUTPUT_PATH
    EXECUTABLE_OUTPUT_PATH
    )
#@-<< Settings >>

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules/")

#@+<< Platform-specific tweaks >>
#@+node:gcross.20110520211700.1430: ** << Platform-specific tweaks >>
if(APPLE)
    message (STATUS "Compiling on Darwin, adding -arch x86_64")
    add_definitions(-arch x86_64)
endif(APPLE)

if(UNIX)
    if(CMAKE_COMPILER_IS_GNUCC)
         add_definitions(-Wall -Wno-strict-aliasing)
    endif(CMAKE_COMPILER_IS_GNUCC)
endif(UNIX)
#@-<< Platform-specific tweaks >>

#@+<< Find packages >>
#@+node:gcross.20110520211700.1431: ** << Find packages >>
#@+others
#@+node:gcross.20110520211700.1434: *3* Boost
SET(Boost_ADDITIONAL_VERSIONS "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46.0" "1.46.1")
find_package( Boost 1.46 COMPONENTS program_options thread REQUIRED )
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )
#@+node:gcross.20110520211700.1435: *3* HDF5
find_package( HDF5 REQUIRED )
include_directories ( ${HDF5_INCLUDE_DIRS} )
link_directories ( ${HDF5_LIBRARY_DIRS} )
#@-others
#@-<< Find packages >>

#@+<< Configure build type >>
#@+node:gcross.20110520211700.1438: ** << Configure build type >>
if( NOT CMAKE_BUILD_TYPE )
set( CMAKE_BUILD_TYPE "RelWithDebInfo" )
endif ()

message (STATUS "Build type is " ${CMAKE_BUILD_TYPE})
#@-<< Configure build type >>

include_directories ("includes")

add_subdirectory ("includes")
add_subdirectory ("package")
add_subdirectory ("sources")
add_subdirectory ("tests")
#@-leo
