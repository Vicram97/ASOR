#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char**argv){
    if(argc < 3 ) printf("Error, faltan parámetros.\n");
    else{
        switch(fork()){
            case -1:
                printf("Error al hacer el fork.\n");
                break;
            case 0:
                printf("PID del hijo: %i\n", getpid());
                system(argv[1]);
                //if(execl(argv[1],argv[3],NULL) == -1) printf("Error al ejecutar el primer comando.\n");
                break;
            default:
                wait(NULL);
                printf("PID del Padre: %i\n", getpid());
                system(argv[2]);
                //if(execl(argv[2],argv[4],NULL) == -1) printf("Error al ejecutar el segundo comando.\n");
                break;
        }
    }
    return 0;
}