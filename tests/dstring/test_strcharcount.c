#include "dop/dstring.h"

#include <string.h>

#define BUFFER_LEN 36

int main(int argc, char **argv) {
    const char start_buffer[BUFFER_LEN] = " \t\nHello, World! \t\nBonjour,le,Monde!";
    
    if (strcharcount(start_buffer, ',') != 3) {
        return 1;
    }

    return 0;
}
