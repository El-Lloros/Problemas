#include <iostream>
#include<algorithm>
using namespace std;
bool resuelvecaso();
int cuentaescalones(long long a,long long b,int tamx,int tamy,int &Salida1,int &Salida2);
int cuentaescalones(long long a,long long b,int tamx,int tamy,int &Salida1,int &Salida2){
    long long  x = (a) % tamx;
    long long  y = (a) / tamx;
    int inicio;
    cout << "? " << x << " " << y << '\n';
    cin>>inicio;
    Salida1=inicio;
    x = (b) % tamx;
    y = (b) / tamx;
    int final;   
    cout << "? " << x << " " << y << '\n';
    cin>>final;
    Salida2=final;
    if(inicio==final){
        return 1;
    }
    long long m=(a+b)/2;
    int izquierda,derecha,Mitad,Siguiente,Dummy;
    izquierda=cuentaescalones(a,m,tamx,tamy,Dummy,Mitad);
    derecha=cuentaescalones(m+1,b,tamx,tamy,Siguiente,Dummy);
      // Contar incrementos que cruzan la mitad del array
    int cruzandoMitad = 0;
    if (Mitad==Siguiente) {
        cruzandoMitad=-1;
    }

    return izquierda + derecha + cruzandoMitad;

}
bool resuelvecaso(){

    long long tamx,tamy;
    long long a,b;
    long long ret;
    long long inicio,final,posibles;
    int Salida1,Salida2;
    ret=1;
    cin>>tamx>>tamy;
    a=0;
    b=(tamx*tamy)-1;
    if(tamx==0&&tamy==0){
        return false;
    }
    ret=cuentaescalones(a,b,tamx,tamy,Salida1,Salida2);
    cout<<"Respuesta: "<<ret<<'\n';
    return true;
}


int main(){
    while(resuelvecaso()){
        ;
    }

    return 0;
}
/*
#include <iostream>

using namespace std;

int contarIncrementos(const int arr[], int inicio, int fin) {
    // Caso base: si el subarray tiene tamaño 1, no hay incrementos
    if (inicio == fin) {
        return 0;
    }

    int mitad = (inicio + fin) / 2;

    // Contar incrementos en la mitad izquierda y derecha del array
    int izquierda = contarIncrementos(arr, inicio, mitad);
    int derecha = contarIncrementos(arr, mitad + 1, fin);

    // Contar incrementos que cruzan la mitad del array
    int cruzandoMitad = 0;

    // Obtener valores del array
    int valActual, valSiguiente;
    cout << "? " << mitad << '\n';
    cin >> valActual;

    cout << "? " << (mitad + 1) << '\n';
    cin >> valSiguiente;

    if (valActual < valSiguiente) {
        cruzandoMitad++;
    }

    return izquierda + derecha + cruzandoMitad;
}

int main() {
    // Ejemplo de uso
    // (En este caso, el usuario proporcionará los valores del array)
    int longitudArray;
    cout << "Ingrese la longitud del array: ";
    cin >> longitudArray;

    int resultado = contarIncrementos(nullptr, 0, longitudArray - 1);

    cout << "El número de incrementos en el array es: " << resultado << endl;

    return 0;
}

*/