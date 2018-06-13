#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    char * archivo = "hello.txt";
    int filesize=64*sizeof(int);

    int fd=open(archivo,O_RDONLY);
    int *buffer = (int*) mmap(NULL, filesize, PROT_READ, MAP_SHARED,fd, 0);
    for(int i = 0; i<64;i++){
        printf("%i\n",buffer[i]);
    }
    munmap(buffer,filesize);
    close(fd);    
    return 0;
}