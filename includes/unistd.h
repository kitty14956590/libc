#pragma once

#include <stdint.h>
#include <fcntl.h>

long syscall(long, ...);
ssize_t write(int, const void *, size_t);
int close(int fd);


typedef unsigned long long int syscall_arg_t;
