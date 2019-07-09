#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
	int x=0;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Soy el hijo y mi identificador es %d\n El valor actual de x es %d\n ",(int) getpid(),x); 
		//Se espera que el hijo tenga el valor asignado al principio del programa, el cual es 0
		x = 15;
		printf("El nuevo valor de x es %d\n", x);
	}
	else{
		int x = 10;
		printf("Soy el padre,  mi identificador es %d y el de mi hijo %d\n El valor de x es %d\n",(int) getpid(),(int) pid,x);
	}
}
