Juan Pablo Dominguez - 1723226
Angélica María Muñoz - 1725435

# TAREA I S.S.O.O (OSTEP)

## *[mem.c](mem.c)

Con el fin de solucionar el problema de dos accesos a la misma dirección de 
memoria, lo que se hizo, no fue modificar el código, sino, en la compilación y
ejecución. Se compiló el programa usando la siguiente línea de código: 

```gcc mem.c -o mem -lpthread```

Y se ejecuta, así:

```./mem (valor) & ./mem (valorII) ```

## *[threads.c](threads.c)

Usando el código provisionado por el docente de puertas, este se implementó 
de manera que, no se permite que ambos hilos accedan a la misma dirección de 
memoria al tiempo.

Se compila de la siguiente manera:
 
```gcc threads.c -o threads -lpthread ```

## *[io.c](io.c)

Debido a que el código planteado en io.c era muy restringido por el número de 
bits a leer, lo que se hizo fue realizar el programa nuevamente. En resumen, 
el algoritmo comienza verificando la existencia del archivo y en base a esa 
información, se procedía a ubicarse al final del archivo leído, con el fin de 
ir leyendo caracter a caracter de final a principio e imprimir eso en consola.

Código de compilación:

```gcc io.c -o io```

Código de ejecución:

```./io (nombre de archivo)```
