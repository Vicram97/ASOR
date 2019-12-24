#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PIPE_W 1
#define PIPE_R 0

int main(int argc, char**argv){
    if(argc < 2) printf("Error, faltan parámetros.\n");
    else{
        //Creamos tubería
        int fd[2];
        int pip = pipe(fd);
        //Hacemos fork
        int aux = fork();
        switch(aux){
        case -1:
            printf("Error al hacer el fork.\n");
            break;
        case 0:
            //Hijo
            printf("Hijo.\n");
            dup2(fd[PIPE_R],0);
            close(fd[PIPE_W]);
            close(fd[PIPE_R]);
            
            //printf("%s\n",argv[3]);
            //printf("%s\n",argv[4]);
            //execvp(argv[3],&argv[4]);
            execlp(argv[3], argv[3], argv[4], NULL);
            
            break;
        default:
            printf("PADRE ESPERANDO A SU HIJO.\n");
            wait(NULL);
            printf("PADRE YA SABE QUE EL HIJO HA ACABADO.\n");

            dup2(fd[PIPE_W],1);
            printf("HOLA.\n");
            close(fd[PIPE_W]);
            close(fd[PIPE_R]);

            printf("%s\n",argv[0]);
            printf("%s\n",argv[1]);
            printf("%s\n",argv[2]);
            execvp(argv[1],&argv[2]);
           
            //Padre
        }
    }
    return 0;
}