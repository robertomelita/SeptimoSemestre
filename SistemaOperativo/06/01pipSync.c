#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int fildes[2];
    char c;

    pipe(fildes);
    write(fildes[1],&c,1);
    if(fork()==0){
        for(;;){
            read(fildes[0],&c,1);
            //SECCION CRITICA
            printf("HOLA soy el hijo\n");
            write(fildes[1],&c,1);
        }
    }else{
        for(;;){
            read(fildes[0],&c,1);
            //SECCION CRITICA
            printf("HELE see el pedre\n");
            write(fildes[1],&c,1);
        }
    }
}