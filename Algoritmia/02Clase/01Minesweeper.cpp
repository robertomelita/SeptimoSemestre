#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
    int m;
    int n;
    cin>>m>>n; //Ingreso del M y el N
    char t[n];
    char entrada[n][m];
    for(int i=0; i < m;i++){
        cin>>t;
        for(int j=0; j < n; j++){
            entrada[j][i]=t[j];
        }
    }
    char salida[n][m];
    
    int cont;
    for(int i=0; i < m;i++){
        for(int j=0; j < n; j++){
            cont=0;
            if('*'==entrada[j][i]){
                salida[j][i]='*';
            }
            else{
                for(int h=0;h<3;h++){
                    for(int k=0;k<3;k++){
                        if(!(h+j-1<0) && !(k+i-1<0) && !(h+j-1>n) && !(k+i-1>m) && entrada[h+j-1][k+i-1]=='*'){
                            cont++;
                        }
                    }
                }
                cout<<cont<<" ";
                salida[j][i]=(char)(cont+48);
            }
        }
    }






    cout<<"IMPRIMIR\n";
    for(int i=0; i < m;i++){
        for(int j=0; j < n; j++){
            cout<<salida[j][i];
        }
        cout<<"\n";
    }
    return 0;
}