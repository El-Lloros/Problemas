/*
NOMBRE Y APELLIDOS: 
    Laura Chueca Bronte

*/

#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aquí la precondición de la función.


*/

bool /* resul */ hay_c_tramo(int a[], int n, int c);

/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aquí la poscondición de la función. Para refirte
	   ---al valor devuelto por la función, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):


	(2) Postcondición



 */



/* DISEÑO DEL ALGORITMO:
	--- Detalla aquí el proceso seguido para diseñar el
	--- algoritmo

	PASO 1. Variables adicionales (aparte de los parámetros y el resultado)

	PASO 2. Invariante
	   (2.1) Definiciones auxiliares (si procede)
	   
	   
	   
	   (2.2) Invariante
	

	PASO 3. Código de inicialización, justificando que, tras
	        dicho código, se cumple el invariante

	
	PASO 4. Condición del bucle, código tras el bucle (si procede),
	        y justificación de que, una vez finalizado el algoritmo,
			se cumple la postcondición


    PASO 5. Diseño del cuerpo del bucle, justificando que dicho código
	        preserva el invariante


	PASO 6: Expresión de cota y justificación de que el algoritmo siempre 
	        termina


	PASO 7: Determinación justificada de la complejidad del algoritmo

*/

bool /* resul */ hay_c_tramo(int v[], int n, int c){
	/* IMPLEMENTACION */
	int a=0;
    int b=0;
    int sumaAcu=0;
    while(b<n&&sumaAcu!=c){
        if(sumaAcu+v[b]<=c){
            sumaAcu+=v[b];
            b++;
        }
        else{
            sumaAcu-=v[a];
            ++a;
        }
    }
    return(sumaAcu==c);
}	


/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/


const static int MAX_ELEMS=1000000;
bool ejecuta_caso() {
  	static int a[MAX_ELEMS];
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
      for (int i=0; i < n; i++) {
		  cin >> a[i];
	  }
	  int c;
	  cin >> c;
	  if (hay_c_tramo(a,n,c)) {
		  cout << "SI" << endl;
	  }
	  else {
	      cout << "NO" << endl;
	  }	  
      return true;	  
	}
}

int main() {
	while(ejecuta_caso());
}
