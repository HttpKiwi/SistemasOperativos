#include "solucion.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv) {
	int x = 20;
	pid_t pid;
	pid = fork();
	if(pid == 0){
		x = fibonacci(x);
		guardarEntero("archivo",x);
		printf("Soy el hijo \n Calculo fibonacci \n  guardo el valor calculado en el archivo %s","archivo");
	}
	else{
		wait(NULL);
		int fb;
		fb = leerEntero("archivo");
		printf("Soy el padre \n espero a que termine mi hijo \n leo el valor que calculó mi hijo del archivo %s \n El resultado de Fibonacci(%d)*100 es %d\n","archivo",x, fb*100);
	}

	return 0;
}
