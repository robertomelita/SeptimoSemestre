#include<signal.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
void tratar_violacion(void){
	printf("está violando el core\n");
	exit(0);
}
int main(int argc, char const *argv[])
{
	
	struct sigaction act;
	act.sa_handler=tratar_violacion;
	act.sa_flags=0;
	sigaction(SIGSEGV,&act,NULL);
	int *p = NULL;
	*p = 1;
	
}