#include <iostream>
using namespace std;
int tiempos[100000];

bool esPosible(int tiempos[],int n,int p,int m){
    int paradas=0;
    int i=0;
    int suma=0;
    while(paradas<=p&&i<n){
        if(suma+tiempos[i]<=m){
            suma+=tiempos[i];
        }else{
            paradas++;
            suma=tiempos[i];
        }
        i++;
    }
    return (paradas<=p&&i>=n);
}
int abueloRecursivo(int tiempos[],int n,int p,int inicio,int final){
    //caso base
        if(inicio==final){
            return inicio;
        }
    //caso recursivo
        int m=(inicio+final)/2;
        if(esPosible(tiempos,n,p,m)){
            final=m;
        }else{
            inicio=m+1;
        }
        return abueloRecursivo(tiempos,n,p,inicio,final);
}

int abuelo(int tiempos[],int n,int p){
    int suma=0;
    int maximo=0;

    for(int i=0;i<n;i++){
        suma+=tiempos[i];
        maximo=max(maximo,tiempos[i]);
    }
    int a=maximo;
    int b=suma;
    int m;
    while(a<b){
        m=(a+b)/2;
        if(esPosible(tiempos,n,p,m)){
            b=m;
        }else{
            a=m+1;
        }
    }
    return a;
}
bool casoDePrueba() {
    int n;
    int p;
    cin>>n;
    cin>>p;

    //leer el inicio del caso de prueba (cin)
    if (!cin)
        return false;
    else {
        int suma=0;
        int maximo=0;
        for(int i=0;i<n;i++){
            cin>>tiempos[i];
            suma+=tiempos[i];
            maximo=max(maximo,tiempos[i]);
        }

        cout<<abueloRecursivo(tiempos,n,p,maximo,suma)<<'\n';
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}