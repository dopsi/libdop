#ifndef LIBDOP_FILESYSTEM_H
#define LIBDOP_FILESYSTEM_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Recursively remove a path
 * @param path Path to be removed
 * @return Something
 **/
int remove_r(char * path);

#ifdef __cplusplus
}
#endif

#endif /* LIBDOP_FILESYSTEM_H */
