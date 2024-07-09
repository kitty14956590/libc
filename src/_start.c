#include <_start.h>
#include <stdlib.h>

void __attribute__((used)) _start(int argc, char * argv[], char * envp[]) {
	exit(main(argc, argv, envp));
	while(1) {};
}
