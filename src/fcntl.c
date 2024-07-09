#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>

int open(const char * name, int flags, ...) {
	mode_t mode;
	va_list list;
	va_start(list, flags);
	mode = va_arg(list, int);
	if (!mode) {
		mode = 0644;
	}
	return syscall(2, name, flags, mode);
}
