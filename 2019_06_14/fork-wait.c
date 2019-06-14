#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
/*

Este programa en C debe imprimir lo siguiente:

Soy el hijo y mi identificador es 34567
Soy el padre, mi identificador es 34566 y el de mi hijo es 34567

hacer uso de la funcion 'getpid()'

*/

int main(int argc, char** argv){
	pid_t pid;
	pid = fork();
	if(pid == 0){
		sleep(3);
		printf("Soy el hijo y mi identificador es %d\n",(int) getpid());
	}
	else{
		pid_t pid2;
		int status;
		printf("Soy el padre,  mi identificador es %d y el de mi hijo %d\n",(int) getpid(),(int) pid);
		pid2 = wait(NULL);
		printf("Terminó el hijo %d\n",pid2);
	}
}

