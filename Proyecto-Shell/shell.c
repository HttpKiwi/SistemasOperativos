#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void parseSpc(char* lineacmd, char** parseada){

	int maxInst = 100;

	for(int i = 0; i < 2; i++){

		parseada[i] = strsep(&lineacmd, " ");
		printf("%s\n", parseada[i]);
		if(parseada[i] == NULL){ break;}
		if(strlen(parseada[i]) == 0){ 
			i--;
			maxInst--;
			printf("sji\n");
		}
	}printf("jejejej\n");

}

void echo(char** parsed){

	

}

void userMan(void){

	printf("**************Bienvenido al manual de usuario***************\n");
	printf("1. cd <directorio> :cambia al directorio especificado, en caso de no ingresar un parametro, \n");
	printf("se muestra el directorio actual.\n");
	printf("2. clr :limpia la consola\n");
	printf("3. dir <directorio> :muestra los contenidos de la carpeta\n");
	printf("4. environ :lista los strings del ambiente\n");
	printf("5. echo <comentario> :muestra el comentario seguido de una linea nueva\n");
	printf("6. pause :pausa la operacion del shell hasta que se presione 'enter'\n");
	printf("7. quit :termina la ejecucion del shell\n");

}

void pauseCmd(void){

}


int manejaCmd(char** parsed){

	int selec = 0, noCmd = 8;
	char* listaCmd[noCmd];

	listaCmd[0] = "cd";
	listaCmd[1] = "dir";
	listaCmd[2] = "clr";
	listaCmd[3] = "environ";
	listaCmd[4] = "echo";
	listaCmd[5] = "help";
	listaCmd[6] = "pause";
	listaCmd[7] = "quit";

	for(int i = 0; i < noCmd; i++){
		if(strcmp(listaCmd[i],parsed[0]) == 0){
			selec = i;
			break;
		}
	}

	switch(selec){

	case 0: printf("\033[H\033[J");
		break;

	case 1: chdir(parsed[1]);
		break;

	case 2: //dir
		break;

	case 3: //environ
		break;

	case 4: echo(parsed);
		break;

	case 5: userMan();
		break;

	case 6: pauseCmd();
		break;

	case 7: printf("Nos vemos\n");
		sleep(3);
		exit(0);

	default: return 0;

	}
	
	return 1;
}

void cmdLoop(void){

	printf("\033[H\033[J");
	printf("Bienvenido a mi Shell\n");

	char lineacmd[101];
	char *cmdParsed[100];
	char dir[1001];

	while(1){

		printf("%s:%s$",getenv("USER"),getcwd(dir,1000));

		if(!fgets(lineacmd,100,stdin)) break;

printf("1\n");

		parseSpc(lineacmd, cmdParsed);
printf("2\n");
		if(manejaCmd(cmdParsed));


	}

}






int main(){

	cmdLoop();
	return 0;

}
