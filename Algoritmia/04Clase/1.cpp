#include <iostream>
#include <vector>

int busqueda(int *datos,int num);
int main(int argc, char const *argv[])
{
	
	//std::vector<int> v = {7, 5, 16, 8};
	int* datos=(int*)malloc(sizeof(int)*16);
	for(int i=0;i<16;i++){
		datos[i]=i;
	}
	int a=atoi(argv[1]);
	int tul=busqueda(datos,a);
	printf("%i\n", tul);
}

int busqueda(int *datos,int num){

	int encontrado=0;
	int inicio=0;
	int final=15;
	int aux;
	
	while(encontrado==0){

		aux=((final+inicio)/2);
		printf("%i\n",aux);
		if(datos[aux]==num){
			encontrado=1;
		}
		if(datos[aux]>num){

			final=aux;
		}
		if(datos[aux]<=num){

			inicio=aux;
		}
	}
	return aux;
}