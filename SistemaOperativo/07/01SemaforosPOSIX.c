#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>

int main(){
    sem_t mutex;
    sem_init(&mutex,0,1);
    int pid=fork();
    if(pid==0){
        sem_wait(&mutex);
        printf("Seccion critica 1\n");
        sem_post(&mutex);
    }else{
        sem_wait(&mutex);
        printf("Seccion critica 2\n");
        sem_post(&mutex);
    }
    return 0;
}