#include "dop/utils.h"

#include <string.h>

unsigned long hash(unsigned char *str)
{
	unsigned long hash = 5381;
	int c;
	
	while (c = *str++)
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	
	return hash;
}

int main() {
	int rvalue = 0;

	char hello[] = "hello world\0";

	if (hash(hello) != hash_djb2(hello, strlen(hello))) {
		rvalue = 1;
	}

	return rvalue;
}

