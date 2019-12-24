#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(){
    const char *pathname = "/home/victor/Documentos/PrSO/Pr2/ej5.txt";
    
    open(pathname,O_CREAT, 0645);
    
    printf("Hecho\n");

    return 1;
}