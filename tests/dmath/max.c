#include "dmath_test.h"
#include "dop/dmath.h"

#include <math.h>

int main(int argc, char **argv) {
    if (isgreater(fabs(max(test_list1, test_list1_len) - (+3.0)), DOUBLE_ALLOWED_DELTA)) {
        return 1;
    }
    return 0;
}
