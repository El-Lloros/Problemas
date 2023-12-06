#include <iostream>
using namespace std;
#include <map>

map<int, char> mapaRestosLetras = {
        {0, 'T'},
        {1, 'R'},
        {2, 'W'},
        {3, 'A'},
        {4, 'G'},
        {5, 'M'},
        {6, 'Y'},
        {7, 'F'},
        {8, 'P'},
        {9, 'D'},
        {10, 'X'},
        {11, 'B'},
        {12, 'N'},
        {13, 'J'},
        {14, 'Z'},
        {15, 'S'},
        {16, 'Q'},
        {17, 'V'},
        {18, 'H'},
        {19, 'L'},
        {20, 'C'},
        {21, 'K'},
        {22, 'E'}
    };

void casoDePrueba() {

    int n=0;
    int numero[8];
    int resto;
    char inputChar;
    for (int i = 0; i < 8; ++i) {
        cin >> inputChar;
        if(inputChar=='?'){
            n++;
            numero[i]=0;
        }else{
            // Convertir el carácter a un número y almacenarlo en el vector
            numero[i]=(inputChar - '0');
        }
    }

    // Leer la letra y buscar su valor en el diccionario
    cin >> inputChar;
    resto=(mapaRestosLetras[inputChar]);

} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}