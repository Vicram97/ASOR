#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

#define PIPE_W 1
#define PIPE_R 0

int main(){
    int fd[2];
    int p_h[2];
    int h_p[2];

    pipe(p_h);
    pipe(h_p);

    switch(fork()){
        case -1: 
            printf("Error al hacer el fork.\n");
            break;
        case 0:
            printf("Entrando a hijo.\n");
            close(p_h[1]);
            close(h_p[0]);
            break;
        default:
            //Padre
            close(p_h[0]);
            close(h_p[1]);
            printf("Pre-Wait.\n");
            wait(NULL);
            close(fd[PIPE_W]);
            close(fd[PIPE_R]);
            printf("10 mensajes enviados.\n");
            break;
    }
}