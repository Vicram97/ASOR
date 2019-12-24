#include <unistd.h>
#include <stdio.h>
#include <sched.h>
#include <stdlib.h>

int main(int argc, char **argv){
    if(argc < 1) printf("Error, Introduce PID.\n");
    else{
        int pid = atoi(argv[0]);
        int plani = sched_getscheduler(pid);

        switch(plani){
            case SCHED_OTHER: printf("Scheduler: Other.\n");break;
            case SCHED_FIFO: printf("Scheduler: FIFO.\n");break;
            case SCHED_RR: printf("Scheduler: Round Robin.\n");break;
            default: printf("Política no encontrada.\n");break;
        }

        struct sched_param p;
        sched_getparam(pid,&p);
        printf("Prioridad: %i\n", p.sched_priority);

        int min = sched_get_priority_min(plani);
        int max = sched_get_priority_max(plani);
        printf("MAX: %i - MIN: %i \n", max, min);
    }
    return 1;
}