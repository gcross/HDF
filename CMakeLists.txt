cmake_minimum_required (VERSION 2.8)
project (HDF++ C CXX)
set (version 0.4)

# Settings {{{
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
# }}}

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMakeModules/")

# Platform-specific tweaks {{{
if(APPLE)
    message (STATUS "Compiling on Darwin, adding -arch x86_64")
    add_definitions(-arch x86_64)
endif(APPLE)

if(UNIX)
    if(CMAKE_COMPILER_IS_GNUCC)
         add_definitions(-Wall -Wno-strict-aliasing)
    endif(CMAKE_COMPILER_IS_GNUCC)
endif(UNIX)
# Platform-specific tweaks }}}

# Find dependencies {{{
# Boost {{{
SET(Boost_ADDITIONAL_VERSIONS "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46.0" "1.46.1")
find_package( Boost 1.46 COMPONENTS REQUIRED )
link_directories ( ${Boost_LIBRARY_DIRS} )
include_directories ( ${Boost_INCLUDE_DIRS} )
# Boost }}}
# HDF5 {{{
if(${CMAKE_PATCH_VERSION} LESS 5)
  find_package( HDF5 REQUIRED )
else()
  find_package( HDF5 COMPONENTS C HL REQUIRED )
endif()
include_directories ( ${HDF5_INCLUDE_DIRS} )
link_directories ( ${HDF5_LIBRARY_DIRS} )
# HDF5 }}}
# Find dependencies }}}

# Configure build type {{{
if( NOT CMAKE_BUILD_TYPE )
set( CMAKE_BUILD_TYPE "RelWithDebInfo" )
endif ()

message (STATUS "Build type is " ${CMAKE_BUILD_TYPE})
# Configure build type }}}

include_directories ("includes")

add_subdirectory ("includes")
add_subdirectory ("package")
add_subdirectory ("sources")

# Configure tests {{{
find_package( Illuminate )

if(${Illuminate_FOUND})
    add_subdirectory ("tests")
else(${Illuminate_FOUND})
    add_custom_target(test
        COMMAND ${CMAKE_COMMAND} -E echo "The Illuminate library is required to build the tests."
    )
endif(${Illuminate_FOUND})
# Configure tests }}}
