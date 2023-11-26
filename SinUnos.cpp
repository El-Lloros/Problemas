#include <iostream>
using namespace std;
long long cuantosin1(long long n, bool &sinunos);

long long cuantosin1(long long n, bool &sinunos){
    //caso base
    if(n==0){
        sinunos=true;
        return 0;
    }
    //caso recursivo
    long long aux= cuantosin1(n/10,sinunos);
    long long ret=0;
    aux=aux*9;
    if(sinunos){
        int d=n%10;
        aux+=d - (d>1);
    }
    sinunos=sinunos&&(n%10!=1);
    return aux;
}

bool casoDePrueba() {
    long long n;
    bool sinunos;
    //leer el inicio del caso de prueba (cin)
    cin>>n;

    if (!cin)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto
        long long aux;
        aux=cuantosin1(n,sinunos);
        if(sinunos){
            cout<<aux+1<<'\n';
        }else{
            cout<<aux<<'\n';
        }
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}