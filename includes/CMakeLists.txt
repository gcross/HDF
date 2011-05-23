#@+leo-ver=5-thin
#@+node:gcross.20110524225139.1924: * @file CMakeLists.txt
FILE(GLOB HEADERS "*.hpp")

install(FILES ${HEADERS} DESTINATION include/hdf++-${version}/hdf++)
#@-leo
