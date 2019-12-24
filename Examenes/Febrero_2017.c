#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){

    //Creamos las tuberias
    int t1 = mkfifo("home/victor/Documentos/PrSO/Examenes/tuberia1",0777);
    int t2 = mkfifo("home/victor/Documentos/PrSO/Examenes/tuberia2",0777);
    
    //Abrimos las tuberias
    int fd1 = open(t1,O_RDONLY);
    int fd2 = open(t2,O_WRONLY);
    return 0;
}