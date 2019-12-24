#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char**argv){
    if(argc < 2 ) printf("Error, faltan parametros.\n");
    else{
        switch(fork()){
            case -1:
                printf("Error al realizar el fork.\n");
                break;
            case 0:
                //DEMONIO
                //Crear nueva sesión
                setsid();
                //Cambiar el directorio de trabajo a tmp
                chdir("/tmp/");
                //Mostrar los ID de proceso
                printf("Identificador de proceso: %i\n", getpid());
                printf("Identificador de proceso padre: %i\n", getppid());
                printf("Identificador de grupo de proceso: %i\n", getpgid(getpid()));
                printf("Identificador de sesión de proceso: %i\n", getsid(getpid()));
                //Ejecucion del comando pasado por argumento
                execl("/bin/sh", "sh", "-c", argv[1], (char *) 0);
                break;
            default:
                break;
        }
    }
    return 0;
}