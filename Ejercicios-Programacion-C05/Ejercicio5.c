#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int x = 0;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Hola, soy el hijo y mi id es %d\n",(int) getpid());
	}
	else{
		x = wait(NULL);
		printf("El id del hijo que terminò es %d\n",x);
	}
}
