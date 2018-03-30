#include <stdio.h>

int main(){
    int pid;
/*    pid = fork();
    if(pid==0){
        printf("soy el hijo\n");
        while(1);
    }else{
        printf("soy el padre %i\n",pid);
        while(1);
    }*/
    for(int i=0;i<3;i++){
        pid = fork();
        if(pid==0) break;
        printf("pid: %i\n",pid);        
    }
}