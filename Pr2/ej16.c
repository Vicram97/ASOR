#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv){
    if(argc < 2) printf ("Error, parametros insuficientes.\n");
    else{
        int fd = open(argv[1], O_RDWR, 00777);
        if(fd == -1) printf("Error al abrir el archivo.\n");
        else{
            struct flock flock;
        }
    }
   
    return 1;
}