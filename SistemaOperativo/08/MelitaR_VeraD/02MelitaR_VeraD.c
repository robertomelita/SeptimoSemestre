#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <time.h>


int main(){
    sem_t mutex, sem_lec;
    key_t key,keyL;
    int id, idL, pid, *a, *nlec;
    if((key = ftok("hola.txt",1))==-1 || (keyL = ftok("hele.txt",1)==-1)){
        printf("Error ftok\n");
        exit(1);
    }
    if((id = shmget(key,sizeof(int),IPC_CREAT|0777))==-1 || (idL = shmget(keyL,sizeof(int),IPC_CREAT|0777))==-1){
        printf("Error shmget\n");
        exit(1);
    }
    a = shmat(id,NULL,0);
    *a=0;
    nlec = shmat(idL,NULL,0);
    sem_init(&mutex,0,1);

    pid=fork();
    if(pid==0){
        for(int i=0;i<40;i++){    
            pid=fork();
            if(pid==0) break;
        }       
        if(pid==0){
            sem_wait(&mutex);
            (*a)++;
            printf("Escribiendo %i\n",*a);
            sem_post(&mutex);
        }
    }else{
        for(int i=0;i<40;i++){    
            pid=fork();
            if(pid==0) break;
        }
        if(pid==0){
            sem_wait(&sem_lec);
            *nlec++;
            if(*nlec ==1) sem_wait(&mutex);
            sem_post(&sem_lec);

            printf("Leyendo %i\n",(*a));

            sem_wait(&sem_lec);
            *nlec--;
            if(*nlec==0) sem_post(&mutex);
            sem_post(&sem_lec);
        }
    }
    return 0;
}

/*
lector(){
    sem_wait(&sem_lec);
    n_lectores = n_lectores+1;
    if(n_lectores ==1) sem_wait(&mutex);
    sem_post(&sem_lec);

    printf("Leyendo %i\n",(*a));

    sem_wait(&sem_lec);
    n_lectores=n_lectores-1;
    if(n_lectores==0) sem_post(&mutex);
    sem_post(&sem_lec);
}
escritor(){
    sem_wait(&mutex);
    (*a)=rand()%5;
    printf("Escribiendo %i\n",*a);
    sem_post(&mutex);
}*/