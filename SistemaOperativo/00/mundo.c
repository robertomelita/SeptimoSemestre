#include <stdlib.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	printf("soy el proceso nuevo\n");
	int a=atoi(argv[1]);
	printf("%i\n",a );
	while(1);
	return 0;
}