#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

int main(int argc, char**argv){
    if(argc < 2) printf("Error, parámetros insuficientes.\n");
    else{
        pid_t aux = fork();

        switch(aux){
            case -1: 
                printf("Error, al realizar el fork para crear el proceso hijo.\n");
                break;
            case 0:
                printf("Proceso Hijo.\n");
                //Todo demonio tiene su propia sesión
                pid_t setsid();
                execvp(argv[1], argv + 1);
                break;
            default:
                
                printf("Proceso Padre.\n");
                break;
        }
    }
    return 0;
}