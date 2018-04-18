#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

int main(){
    mqd_t mutex;
    struct mq_attr attr;

    attr.mq_maxmsg = 1;
    attr.mq_msgsize = sizeof(char);

    mutex = mq_open("/MUTEX",O_CREAT|O_RDWR, 0777,&attr);
    perror("ERROR");
    if(fork()==0){

        char c1;
        mq_receive(mutex,&c1,1,0);
        printf("%c\n",c1);
    }else{
        char c2 = 'D';
        mq_send(mutex,&c2,1,0);
    }
}