#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "common.h"
#include "common_threads.h"
#include "mycommon.h"

volatile double v; 
puerta door;

void *worker(void *arg) {

    int y = 350;
    int z = 25;

    cerrar_puerta(door);
    sleep(2);
    v = (double)z/y;
    abrir_puerta(door);
    return NULL;
}

void *worker2(void *arg) {

    int x = 1250;
    cerrar_puerta(door);
    v = v*x;
    abrir_puerta(door);
    return NULL;
}

int main(int argc, char *argv[]) {

    crear_puerta(door);
    pthread_t p1, p2;
    Pthread_create(&p1, NULL, worker, NULL); 
    Pthread_create(&p2, NULL, worker2, NULL);
    Pthread_join(p1, NULL);
    Pthread_join(p2, NULL);
    destruir_puerta(door);

    printf("El resultado de realizar x*(z/y) es igual a: %f\n",v);  

    return 0;
}
