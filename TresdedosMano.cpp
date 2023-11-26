#include <iostream>
using namespace std;
int conversor(int n);

int conversor(int n){
    //caso base
    if (n<6){
        cout<<n;
        return 0;
    }
    //caso recursivo
    conversor(n/6);
    cout<<n%6;
    return 0;
}


void casoDePrueba() {

    // TU CÓDIGO AQUÍ
    int n;
    cin>>n;
    conversor(n);
    cout<<'\n';

} // casoDePrueba


int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}
  
