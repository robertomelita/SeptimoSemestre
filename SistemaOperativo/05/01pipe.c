#include <stdio.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    int f[2],g[2],pid;
    pipe(f);
    pipe(g);
    
    pid = fork();
    if(pid==0){
        char d;
        read(f[0],&d,1);
        printf("HIJO: me llego una %c\n",d);
        printf("HIJO: Lo cambiare por una H\n");
        d = 'H';
        write(g[1],&d,1);
    }
    else{
        char c = 'G';
        printf("PADRE: mandare una %c\n",c);
        write(f[1],&c,1);
        read(g[0],&c,1);
        printf("PADRE: me devolvieron una %c\n",c);
    }
}