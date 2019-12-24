#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){

    if(argc < 2) printf("Erros, parámetros insuficientes. \n");
    else{
        struct stat buff;
        int statint = stat(argv[1],&buff);
        if(statint == -1) printf("Error, el fichero no existe. \n");
        
        else{
            //printf("Todo correcto.\n");
            if(S_ISREG(buff.st_mode)){
                int hardlink = link("/home/victor/Documentos/PrSO/Pr2/fichero.c", "/home/victor/Documentos/PrSO/Pr2/fichero.hard");
                int simlink = symlink("/home/victor/Documentos/PrSO/Pr2/fichero.c", "/home/victor/Documentos/PrSO/Pr2/fichero.sym");
                //printf("Valor 1: %d\n", hardlink);
                if (hardlink == 0) printf("Enlace rigido correcto: %d.\n", hardlink);
                if (simlink == 0) printf("Enlace simbolico correcto: %d.\n", simlink);
            }
            else printf("No es un fichero regular.\n");
        }
    }
    
    return 1;
}