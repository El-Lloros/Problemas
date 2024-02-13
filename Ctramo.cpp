/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aquí la precondición de la función.
    0<=n<=long(a)&&
    0<c&&
    Pt:0<=i<=n:a[i]>0

*/

bool /* resul */ hay_c_tramo(int a[], int n, int c);

/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aquí la poscondición de la función. Para refirte
	   ---al valor devuelto por la función, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):
        ExisteTramo=Existe:0<=incio<=fin<=n :suma(incio,fin,v)==c
        siendo suma(inicio,fin,a) = Suma:inicio<=j<fin:a[j]
	(2) Postcondición
    resul=ExisteTramo(v,n,c)


 */



/* DISEÑO DEL ALGORITMO:
	--- Detalla aquí el proceso seguido para diseñar el
	--- algoritmo

	PASO 1. Variables adicionales (aparte de los parámetros y el resultado)
        - int inicio es el indice del lateral izquierdo de la ventana deslizante
        - int fin es el indice del lateral derecho de la ventana deslizante
        - suma : suma acumulada de los valores del vector que estan dentro de la ventana [inicio,fin)

	PASO 2. Invariante
	   (2.1) Definiciones auxiliares (si procede)
            siendo suma = Suma:inicio<=j<fin:a[j]
	   
	   (2.2) Invariante
            0<=inicio<=fin<=n && suma<=c
            

	PASO 3. Código de inicialización, justificando que, tras
	        dicho código, se cumple el invariante
            inicio=0
            fin=0
            suma=0
            0<=0(inicio)<=0(fin)<=n
            0(suma)<=c
            suma=Suma: false : a[j]=0
	
	PASO 4. Condición del bucle, código tras el bucle (si procede),
	        y justificación de que, una vez finalizado el algoritmo,
			se cumple la postcondición
            el bucle termina cuando 
                suma==c
            o hemos llegado al final del vector
            devolvemos si la suma == c o sea resul


    PASO 5. Diseño del cuerpo del bucle, justificando que dicho código
	        preserva el invariante
            if(suma+v[fin]<=c){
                suma+=v[fin];
                fin++;
            }else{
                suma-=v[inicio];
                inicio++;
            }
            al entras suma no tiene añadido a[fin] y este solo se añade si cumple que al añadirlo suma<=c;
            tras esto avanzamos fin
            si no se cumple avanzamos inicio (restando su valor a la suma) manteniendo suma <=c

	PASO 6: Expresión de cota y justificación de que el algoritmo siempre 
	        termina
            Cota: 2n - inicio - fin
            O bien encontramos c-tramo (suma==c)
            o fin == n

	PASO 7: Determinación justificada de la complejidad del algoritmo
            O(2n)=O(n)
*/

bool /* resul */ hay_c_tramo(int v[], int n, int c){
	/* IMPLEMENTACION */
	int inicio=0;
    int fin=0;
    int suma=0;
    while(fin<n&&suma!=c){
        if(suma+v[fin]<=c){
            suma+=v[fin];
            fin++;
        }else{
            suma-=v[inicio];
            inicio++;
        }
    }

    return suma==c;
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
