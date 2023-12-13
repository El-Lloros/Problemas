#include <iostream>
using namespace std;
int CuentaUvas(int uvas[],int n,int pesoMax,int pesoParcial,int k,int u /*uva que nos vamos a comer*/){
    if(k==12){
        return 1;
    }
    int ret=0;
    //opcion 1 comer uva
    if(pesoParcial+uvas[u]<=pesoMax){
        ret+=CuentaUvas(uvas,n,pesoMax,pesoParcial+uvas[u],k+1,u+1);
    }

    //opcion 2 no comer uva    
    if(k+(n-u)>12){
        ret+=CuentaUvas(uvas,n,pesoMax,pesoParcial,k,u+1);
    }
    return ret;
}

bool casoDePrueba() {

    //leer caso de prueba
    int peso, n;
    cin >>peso;
    cin >> n;
    if (peso==0&&n==0)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ    
        int uvas[24];
        for(int i=0;i<n;i++){
            cin>>uvas[i];
        }
        int ret=CuentaUvas(uvas,n,peso,0,0,0);
        cout<<ret<<"\n";
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}