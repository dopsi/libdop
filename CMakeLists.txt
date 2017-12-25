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

set(C_STANDARD 11)

include_directories(BEFORE ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/src)

# Build
add_library(dop SHARED
    src/filesystem.c
    src/memory.c
    src/utils.c
    src/dmath.c
    src/dstring.c)

add_executable(hexdump_test
    tests/hexdump-test.c)

add_executable(buffer_test
    tests/buffer-test.c)

add_executable(hash_djb2_test
    tests/hash_djb2-test.c)

add_executable(dmath_max_test
    tests/dmath/max.c)

add_executable(dmath_mean_test
    tests/dmath/mean.c)

add_executable(dmath_median_test
    tests/dmath/median.c)

add_executable(dmath_min_test
    tests/dmath/min.c)

add_executable(dmath_range_test
    tests/dmath/range.c)

add_executable(dmath_standart_deviation_test
    tests/dmath/standart_deviation.c)

add_executable(dmath_sum_test
    tests/dmath/sum.c)

add_executable(dmath_variance_test
    tests/dmath/variance.c)

add_executable(dstring_test_trimwhitespace
    tests/dstring/test_trimwhitespace.c)

add_executable(dstring_test_strcharcount
    tests/dstring/test_strcharcount.c)

# Linking
target_link_libraries(dop
    m)

target_link_libraries(hexdump_test
    dop)

target_link_libraries(buffer_test
    dop)

target_link_libraries(hash_djb2_test
    dop)

target_link_libraries(dmath_max_test
    dop)

target_link_libraries(dmath_mean_test
    dop)

target_link_libraries(dmath_median_test
    dop)

target_link_libraries(dmath_min_test
    dop)

target_link_libraries(dmath_range_test
    dop)

target_link_libraries(dmath_standart_deviation_test
    dop)

target_link_libraries(dmath_sum_test
    dop)

target_link_libraries(dmath_variance_test
    dop)

target_link_libraries(dstring_test_trimwhitespace
    dop)

target_link_libraries(dstring_test_strcharcount
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
add_test(NAME hexdump COMMAND hexdump_test)
add_test(NAME buffer COMMAND buffer_test)
add_test(NAME djb2_hash_on_string COMMAND hash_djb2_test)
add_test(NAME dmath_max COMMAND dmath_max_test)
add_test(NAME dmath_mean COMMAND dmath_mean_test)
add_test(NAME dmath_median COMMAND dmath_median_test)
add_test(NAME dmath_min COMMAND dmath_min_test)
add_test(NAME dmath_range COMMAND dmath_range_test)
add_test(NAME dmath_standart_deviation COMMAND dmath_standart_deviation_test)
add_test(NAME dmath_sum COMMAND dmath_sum_test)
add_test(NAME dmath_variance COMMAND dmath_variance_test)
add_test(NAME dstring_test_trimwhitespace COMMAND dstring_test_trimwhitespace)
add_test(NAME dstring_test_strcharcount COMMAND dstring_test_strcharcount)
