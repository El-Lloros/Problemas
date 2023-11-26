#include <iostream>
using namespace std;
#include <string>
long long polaca();

long long polaca(){
  
   // int numero = caracter - '0'; // Convierte el carácter a un entero
    char c;
    cin >> c;
    long long ic = c - '0';
    if (ic < 0 || ic > 9) {
        if(c=='+') ic = polaca() + polaca();
        else if(c=='-') ic = polaca() - polaca();
        else if(c=='*') ic = polaca() * polaca();
        else ic = polaca() / polaca();
        }
    return ic;
}


void casoDePrueba() {
    // TU CÓDIGO AQUÍ
    
    cout << polaca() <<'\n';


} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}