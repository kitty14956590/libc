#pragma once
#define O_RDONLY 00
#define O_WRONLY 01
#define O_RDWR 02
#define O_CREAT 0100

int open(const char *pathname, int flags, ...);

typedef unsigned short mode_t;
