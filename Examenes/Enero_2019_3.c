#include <stdio.h>
#include <signal.h>
#include <unistd.h>

volatile int num_SIGINT = 0;
volatile int num_SIGTSTP = 0;

void handler(int signal){ //Manejador
    if(signal == SIGINT) num_SIGINT++;
    else if(signal == SIGTSTP) num_SIGTSTP++;
}

int main(){
    printf("Numero de PID: %d\n",getpid());
    struct sigaction act;

    //Modificación del tratamiento de señal SIGINT
    sigaction(SIGINT,NULL,&act);
    act.sa_handler = handler;
    sigaction(SIGINT,&act,NULL);

    //Modificación del tratamiento de señal SIGTSTP
    sigaction(SIGTSTP,NULL,&act);
    act.sa_handler = handler;
    sigaction(SIGTSTP,&act,NULL);

    sigset_t set;
    sigemptyset(&set);

    //Mientras no se reciban las 10 señales, estamos en stand-by
    while(num_SIGINT + num_SIGTSTP < 10){
        sigsuspend(&set);
    }

    printf("Número de señales SIGINT: %d\n",num_SIGINT);
    printf("Número de señales SIGTSTP: %d\n",num_SIGTSTP);
    return 0;
}