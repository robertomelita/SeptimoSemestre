#include <stdio.h>
#include <stdlib.h>

int main(){
    //printf("retorno %i\n",system("./prog"));
    printf("%i jeujeu\n",execv("./prog",NULL));
    printf("hele\n");
}