#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

void printAtributos(){
    printf("Identificador de proceso: %i\n", getpid());
    printf("Identificador de proceso padre: %i\n", getppid());
    printf("Identificador de grupo de procesos: %i\n", getpgid(getpid()));
    printf("Identificador de sesion de proceso: %i\n", getsid(getpid()));

    struct rlimit limit;
    int rec = getrlimit(RLIMIT_NOFILE, &limit);
    if(rec == -1) printf("Error al recavar info sobre limites del proceso.\n");
    else printf("RLIMIT: %li\n", limit.rlim_max);
}

int main(){

    pid_t pid = fork();

    switch(pid){
        case -1: 
            perror("fork"); 
            exit(-1);
        break;

        case 0:
        sleep(1000);
        setsid();
        int aux = chdir("/tmp");
        printf("Hijo: %i Padre : %i \n", getpid(),getppid());
        printAtributos();
        
        break;

        default:
            printf("PADRE.\n");
            printAtributos();
        break;
    }
    return 1;
}