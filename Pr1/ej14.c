#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(){
    printf("Estamos en el año: %i\n", 1900 + *localtime(&time(NULL))->tm_year);
    return 1;
}