#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_cond_t mutex1;
int cont = 0;

void hilo_1(){
    pthread_mutex_lock(&mutex);
    while(cont==0) pthread_cond_wait(&mutex1,&mutex);
    printf("JUJUJUJU\n");
    pthread_mutex_unlock(&mutex);
}


void hilo_2(){
    pthread_mutex_lock(&mutex);
    printf("JOJOJOJOJO\n");
    sleep(1);
    cont=1;
    pthread_cond_signal(&mutex1);
    pthread_mutex_unlock(&mutex);    
}

int main(){
    pthread_t th1,th2;
    pthread_mutex_init(&mutex,NULL);
    pthread_create(&th1,NULL,hilo_1,NULL);
    pthread_create(&th2,NULL,hilo_2,NULL);
    pthread_join(th1,NULL);
    pthread_join(th2,NULL);
    pthread_mutex_destroy(&mutex);
    return 0;
}