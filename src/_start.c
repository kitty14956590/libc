#include <_start.h>
#include <unistd.h>

void __attribute__((used)) _start(int argc, char * argv[], char * envp[]) {
	int ret = main(argc, argv, envp);
        syscall(0x3c, ret);
	while(1) {};
}
