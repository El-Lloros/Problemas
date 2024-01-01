#include <iostream>
using namespace std;

const unsigned int MAX_NINIOS = 20; // maximo numero de ni�os
                                    // el n�mero de sitios siempre
									// ser� menor o igual que el
									// n�mero de ni�os

  // Representaci�n de la matriz de satisfacciones
typedef struct {
	int n_ninios;	// numero de ni�os.
    int n_sitios;	// numero de sitios
	int sat[MAX_NINIOS][MAX_NINIOS];  // la posici�n i,j representa la satisfaccion
                                      // que siente el ninio i si se le asigna el sitio j											   
} tMatrizSatisfacciones;

void resuelve(const tMatrizSatisfacciones& sats, int h, int k,int supersticiosos,bool asientos[],int maxAsiento[], int MaxPosible,int SolParcial,int &optimo){
    //Caso base
    if(k== sats.n_ninios){
        optimo=SolParcial;
        return;
    }
    //invitar al niño
    for(int i=0;i<sats.n_sitios;i++){
        if(asientos[i])
            continue;
        if(k%sats.n_sitios==i&&supersticiosos==(sats.n_sitios/3))
            continue;
        if(sats.sat[k][i]<0)
            continue;
        if((MaxPosible-maxAsiento[k])+(SolParcial+sats.sat[k][i])<optimo)
            continue;
        asientos[i]=true;
        resuelve(sats,h,k+1,supersticiosos+(k%sats.n_sitios==i),asientos,maxAsiento,MaxPosible-maxAsiento[k],SolParcial+sats.sat[k][i],optimo);
        asientos[i]=false;

    }
    //tu hermano siempre se invita
    if(k==h)
        return;
    //no invitar niño
    if(MaxPosible-maxAsiento[k]+SolParcial>=optimo){
        resuelve(sats,h,k+1,supersticiosos,asientos,maxAsiento,MaxPosible-maxAsiento[k],SolParcial,optimo);
    } 
    
    return;
}
/*
N niños M sitios; nxm
A nadie se le asignará un puesto que tenga satisfacción negativa. Prefiere no ir, antes de utilizar
ese sitio.
• Los niños se han vuelto muy supersticiosos y en general si su número de lista de clase es k,
tienden a evitar sentarse en el puesto i en el que k%m = i (con m el número de puestos totales).
Es por esto que no se considerarán buenas asignaciones en las que esto ocurra más de m/3 veces
(usando división entera).
• Obviamente, tu hermano debe ser invitado...
• Tanto los números en la lista de clase como los puestos están numerados empezando a contar
desde el 0.


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



*/

int satisfaccion_maxima(const tMatrizSatisfacciones& sats, int h) {
	// A IMPLEMENTAR
    int maxAsiento[MAX_NINIOS];
    bool asientos[MAX_NINIOS];
    int MaxPosible=0;
    for(int i=0;i<sats.n_ninios;i++){
        maxAsiento[i]=sats.sat[i][0];
        for(int j=0;j<sats.n_sitios;j++){
            maxAsiento[i]=max(maxAsiento[i],sats.sat[i][j]);
            asientos[j]=false;
        }
        if(maxAsiento[i]<0)
            maxAsiento[i]=0;
        MaxPosible+=maxAsiento[i];
    }
    int optimo=0;
    resuelve(sats,h,0,0,asientos,maxAsiento,MaxPosible,0,optimo);
    return optimo;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */
					
bool ejecuta_caso() {
	tMatrizSatisfacciones sats;
	cin >> sats.n_ninios;
	if (sats.n_ninios != -1) {
	   cin >> sats.n_sitios;
	   int h;
	   cin >> h;
	   for (int sitio=0; sitio < sats.n_sitios; sitio++) {
		   for (int ninio=0; ninio < sats.n_ninios; ninio++) {
			   cin >> sats.sat[ninio][sitio];
		   }
	   }
	   cout << satisfaccion_maxima(sats,h) << endl; 
	   return true;
	}
	else {
		return false; 
	}
}	


int main() {
	while(ejecuta_caso());
}