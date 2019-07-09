#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int guardar(char *fn, int n) {
  FILE *fp;
  fp = fopen(fn, "w");
  fprintf(fp,"%d",n);
  fclose(fp);
  return 0;
}

int leer(char *fn) {
  FILE *fp;
  int n;
  fp = fopen(fn,"r");
  fscanf(fp,"%d",&n);
  fclose(fp);
  return n;
}

int main(int argc, char** argv) {
	pid_t pid;
	pid = fork();
	int x = 0;

	if(pid == 0){
		x = leer("archivo");
		printf("Soy el hijo, el valor de x es %d\n",x);
		guardar("archivo",15);
	}
	else{
		x = leer("archivo");
		printf("Soy el padre, el valor de x es %d\n",x);
		guardar("archivo", 24);
	}

	return 0;
}
