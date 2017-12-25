#ifndef LIBDOP_DMATH_H
#define LIBDOP_DMATH_H

#include <stddef.h>

/**
 * @brief Count the number of characters
 *
 * @param str string to be checked (must be NULL-terminated)
 * @param c character to be counted
 *
 * @return the number of characters found
 */
size_t strcharcount(const char *str, char c);

/**
 * @brief Remove leading and trailing whitespace
 *
 * @param out output buffer
 * @param len outpub buffer lenght
 * @param str input buffer
 *
 * @return The length of copied characters
 */
size_t trimwhitespace(char *out, size_t len, const char *str);

#endif // LIBDOP_DMATH_H

