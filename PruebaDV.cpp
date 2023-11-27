#include <iostream>
using namespace std;
long long divertdo(long long n, bool& norepetido, int &digito);
long long entretenido(long long n);
long long entretenido(long long n){
    long long posicion;
    bool norepetido;
    int digito ;
    long long numero=n;
    posicion=divertdo(n+1, norepetido,digito);
    while(posicion<n){
        numero=numero*2;
        posicion=divertdo(numero+1, norepetido,digito);
    }
    long long a= 0;
    long long b=numero;
    while(a<b){
        long long m=(a+b)/2;
        posicion=divertdo(m+1, norepetido,digito);
        if(posicion>=n){
            b=m;
            

        }else{
            a=m+1;

        }
        
    }
    
    return b;
}
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
        aux=entretenido(n);
        
      
        cout << aux << '\n';
        
       
    }
    return true;

} // casoDePrueba

int main() {

    while (casoDePrueba()) {
    }

    return 0;
}