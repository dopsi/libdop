#include "dop/utils.h"
#include "dop/version.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HEXDUMP_LEN 16

size_t hexdump(void * data, size_t len) {
	size_t num_bytes = 0;
	char text_buffer[HEXDUMP_LEN+1] = { '\0' };
	for (size_t i = 0; i < len; ++i) {
		printf("%x ", ((char*)data)[i]);
		if (isprint(((char*)data)[i])) {
			sprintf(text_buffer + i%HEXDUMP_LEN, "%c", ((char*)text_buffer)[i]);
		} else {
			sprintf(text_buffer + i%HEXDUMP_LEN, ".");
		}
		if ((i+1)%HEXDUMP_LEN == 0) {
			printf("%s\n", text_buffer);
			memset(text_buffer, '\0', sizeof(text_buffer));
		}
	}
	return num_bytes;
}
