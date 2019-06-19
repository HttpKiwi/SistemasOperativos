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
	pos = ftell(file)-1;
	while(pos >-1){ 
		fseek(file, pos, SEEK_SET);
		c = fgetc(file); 
		printf("%c", c);
		pos--;
	
	}printf("\n");
    } else printf("el archivo no existe");
    fclose(file);
    return 0;
}

