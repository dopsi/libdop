#include "dop/dstring.h"

#include <string.h>

#define BUFFER_LEN 20

int main(int argc, char **argv) {
    const char start_buffer[BUFFER_LEN] = " \t\nHello, World! \t\n";
    char output_buffer[BUFFER_LEN] = {'\0'};
    
    if (trimwhitespace(output_buffer, BUFFER_LEN, start_buffer) != 13) {
        return 1;
    }

    if (strcmp(output_buffer, "Hello, World!")) {
        return 2;
    }

    return 0;
}
