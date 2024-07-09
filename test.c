#include <stdio.h>
#include <unistd.h>

int main() {
	int file;
	puts("Hello World!");

	puts("Writing \"hello\" to /tmp/file.txt");
	file = open("/tmp/file.txt", O_WRONLY | O_CREAT, 0644);
	write(file, "hello\r\n", 7);
	close(file);
	return file;
}
