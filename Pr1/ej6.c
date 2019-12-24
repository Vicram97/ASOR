#include <unistd.h>
#include <stdio.h>

int main(){
    printf("Longitud máxima de argumentos: %li\n", sysconf(_SC_ARG_MAX));
    return 1;
}