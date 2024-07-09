#include <unistd.h>

void exit(int status) {
	syscall(0x3c, status);
	while (1) {};
}
