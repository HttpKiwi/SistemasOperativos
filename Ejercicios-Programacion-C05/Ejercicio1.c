#include <unistd.h>
#include <stdio.h>

int main(int argc, char** argv){
	int x=0;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		printf("Soy el hijo. El valor actual de x es %d\n ",x); 
		//Se espera que el hijo tenga el valor asignado al principio del programa, el cual es 0
		x = 15;
		printf("El nuevo valor de x es %d\n", x);
	}
	else{
		printf("Soy el padre. El valor de x es %d\n",x);
		x = 10;
		printf("Ahora el valor de x es %d\n",x);
	}
}
