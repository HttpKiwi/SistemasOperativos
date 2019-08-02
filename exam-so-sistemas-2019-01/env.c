#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
	

int file_exist (char *filename)
{
	if( access(filename, F_OK ) != -1 )
		return 1;
	 else
		return 0;
}

int main(int argc, char *argv[]) {

	if(argc != 2){
		printf("Searching for null, usage ./env <file name>\n");
		exit(1);
	}

	char* file = argv[1];
	char* path = getenv("PATH");
	char* p = strtok(path,":");

	while(p != NULL){
	printf("%s\n",p);
		if(strcmp(p,file) == 0){
		        char *args[]={p,NULL};
			printf("%s\n",p);
			//execvp(args[0],args[1]);
		}
	}
	p = strtok(p,":");
	return 0;
}
