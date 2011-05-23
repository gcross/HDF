#@+leo-ver=5-thin
#@+node:gcross.20110524225139.1921: * @file CMakeLists.txt
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/HDF++-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/HDF++-config.cmake @ONLY
)

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/HDF++-config-version.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/HDF++-config-version.cmake @ONLY
)

install(
    FILES
        ${CMAKE_CURRENT_BINARY_DIR}/HDF++-config.cmake
        ${CMAKE_CURRENT_BINARY_DIR}/HDF++-config-version.cmake
    DESTINATION
        lib/HDF++-${version}
)

install (
    EXPORT HDF++-targets
    DESTINATION lib/HDF++-${version}
)
#@-leo
