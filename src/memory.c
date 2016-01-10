#include "dop/memory.h"

#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

size_t buffer_length_check(char ** buffer, size_t size, size_t needed) {
	char * new_buffer = *buffer;
	size_t initial_buffer_length = strlen(*buffer);
	if (initial_buffer_length + needed >= size) {
		while (initial_buffer_length + needed >= size) {
			size+=BUFFER_SIZE;
		}
		new_buffer = realloc(*buffer, size);
		if (new_buffer) {
			*buffer = new_buffer;
		}
	}
	return size;
}
