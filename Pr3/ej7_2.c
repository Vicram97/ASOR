#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char**argv){
    if(argc < 2 ) printf("Error, parametros insuficientes.\n");
    else{
        if(execvp(argv[1],argv + 1) == -1) printf("Error al ejecutar el comando.\n");
        else printf("El comando terminó de ejecutarse.\n");
    }
    return 0;
}