#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    char * archivo = "hello.txt";
    int filesize=64*sizeof(int);
//    ftruncate(archivo,filesize);

    int fd=open(archivo,O_RDWR);
    int *mapa=(int*) mmap(NULL,filesize,PROT_READ | PROT_WRITE,MAP_SHARED,fd, 0);
    for(int i=0;i<64;i++){
        mapa[i]=i;
    }
    
    munmap(mapa,filesize);
    close(fd);    
    return 0;
}