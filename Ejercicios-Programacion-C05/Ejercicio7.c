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
		close(STDOUT_FILENO);
		printf("Cerre la salida estandar\n");
	}
	else{
		wait(NULL);
		printf("soy el padre\n");
	}
}
