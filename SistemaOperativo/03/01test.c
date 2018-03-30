#include <stdio.h>
#include <stdlib.h>

int main(){
    int pid = fork();
    if(pid==0){
        printf("Mi id es %i,%i\n",getpid(),getppid());
        //exit();
    }
    else{
        printf("Mi id es %i,%i\n",getpid(),getppid());
    }
}