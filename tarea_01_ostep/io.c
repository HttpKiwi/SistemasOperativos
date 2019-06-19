#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>

FILE *file;
char c;

bool exists(const char *fname)
{

    if ((file = fopen(fname, "r")))
    {
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {

    char *fname = argv[1];
    long pos;

    if(exists(fname)){
	printf("holi, existo");
	fseek(file,0,SEEK_END);
	for(pos = ftell(file)-1; pos >-1; pos--){ //Desde la ultima posicion hasta la primera
		fseek(file, pos, SEEK_SET); //Se ubica en la posicion pos
		c = fgetc(file); //Retorna el siguiente caracter y lo guarda
		printf("%c", c); //Se imprime
	
	}printf("\n");
    } else printf("el archivo no existe");
    fclose(file);
    return 0;
}

