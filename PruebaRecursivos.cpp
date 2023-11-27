#include <iostream>
using namespace std;
long long divertdo(long long n, bool& norepetido, int &digito);
//Complejidad: a= 1 (recursion simple por division) b=10 k=0 => O(log n) siendo n el número que da el usuario.

long long divertdo(long long n, bool& norepetido, int& digito) {
    //caso base
  //caso base
    if (n < 10) {
        norepetido = true;
        digito = n;
        return n;
    }
    //caso recursivo
    long long aux = divertdo(n / 10, norepetido, digito);
    aux = aux * 9;
    aux++;
    if (norepetido) {
        int d = n % 10;
        aux += d - (d > digito);
    }

    norepetido = norepetido && (n % 10 != digito);
    digito = n % 10;

    return aux;
}

bool casoDePrueba() {
    long long n;
    bool norepetido;
    int digito ;
    
    //leer el inicio del caso de prueba (cin)
    cin >> n;

    if (n == -1)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto
        long long aux;
        aux = divertdo(n, norepetido,digito);
      
            cout << aux << '\n';
        
       
    }
    return true;

} // casoDePrueba

int main() {

    while (casoDePrueba()) {
    }

    return 0;
}