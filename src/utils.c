#include "dop/utils.h"
#include "dop/version.h"

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define HEXDUMP_LEN 16

size_t hexdump(void * data, size_t len) {
	size_t num_bytes = 0;
	char text_buffer[HEXDUMP_LEN+1] = { '\0' };
	size_t i;
	size_t add;
	add = (len % HEXDUMP_LEN) ? (HEXDUMP_LEN - (len % HEXDUMP_LEN)) : 0;
	printf("len = %lu\n", len);
	printf("add = %lu\n", add);
	for (i = 0; i < len + add; ++i) {
		if (i%HEXDUMP_LEN == 0) {
			printf("%3.3lx ", i);
		}
		if (i%2 == 0) {
			printf(" ");
		}
		if (i < len) {
			printf("%2.2x", (unsigned char)((char*)data)[i]);
			if (isprint(((char*)data)[i])) {
				text_buffer[i%HEXDUMP_LEN] = ((char*)data)[i];
			} else {
				text_buffer[i%HEXDUMP_LEN] = '.';
			}
		} else {
			printf("  ");
			text_buffer[i%HEXDUMP_LEN] = ' ';
		}
		if ((i+1)%HEXDUMP_LEN == 0) {
			printf("  %s\n", text_buffer);
			memset(text_buffer, '\0', sizeof(text_buffer));
		}
	}
	return num_bytes;
}

/**
 * From http://www.cse.yorku.ca/~oz/hash.html
 * Modified to be used on void* data with not null terminator
 **/
unsigned long hash_djb2(void *data, size_t len) {
	void *current_data = data;
	unsigned long hash = 5381;
	int c;
	
	while (current_data != data+len) {
		c = *(unsigned char*)current_data++;
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	}
	
	return hash;
}
