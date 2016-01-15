#ifndef LIBDOP_MEMORY_H
#define LIBDOP_MEMORY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>

/**
 * @brief Check for buffer length and resize it if needed.
 * @param buffer The address of the buffer to be checked
 * @param size The current size of the buffer
 * @param needed The additionnal size needed for the buffer
 * @return The size of the new buffer
 **/
size_t buffer_length_check(char ** buffer, size_t size, size_t needed);

#ifdef __cplusplus
}
#endif

#endif /* LIBDOP_MEMORY_H */
