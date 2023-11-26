#include <iostream>
using namespace std;
pair <bool,long long> Poli(long long n);

pair <bool,long long> Poli(long long n){
    
    //Caso Base
    if(n<10){
        
        return pair <bool,long long> (true,1);
    }
    //Caso Recursivo
    pair <bool,long long> aux=Poli(n/10);
    aux.second++;
    aux.first=aux.first&&(n%aux.second==0);
    return aux;
}
bool casoDePrueba() {

    //leer el inicio del caso de prueba (cin)
    long long n;
    cin>>n;
    if (!cin)
        return false;
    else {
        bool sol;
        sol=Poli(n).first;
        if(sol)
            cout<<"POLIDIVISIBLE"<<'\n';
        else
            cout<<"NO POLIDIVISIBLE"<<'\n';
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}