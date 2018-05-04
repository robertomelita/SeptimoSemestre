#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int x = 0;

int main(){
    sem_t mutex;
    sem_init(&mutex,0,1);
    int pid=fork();
    if(pid==0){
        sem_wait(&mutex);
        x=x-1;
        printf("%i\n",x);
        
        sem_post(&mutex);
    }else{
        sem_wait(&mutex);
        x=x+1;
        printf("%i\n",x);
        sem_post(&mutex);
    }
    printf("%i\n",x);
    return 0;
}