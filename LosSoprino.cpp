/*
NOMBRE Y APELLIDOS:

Nº USUARIO DOMJUDGE:

*/

#include <iostream>

using namespace std;

const int MAX_PERSONAS = 20;
const int MAX_VEHICULOS = 10;


// Datos de entrada
typedef struct {
	bool ha_bebido[MAX_PERSONAS];   // ha_bebido[i]: La persona i ha bebido
	int capacidad[MAX_VEHICULOS];   // capacidad[v]: Nº de personas que caben en el vehículo v 
	int n_personas;                 // Nº total de personas en el clan
	int n_vehiculos;                // Nº total de vehículos
} tDatos;

/*
    1 no pasarse del aforo
    2 al menos una persona que no bebe
    3 no mas del 50% alcohol
    4 No dejar ningun coche
    5 No dejar personas fuera
*/
int resuelve(const tDatos& datos,int MaxNobeben,int k,int coches[],int cochesAL[],int CochesConductor){
    if(k==datos.n_personas){//k perosnas entadas en coches
        return 1;
    }
    //donde sentamos a la persona k 
    int ret=0;//contador  de formas
    for(int i=0;i<datos.n_vehiculos;i++){
        if(coches[i]>=datos.capacidad[i])//si el coche esta lleno nos vamos a otro
            continue;
        if(cochesAL[i]>=(datos.capacidad[i]/2)&&datos.ha_bebido[k])//si la persona k ha bebido pero ya hay un 50% de bebedores vamos a otro 
            continue;
        if((coches[i]>cochesAL[i])&&(!datos.ha_bebido[k])&&(MaxNobeben-1+CochesConductor<datos.n_vehiculos))//si no ha bebido y lo sentamos en un coche con conductor hay que ver si aun quedan conductores para los demas coches
            continue;
        
        coches[i]++;
        cochesAL[i]+=datos.ha_bebido[k]; //solo se suma si la persona k ha bebido (true)
        ret+=resuelve(datos,(MaxNobeben-(!datos.ha_bebido[k])),k+1,coches,cochesAL,CochesConductor+((coches[i]-1==cochesAL[i])&&(!datos.ha_bebido[k])));//sumamos las soluciones factibles que vienen de esta decision
        coches[i]--;//esta persona ya no se sienta en el coche i
        cochesAL[i]-=datos.ha_bebido[k]; //solo se resta si la persona k ha bebido (true)
    }
    return ret;
}


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

int num_asignaciones(const tDatos& datos) {
	// A IMPLEMENTAR

    int j=0;
    int coches[MAX_VEHICULOS];
    int cochesAL[MAX_VEHICULOS];
    for (int i=0;i<datos.n_personas;i++){
        if(!datos.ha_bebido[i]){
            j++; //cuantas personas no beben
        }
    }
    for (int i=0;i<datos.n_vehiculos;i++){
        coches[i]=0;
        cochesAL[i]=0;
    }
    if(j<datos.n_vehiculos){//Si no hay sufiientes personas que no beben para llevar los coches no entramos
        return 0;
    }else{
        return resuelve(datos,j,0,coches,cochesAL,0);
    }
}


bool ejecuta() {
	tDatos datos;
	cin >> datos.n_vehiculos;
	if (datos.n_vehiculos == -1) return false;
	cin >> datos.n_personas;
	for (int v = 0; v < datos.n_vehiculos; v++) {
		int bebe;
		cin >> datos.capacidad[v];
	}
	for (int p = 0; p < datos.n_personas; p++) {
		int bebe;
		cin >> bebe;
		if (bebe == 0) {
			datos.ha_bebido[p] = false;
		}
		else {
			datos.ha_bebido[p] = true;
		}
	}
	cout << num_asignaciones(datos) << endl;
	return true;

}


int main() {
	while (ejecuta());
}