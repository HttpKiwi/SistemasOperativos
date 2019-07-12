#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

	int bytes;

	if(argc < 2){
		printf("No se encontraron argumentos\n");
		return 1;
	}
	bytes = atoi(argv[1]);

	int* array = malloc((bytes*1024*1024)*(sizeof(int)));

	if(array  == NULL){
		printf("Memoria no asignada\n");
		exit(-1);
	}

	for(int i = 0; i < bytes*1024*1024; i++){
		array[i] = i;
	}

	sleep(10);

	return 0;
}
