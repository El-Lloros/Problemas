
#include <iostream>
using namespace std;

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
  // Representaci�n de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
	                                                      // 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;

						 
/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.

No es posible emparejar un cliente consigo mismo.
• Todos los clientes deben tener pareja, y dicha pareja debe ser única.
• Si el cliente i está emparejado con el cliente j, entonces ambos clientes deben ser compatibles, en
el sentido de que Aij > 0 (es decir, el cliente i debe tener cierto grado de afinidad con el cliente j)
y Aji > 0 (es decir, el cliente j debe tener cierto grado de afinidad con el cliente i).
Por otra parte: (i) la afinidad de una pareja {i, j} es la suma de la afinidad que i siente por j, y la afinidad
que j siente por i (es decir, Aij + Aji); y (ii) la afinidad de un emparejamiento es la suma de las afinidades
de todas las parejas que forman parte de dicho emparejamiento.

*/
void resuelve(const tMatrizAfinidad& as,int k,bool emparejado[],int afinidad,int &maximo){
    //caso base emparejamos a todos
    if(k==as.n_clientes){
        maximo=max(afinidad,maximo);
        return;
    }
    //Si ya tiene pareja no hacemos nada
    if(emparejado[k]){
        resuelve(as,k+1,emparejado,afinidad,maximo);
    }else{
    //Emparejamos a clientes
        for(int i=k+1;i<as.n_clientes;i++){
            if(emparejado[i])
                continue;
            if(as.afinidades[k][i]<=0||as.afinidades[i][k]<=0)
                continue;
            if(i==k)
                continue;
            emparejado[k]=true;
            emparejado[i]=true;
            resuelve(as,k+1,emparejado,afinidad+(as.afinidades[i][k]+as.afinidades[k][i]),maximo);
            emparejado[k]=false;
            emparejado[i]=false;
        }
    }
    //si no tiene pareja return;
    return;
}

int maxima_afinidad(const tMatrizAfinidad& as) {
	// Punto de entrada al algoritmo: as representa la matriz de afinidades 
	// (ver definici�n de tMatrizAfinidad). Una vez finalizado el algoritmo,
	// deber� devolverse el valor pedido. Pueden definirse todas las 
	// funciones auxiliares que se considere oportuno.
    bool emparejados[MAX_CLIENTES];
    for(int i=0;i<as.n_clientes;i++){
        emparejados[i]=false;
    }
    int maximo=0;
    resuelve(as,0,emparejados,0,maximo);
    return maximo;
}


void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}