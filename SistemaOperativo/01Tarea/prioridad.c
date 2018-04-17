#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
    struct sched_param sp;
    printf("hola %i\n", sched_getscheduler(getpid()));
    setpriority(0,0,10);
    sp.sched_priority= sched_get_priority_min(SCHED_FIFO);
    sched_setscheduler(0,SCHED_FIFO,&sp);
    while(1);
    return 0;
}