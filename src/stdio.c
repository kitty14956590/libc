#include <unistd.h>
#include <string.h>

int puts(const char * str) {
	ssize_t a = write(1, str, strlen(str));
	ssize_t b = write(1, "\r\n", 2);
	if (a == -1 || b == -1) {
		return -1;
	}
	return a + b;
}
