
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION: 
  ---Escribe aqu� la precondici�n de la funci�n.
  
*/

int tramo_mas_corto(bool a[], int n, int k); 

/*
POSTCONDICION DE LA FUNCION: 
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'
     

	 
 */
 

/*
DISE�O DEL ALGORITMO:

Paso 1. Variables


Paso 2. Invariante
     

Paso 3. Inicializaci�n

Paso 4. Condici�n del bucle, y c�digo tras el bucle.

	
Paso 5. Cuerpo del bucle

Paso 6. Justificaci�n de que el algoritmo siempre termina.
 
 
Paso 7. Complejidad:

 
*/
 


int tramo_mas_corto(bool v[], int n, int k) {
   // A IMPLEMENTAR	   
    int a=0;
    int b=0;
    int Kacum=0;
    int ret=0;
    int minret=n+1;
    while(b<n||Kacum>=k){
        if(Kacum<k){
            if(v[b]==1)
                Kacum++;
            b++;
            ret++;
        }else{
            if(k==Kacum)
                minret=min(b-a,minret);
            Kacum-=v[a];
            ret--;
            a++;
        }
        
        
    }
    return minret;

}	

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA: 
   NO MODIFICAR 
   
   Un k-tramo de un vector de booleanos es una secuencia de valores consecutivos del vector en la que
aparecen exactamente k trues.
Se desea desarrollar un algoritmo iterativo que, dado un entero positivo k y un vector de booleanos,
almacenado en las n primeras posiciones de un array a, determine el tamaño del k-tramo más corto de
dicho vector. En caso de que el vector no contenga ningún k-tramo, el algoritmo deberá devolver n+1.
   
   */

   
void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}
	
	