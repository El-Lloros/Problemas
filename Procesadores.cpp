/*
NOMBRE Y APELLIDOS: 

IMPORTANTE: Si no se añade el nombre y apellidos,
el ejercicio no se corregirá (puntuará como 0).

*/
#include <iostream>

using namespace std;


const int MAX_PROCESOS = 100; 

// Tipo para codificar los datos de entrada
// al problema
typedef struct {
	int t_procesamiento;  // Tiempo de procesamiento 'T' de los procesadores.
	                      // Cada procesador permite utizar, como máximo,
						  // 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS];  // Unidades de tiempo requeridas por cada proceso. 
	int b_procesos[MAX_PROCESOS];  // Beneficio reportado por cada proceso.
	int n;                         // Número de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;

void resuelve(const tEntrada& entrada,int k,int t1,int t2, int beneficio,int beneficioRestante, int &maximo){
    //caso base Hemos decidido que hacer con todos los procesos
    if(k==entrada.n){
        maximo=beneficio;
        return;
    }
    //asignamos procesos o no
    //se lo asignamos a p1
    if(t1+entrada.t_procesos[k]<=entrada.t_procesamiento){
        resuelve(entrada,k+1,t1+entrada.t_procesos[k],t2,beneficio+entrada.b_procesos[k],beneficioRestante-entrada.b_procesos[k],maximo);
    }
    //se lo asignamos a p2
    if(t2+entrada.t_procesos[k]<=entrada.t_procesamiento){
        resuelve(entrada,k+1,t1,t2+entrada.t_procesos[k],beneficio+entrada.b_procesos[k],beneficioRestante-entrada.b_procesos[k],maximo);
    }
    //no se asigna a ninguno
    if((beneficioRestante-entrada.b_procesos[k])+beneficio>maximo){
        resuelve(entrada,k+1,t1,t2,beneficio,beneficioRestante-entrada.b_procesos[k],maximo);
    }

    return;   
}

/*
1 cada proceso solo se ejecuta una vez
2 no se pude fragmentar el proceso
3 un proceso en cada uno
4 T es para cada procesador no la suma de los dos

IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del diseño del algoritmo. No 
se tendrá en cuenta la codificación del algoritmo, a menos que
esté acompañada del diseño sistemático del mismo.
*/


/*
(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Si estás utilizando algún criterio de poda adicional, explica detalladamente
    el criterio utilizado

(7) Análisis de casos

(7.1) Caso(s) base


(7.2) Caso(s) recursivos

(8) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
int max_beneficio(const tEntrada& entrada) {
	// A IMPLEMENTAR: Debe devolver el beneficio máximo
	// que puede conseguirse
    int beneficioRestante=0;
    int maximo=0;
    for (int i=0;i<entrada.n;i++){
        beneficioRestante+=entrada.b_procesos[i];
    }
    resuelve(entrada,0,0,0,0,beneficioRestante,maximo);
    return maximo;
}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el código que sigue no se corregirán (puntuarán 0).

bool ejecuta_caso() {
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0) {
		return false;
	}
	else {
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}



