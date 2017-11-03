#ifndef LIBDOP_DMATH_H
#define LIBDOP_DMATH_H

#include <stddef.h>

/**
 * @brief Obtain maximum value from double array
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the maximum value of the array, -HUGE_VAL otherwise
 */
double max(const double *list, size_t len);

/**
 * @brief Obtain minimum value from double array
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the minimum value of the array, HUGE_VAL otherwise
 */
double min(const double *list, size_t len);

/**
 * @brief Obtain the difference between the maximum and minimum from double array
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the maximum value of the array, -HUGE_VAL otherwise
 */
double range(const double *list, size_t len);

/**
 * @brief Obtain the sum of the array
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the sum
 */
double sum(const double *list, size_t len);

/**
 * @brief Obtain the arithmetic mean
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the mean
 */
double mean(const double *list, size_t len);

/**
 * @brief Obtain median
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the median value of the array
 */
double median(const double *list, size_t len);

/**
 * @brief Obtain variance
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the variance
 */
double variance(const double *list, size_t len);

/**
 * @brief Obtain the standart deviation
 *
 * @param list array of double
 * @param len lenght of the array
 *
 * @return the standart deviation
 */
double standart_deviation(const double *list, size_t len);

#endif // LIBDOP_DMATH_H
