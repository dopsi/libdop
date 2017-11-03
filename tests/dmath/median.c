#include "dmath_test.h"
#include "dop/dmath.h"

#include <math.h>

int main(int argc, char **argv) {
    if (isgreater(fabs(median(test_list1, test_list1_len) - 0.5), DOUBLE_ALLOWED_DELTA)) {
        return 1;
    }

    return 0;
}
