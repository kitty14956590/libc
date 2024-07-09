#include <stdarg.h>
#include <unistd.h>
#include <errno.h>

long __syscall_return__(long r) {
	if (r > 0xfffff000) {
		errno = -r;
		return -1;
	}
	return r;
}

long syscall(long number, ...) {
	syscall_arg_t rdi;
	syscall_arg_t rsi;
	syscall_arg_t rdx;
	register syscall_arg_t r10 asm("r10");
	register syscall_arg_t r8 asm("r8");
	register syscall_arg_t r9 asm("r9");
	syscall_arg_t ret;
	va_list list;
	va_start(list, number);
	rdi = va_arg(list, syscall_arg_t);
	rsi = va_arg(list, syscall_arg_t);
	rdx = va_arg(list, syscall_arg_t);
	r10 = va_arg(list, syscall_arg_t);
	r8 = va_arg(list, syscall_arg_t);
	r9 = va_arg(list, syscall_arg_t);
	va_end(list);

	asm volatile ("syscall"
	: "=a"(ret) :
		"a"(number),
		"D"(rdi),
		"S"(rsi),
		"d"(rdx),
		"r"(r10),
		"r"(r8),
		"r"(r9)
	);
	return __syscall_return__(ret);
}
