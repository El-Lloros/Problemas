
#include <iostream>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
	                         // los tamaños de los objetos
	int n_objetos;           // Numero de objetos
} tObjetos;



/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/
void resuelve(const tObjetos& objetos, int capacidad_caja,int k,int cajas,int &minimo,int pesocajas[]){
    //caso base 
    if(k==objetos.n_objetos){ //Ya hemos decidido que hacer con todos los objetos
        minimo=cajas;
        return;
    }

    //caso recursivo
    for(int i=0;i<cajas;i++){
        //meto el objeto en alguna caja
        //Comprobamos si el objeto k cabe en la caja i 
        if(pesocajas[i]+objetos.tamanios[k]<=capacidad_caja){
            pesocajas[i]+=objetos.tamanios[k];
            resuelve(objetos,capacidad_caja,k+1,cajas,minimo,pesocajas);
            pesocajas[i]-=objetos.tamanios[k];
        }
        
    }
    //Si no cabe en ninguna caja o ya hemos probado todas, creamos una caja nueva
    /*
    PODA:
        Solo creamos una caja si no existe ya una solución con menos cajas
    */
    if(cajas+1<minimo && k+1>cajas){
        
        pesocajas[cajas] += objetos.tamanios[k];
        resuelve(objetos,capacidad_caja,k+1,cajas+1,minimo,pesocajas);
        pesocajas[cajas] -= objetos.tamanios[k];
        
    }
    //Si llegamos cortamos la cadena de soluciones ya que este objeto no lo metemos en ningun sitio
    return;
}

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
	// A IMPLEMENTAR
    int pesocajas[MAX_OBJS];
	for(int i=0;i<objetos.n_objetos;i++){
        pesocajas[i]=0;
    }
    int minimo=objetos.n_objetos;
    int cajas=1;
    resuelve(objetos,capacidad_caja,0,cajas,minimo,pesocajas);
    return (minimo);
}

/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		cout << min_numero_de_cajas(objetos,capacidad) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}
