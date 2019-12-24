#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>


int main(int argc, char** argv){
    if(argc < 2) printf("Error, se debe especificar la ruta del directorio en los argumentos del programa.\n");
    else{
        DIR *directorio = opendir(argv[1]);
        if(directorio == NULL) printf("Error, el directorio indicado es incorrecto.\n");
        else{
            //printf("TODO CORRECTO.\n");
            struct dirent *lectura;
            lectura = readdir(directorio);

            struct stat buff;
            int maxTamaño = 0;

            while(lectura != NULL){
              int numbuff = stat(ALGO,&buff);  
              if(numbuff == -1) printf("Error, no se puede analizar este archivo.\n");
              else{
                  if(S_ISREG(buff.st_mode)){
                      totalsize = totalsize + ((buff.st_blksize/8)*buff.st_blocks);
                      printf();
                  }
                  else if(S_ISDIR(buff.st_mode)){
                      printf("[/] %S \n", buff->d_name);
                  }
                  else if(S_ISLNK(buff.st_mode)){
                      printf("Simbolico");
                  }
                  else if(S_IXUSR(buff.st_mode)){
                      printf("Ejecutable");
                  }
              }
              lectura = readdir(directorio);
            }
            closedir(directorio);
        }
    }
    return 1;
}