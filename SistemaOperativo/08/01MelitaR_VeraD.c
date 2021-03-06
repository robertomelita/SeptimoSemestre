#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t mutex;
int x=0;
void hilo_1(){
    pthread_mutex_lock(&mutex);
    x=x+1;
    printf("%i\n",x);
    pthread_mutex_unlock(&mutex);    
}


void hilo_2(){
    pthread_mutex_lock(&mutex);
    x=x-1;
    printf("%i\n",x);
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
    printf("%i\n",x);    
    return 0;
}