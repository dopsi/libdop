#include "dop/utils.h"

#include <string.h>

int main() {
	int a = 5;
	struct {
		int *int_ptr;
		char *msg;
		double time;
		char c;
	} hello;

	struct {
		int *int_ptr;
		char *msg;
		double time;
	} hello2;

	char hello3[] = "Violence is the last refuge of the incompetent.\0";

	hello.int_ptr = &a;
	hello.msg = "Hexdump test\0";
	hello.time = 3.1415;

	hello.int_ptr = &a;
	hello.msg = "Hexdump test\0";
	hello.time = 3.1415;
	hello.c = 'a';

	hexdump(&hello, sizeof(hello));
	hexdump(&hello2, sizeof(hello2));
	hexdump(&hello3, strlen(hello3));
	return 0;
}
