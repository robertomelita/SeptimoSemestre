#include <iostream>
#include <vector>
int busqueda(int *datos,int num,int inicio,int final);
int main(int argc, char const *argv[])
{
	int* datos=(int*)malloc(sizeof(int)*16);
	for(int i=0;i<16;i++){
		datos[i]=i;
	}
	int a=atoi(argv[1]);
	int tul=busqueda(datos,a,0,15);
	printf("%i\n", tul);
	
}

int busqueda(int *datos,int num,int inicio, int final){
	int aux;
	aux=(final+inicio)/2;
	if(datos[aux]==num){
		return aux;
	}
	else{

	if(datos[aux]>num){
		busqueda(datos,num,inicio,aux);
	}
	else{
		busqueda(datos,num,aux,final);
	}
}
}
