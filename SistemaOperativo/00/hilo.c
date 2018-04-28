#include <stdio.h>
#include <sched.h>
#include <pthread.h>

int main(int argc, char const *argv[])
{
	struct sched_param param;
	sched_getparam(0,&param);
	printf("%i\n",getpid());
	param.sched_priority=16;
	sched_setparam(0,&param);
	sched_getparam(0,&param);
	printf("%i\n",param.sched_priority);
	while(1);
}
