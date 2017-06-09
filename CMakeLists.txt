cmake_minimum_required(VERSION 2.6)
# Check for out-of-source build
if( CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR AND NOT MSVC_IDE )
	message(FATAL_ERROR "In-source builds are not allowed.
	Please create a directory and run cmake from there, passing the path
	to this source directory as the last argument.
	This process created the file `CMakeCache.txt' and the directory `CMakeFiles'.
	Please delete them.")
endif()

enable_testing()

# Set project data
project(libdop)
set(libdop_VERSION_MAJOR 1)
set(libdop_VERSION_MINOR 1)
set(libdop_VERSION_REVISION 2)

# Build
add_library(dop SHARED
	src/filesystem.c
	src/memory.c
	src/utils.c)

add_executable(hexdump_test
	tests/hexdump-test.c)

# Linking
target_link_libraries(hexdump_test
	dop)

# Install
install(TARGETS dop LIBRARY DESTINATION lib)
install_files("/include/dop" .h
	${CMAKE_SOURCE_DIR}/src/dop/utils.h
	${CMAKE_SOURCE_DIR}/src/dop/memory.h
	${CMAKE_SOURCE_DIR}/src/dop/filesystem.h
	${CMAKE_SOURCE_DIR}/src/dop/version.h)
install_files("/share/pkgconfig" .pc
	${CMAKE_SOURCE_DIR}/pkgconfig/dop.pc)

# Tests
add_test(NAME hexdump_test COMMAND hexdump_test)
