#ifndef LIBDOP_UTILS_H
#define LIBDOP_UTILS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * @brief Write a hexdump to stdout
 * @param data Address to be dumped
 * @param len Length of the data to be dumped
 * @return The actual length of the data that has been dumped
 **/
size_t hexdump(void * data, size_t len);

#ifdef __cplusplus
}
#endif

#endif // LIBDOP_UTILS_H
