#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if(argc < 2) printf("Error, parámetros insuficientes. \n");
    else{
        struct stat buff;
        int statint = stat(argv[1],&buff);
        if(statint == -1) printf("Error, el fichero no es correcto.\n");
        else{
            //Comenzamos el ejercicio
            int fd = open(argv[1], O_CREAT | O_RDWR, 00777);
            if(fd == -1) printf("Error al abrir el fichero.\n");
            else{
                int aux = dup2(fd, 1);
                if(aux == -1) printf("Error al ducplicar el fichero.\n");
                else{
                    dup2(aux,fd);
                }
            }
        }
    }
    return 1;
}