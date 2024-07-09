#include <stdint.h>

size_t strlen(const char * string) {
	int i = 0;
	while (*string++) {
		i++;
	}
	return i;
}
