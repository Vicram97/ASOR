#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char**argv){

    if(argc < 2) printf("Error, faltan parámetros: recuerda que la ruta se pasa por parámetro.\n");

    else{
        //Leemos el directorio
        DIR *directorio = opendir(argv[1]);
        //Extraemos la información del primer archivo
        struct dirent *lectura = readdir(directorio);
        //Informacion del archivo
        struct stat *info;
        
        
        while(lectura != NULL){
            printf("Nombre del archivo: %s\n", lectura->d_name);

            //stat(strcat(argv[1], lectura->d_name), info);
            if(stat(strcat(argv[1], lectura->d_name), info) ==-1) printf("Fallo al ejecutar stat.\n");
            else{
                printf("UID del usuario propietario: %i.\n",info->st_uid);
                printf("UID del usuario propietario (2): %i.\n",info->st_uid);
                printf("Numero de i-nodo: %li.\n", lectura->d_ino);
                printf("Numero de i-nodo (2): %li.\n", info->st_ino);
                printf("Tamaño del archivo: %d\n", lectura->d_reclen);
                printf("Tamaño del archivo (2): %li\n", info->st_size);
            }

            printf("\n"); //Salto de línea para ver mejor el resultado por pantalla
            lectura  = readdir(directorio); //Leemos el siguiente archivo
        }
    }
    return 0;
}