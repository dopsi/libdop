#include "dop/memory.h"

#include <stdlib.h>

int main() {
	size_t buffer_size = 1024;
	char *buffer = calloc(buffer_size, sizeof(char));
	int rvalue = 0;

	if ( buffer_length_check(&buffer, buffer_size, buffer_size+1) != buffer_size+16) {
		rvalue = 1;
	}

	free(buffer);
	buffer = NULL;

	return rvalue;
}

