#include <iostream>
using namespace std;
long long enemigos[300000];

bool esPosible(long long enemigos[],int luchadores,int n,long long m){
    int acum=0;
    int i=0;
    while(i<n&&acum<=luchadores){
        acum+=enemigos[i]/m;
        if(enemigos[i]%m>0)
            acum++;
        i++;
    }
    return acum<=luchadores&&i>=n;
}
long long recursivo(long long enemigos[],int luchadores,int n,long long inicio,long long fin){
    //caso base
    if(inicio==fin){
        return inicio;
    }
    long long m=(inicio+fin)/2;
    if(esPosible(enemigos,luchadores,n,m)){
        return recursivo(enemigos,luchadores,n,inicio,m);
    }else{
        return recursivo(enemigos,luchadores,n,m+1,fin);
    }
}
long long resuelve(long long enemigos[],int luchadores,int n){
    long long maximo=0;
    for(int i=0;i<n;i++){
            maximo=max(maximo,enemigos[i]);
        }
    return recursivo(enemigos,luchadores,n,1,maximo);
    long long a=1;
    long long b=maximo;
    long long m;
    while(a<b){
        m=(a+b)/2;
        if(esPosible(enemigos,luchadores,n,m)){
            b=m;
        }else{
            a=m+1;
        }

    }
    return a;
} 
bool casoDePrueba() {
    int luchadores;
    int n;
    cin>>luchadores>>n;
    //leer el inicio del caso de prueba (cin)
    if (!cin)
        return false;
    else {
        for(int i=0;i<n;i++){
            cin>>enemigos[i];
        }
        cout<<resuelve(enemigos,luchadores,n)<<'\n';
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}