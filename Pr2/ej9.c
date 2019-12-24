#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/sysmacros.h>


int main(int argc, char **argv){

    if(argc < 2){
        printf("Error, faltan argumentos en los parámetros\n");
    }
    else{
        struct stat buff;
        int statint = stat(argv[1],&buff);
    
        if(statint == -1){
            printf("Error, no existe el directorio\n");
        }
        else{
            //Major y minor
            printf("Major: %i\n", major(buff.st_dev));
            printf("Minor: %i\n", minor(buff.st_dev));
            //Numero de inodo
            printf("Numero de inodo: %li\n", buff.st_ino);
            //Tipo de fichero
            printf("Tipo de fichero: %i\n", buff.st_mode);

            mode_t mode = buff.st_mode;
            if(S_ISLNK(mode)) printf("%s es un enlace simbolico.\n", argv[1]);
            else if (S_ISREG(mode)) printf("%s es un archivo ordinario.\n", argv[1]);
            else if (S_ISDIR(mode)) printf("%s es un directorio.\n", argv[1]);
        }
    }
    return 1;
}