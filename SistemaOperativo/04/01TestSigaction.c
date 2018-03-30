#include <signal.h>
#include <stdio.h>
#include <sys/mman.h>

void tratar_alarma(void){
    printf("hubo un segentation fault\n");
    exit(1);
}

int main(){
    struct sigaction act;
    act.sa_handler = tratar_alarma;
    act.sa_flags = 0;
    sigaction(SIGSEGV, &act, NULL);

    raise(11);
    //int x = 4/2;
    //int protection = mprotect(&x,sizeof(&x),PROT_NONE);
    //x=0;
    //printf("El valor es: %i      %i\n",x, protection);
}