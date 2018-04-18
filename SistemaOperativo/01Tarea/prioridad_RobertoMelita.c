/*Roberto Melita
  Javier Rojas*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main(){
    int p = 14;
    int prioridad = setpriority(0,0,p);
    if(prioridad == 0)
        printf("Sea ha cambiado la prioridad a %i\n",p);
    else
        printf("Ocurrio un error\n");
    while(1);
    return 0;
}