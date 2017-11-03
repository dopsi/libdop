#include "dop/dmath.h"

#include <math.h>

double max(const double *list, size_t len) {
    double m = -HUGE_VAL;
    size_t i;

    for (i=0; i<len; ++i) {
        if (m < list[i]) {
            m = list[i];
        }
    }

    return m;
}

double min(const double *list, size_t len) {
    double m = HUGE_VAL;
    size_t i;

    for (i=0; i<len; ++i) {
        if (m > list[i]) {
            m = list[i];
        }
    }

    return m;
}

double range(const double *list, size_t len) {
    return max(list, len) - min(list, len);
}

double sum(const double *list, size_t len) {
    double s = 0.0;
    size_t i;

    for (i=0; i < len; ++i) {
        s += list[i];
    }

    return s;
}
    
double mean(const double *list, size_t len) {
    return sum(list, len) / (double)len;
}

double median(const double *list, size_t len) {
    if (len == 0) {
        return HUGE_VAL;
    }

    double m = HUGE_VAL;

    if (len % 2) { // odd
        return list[(len+1)/2 - 1];
    } else { // even
        return (list[len/2 - 1]+list[len/2])/2;
    }
}

double variance(const double *list, size_t len) {
    double s = 0.0;
    double m = 0.0;
    size_t i;

    m = mean(list, len);

    for (i = 0; i < len; ++i) {
        s += pow(list[i] - m, 2);
    }

    return s/(double)len;
}

double standart_deviation(const double *list, size_t len) {
    return sqrt(variance(list, len));
}
