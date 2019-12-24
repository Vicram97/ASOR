#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

volatile int int_count = 0;
volatile int stp_count = 0;

void hdler(int senial){
    if(senial == SIGINT) int_count++;
    if(senial == SIGTSTP) stp_count++;
}

int main(){
    struct sigaction act;
    act.sa_handler = hdler;

    sigaction(SIGINT, NULL, &act);
    hdler(SIGINT);
    sigaction(SIGINT, &act, NULL);
    
    sigaction(SIGTSTP, NULL, &act);
    hdler(SIGTSTP);
    sigaction(SIGTSTP, &act, NULL);

    sigset_t set;
    sigemptyset(&set);

    while(int_count + stp_count < 10){
        sigsuspend(&set);
    }
    
    printf("SIGINT captures: %i \n", int_count);
    printf("SIGTSTP captures: %i \n", stp_count);

    return 0;
}