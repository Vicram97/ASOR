#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(){
    printf("Identificador de proceso: %i\n", getpid());
    printf("Identificador de proceso padre: %i\n", getppid());
    printf("Identificador de grupo de procesos: %i\n", getpgid(getpid()));
    printf("Identificador de sesion de proceso: %i\n", getsid(getpid()));

    struct rlimit limit;
    int rec = getrlimit(RLIMIT_NOFILE, &limit);
    if(rec == -1) printf("Error al recabvr info sobre limites del proceso.\n");
    else{
        printf("RLIMIT: %li\n", limit.rlim_max);
    }
    return 1;
}