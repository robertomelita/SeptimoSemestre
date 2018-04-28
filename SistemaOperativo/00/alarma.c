#include<signal.h>
#include<stdio.h>
void tratar_alarma(void){
	printf("activada\n");
}
int main(int argc, char const *argv[])
{
	struct sigaction act;
	act.sa_handler=tratar_alarma;
	act.sa_flags=0;
	sigaction(SIGALRM,&act,NULL);
	act.sa_handler=SIG_IGN;
	sigaction(SIGINT,&act,NULL);
	for(;;){
		alarm(3);
		pause();
	}
}