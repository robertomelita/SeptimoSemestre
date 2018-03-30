#include <iostream>
#include <vector>

int n = 17;

int busquedaBinaria(int* datos,int numero);
int busquedaRecursiva(int *datos, int numero, int inicio, int fin);

int main(int argc, char **argv){
    int a = atoi(argv[1]);
    int* datos = (int*)malloc(sizeof(int)*n);
    for(int i = 0; i<n; i++){
        datos[i]=i;
    }
    int posicion = busquedaRecursiva(datos,a,0,17);
    printf("La posicion del numero buscado es : %i\n",posicion);
    return 0;
}
int busquedaBinaria(int* datos,int numero){
    int inicio = 0;
    int fin = n;
    int mitad;
    while(fin-inicio>1){
        mitad = (fin+inicio)/2;
        if(numero>=datos[mitad]){
            inicio = mitad;
        }else {
            fin = mitad;
        }
    }
    return mitad;
}

int busquedaRecursiva(int *datos, int numero, int inicio, int fin){
    int mitad = (inicio + fin)/2;
    if(numero==datos[mitad]){
        return mitad;
    }else if(numero<datos[mitad]) {
        busquedaRecursiva(datos,numero,inicio,mitad);
    }else if(numero>datos[mitad]){
        busquedaRecursiva(datos,numero,mitad,fin);
    }
}