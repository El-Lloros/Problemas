#include <iostream>
using namespace std;

long long codigo(long long n,int minDerecha,int &MaxIzq,int &NumDigitos){
    //caso base
    if(n<10){
         NumDigitos=1;
         MaxIzq=n;
         return(3*n+minDerecha);
    }
    //caso recursivo
    long long ret;
    int d=n%10;
    ret=codigo(n/10,min(d,minDerecha),MaxIzq,NumDigitos);
    if(NumDigitos%2!=0){
        ret+=2*d+MaxIzq;
    }else{
        ret+=3*d+minDerecha;
    }
    NumDigitos++;
    MaxIzq=max(MaxIzq,d);
    return ret;
}
void casoDePrueba() {
    /*
    Cada dígito en una posición impar se multiplica por 3 y se le suma el menor dígito a su derecha.
    Cada dígito en una posición par se multiplica por 2 y se le suma el mayor dígito a su izquierda.
    */
    // TU CÓDIGO AQUÍ
    long long n;
    int MaxIzq;
    int NumDigitos;
    cin>>n;
    cout<<codigo(n,10,MaxIzq,NumDigitos)<<'\n';

} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}