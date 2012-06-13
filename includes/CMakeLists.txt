#@+leo-ver=5-thin
#@+node:gcross.20110524225139.1924: * @file CMakeLists.txt
FILE(GLOB HEADERS "*.hpp")
FILE(GLOB HEADERS-properties "properties/*.hpp")
FILE(GLOB HEADERS-properties-shared "properties/shared/*.hpp")

FILE(GLOB HEADERS-implementation "implementation/*.hpp")
FILE(GLOB HEADERS-implementation-properties "implementation/properties/*.hpp")
FILE(GLOB HEADERS-implementation-properties-shared "implementation/properties/shared/*.hpp")

set(HEADER_DESTINATION include/hdf++-${version}/hdf++)

install(FILES ${HEADERS} DESTINATION ${HEADER_DESTINATION})
install(FILES ${HEADERS-properties} DESTINATION ${HEADER_DESTINATION}/properties)
install(FILES ${HEADERS-properties-shared} DESTINATION ${HEADER_DESTINATION}/properties/shared)
install(FILES ${HEADERS-implementation} DESTINATION ${HEADER_DESTINATION}/implementation)
install(FILES ${HEADERS-implementation-properties} DESTINATION ${HEADER_DESTINATION}/implementation/properties)
install(FILES ${HEADERS-implementation-properties-shared} DESTINATION ${HEADER_DESTINATION}/implementation/properties/shared)
#@-leo
