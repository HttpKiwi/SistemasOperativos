#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){

	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Hello\n");
	}
	else{
		wait(NULL);
		printf("goodbye\n");
	}
}

