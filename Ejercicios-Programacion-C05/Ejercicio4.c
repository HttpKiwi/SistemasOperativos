#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){

	argv[0] = "/bin/ls";
	argv[1] = NULL; //todos los arreglos deben terminar en NULL
	pid_t pid = fork();
	if(pid == 0){
		execv(argv[0],argv);
		//execvp(argv[0],argv);
		//execlp(argv[0],argv);
		//execl(argv[0],argv);
	}
	else{
		wait(NULL);
	}
}
