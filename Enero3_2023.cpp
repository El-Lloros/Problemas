/*
NOMBRE Y APELLIDOS:

*/


#include <iostream>

using namespace std;

static const int MAX_MONEDAS = 100;

/* Tipo para representar los datos de entrada */
typedef struct {
  int num_monedas;     /* Número de monedas a repartir */
  int min_monedas;     /* Mínimo de monedas que debe recibir cada pirata -los dos deben
                          recibir este mínimo número de monedas */
  int valor_monedas[MAX_MONEDAS];  /* Valor de las distintas monedas a repartir */
} tEntrada;


/*
(1) ¿Cómo son las soluciones parciales viables de este problema?

(2) ¿Cuándo una solución es final?

(3) Dada una solución viable, ¿cómo se generan nuevas soluciones viables a partir de ella?

(4) ¿Cómo se representarán las soluciones en este problema? Describe los distintos elementos
    de información que las componen, indicando si se representan como parámetros de entrada,
	de entrada/salida (estado global), si se representan implícitamente...

(5) ¿Qué marcadores utiliza el algoritmo? Describe claramente su propósito, los elementos
    de información que los componen, así como si dichos elementos se representan como parámetros
	de entrada, de entrada/salida (estado global)... 

(6) Si el algoritmo utiliza generalización, indica como es la misma, describiendo claramente
    el propósito de cada parámetro.
	
(7) Análisis de casos: casos base, casos recursivos

(8) Si el algoritmo utiliza una generalización, describe cómo se implementa el algoritmo
    en términos de la misma (inmersión)

*/

 
  /* - En min_dif debe devolverse la mínima diferencia que puede conseguirse.
     - En num_formas debe devolverse el número de soluciones que presentan dicha diferencia mínima.
   */	
 void asigna(const int valorMonedas[],const int n,const int minimo, int& min_dif, int& num_formas, 
 int k,int solParcial[],
 int ganancias[],int pendientes[],long long valorPendiente
 ){
    if(k==n){
        if(abs(ganancias[1]-ganancias[0])==min_dif){
            ++num_formas;
        }
        else{
           //if(abs(ganancias[1]-ganancias[0])<min_dif){ 
            min_dif=abs(ganancias[1]-ganancias[0]);
            num_formas=1;
            
        }
        return;
    }
    //caso recursivo
    for(int i=0;i<2;i++){
        int otro;
        if(i==0){
            otro=1;
        }else{
            otro=0;
        }
        if(pendientes[otro]>0 && ((n-(k+1))<pendientes[otro])){
            continue;
        }
      
       if(abs((ganancias[i]+valorMonedas[k])-ganancias[otro])-(valorPendiente-valorMonedas[k])>min_dif){
            continue;
        }

        ganancias[i]+=valorMonedas[k];
        solParcial[k]=i;
        --pendientes[i];
        //valorPendiente-=valorMonedas[k];
        asigna(valorMonedas,n,minimo,min_dif,num_formas,k+1,solParcial,ganancias,pendientes,valorPendiente-valorMonedas[k]);
        //valorPendiente+=valorMonedas[k];
        ganancias[i]-=valorMonedas[k];
        ++pendientes[i];

    }
    return;

 } 
 void reparte(const tEntrada& entrada, int& min_dif, int& num_formas) {
	 // A IMPLEMENTAR
     int pendientes[2];
     pendientes[0]=entrada.min_monedas;
     pendientes[1]=entrada.min_monedas;
     int ganancias[2];
     ganancias[0]=0;
     ganancias[1]=0;
     int dummy[MAX_MONEDAS];
     long long valorPendiente=0;
     for(int i=0;i<entrada.num_monedas;i++){
        valorPendiente+=entrada.valor_monedas[i];
     }
     min_dif=valorPendiente;
     num_formas=0;
     
     asigna(entrada.valor_monedas,entrada.num_monedas,entrada.min_monedas,min_dif,num_formas,0,dummy,ganancias,pendientes,valorPendiente);

 }

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

 bool ejecuta_caso() {
	 int num_monedas;
	 cin >> num_monedas;
	 if (num_monedas == -1) return false;
	 else {
		 tEntrada entrada;
		 entrada.num_monedas = num_monedas;
		 cin >> entrada.min_monedas;
		 for (int m = 0; m < num_monedas; m++) {
			 cin >> entrada.valor_monedas[m];
		 }
		 int min_dif;
		 int num_formas;
		 reparte(entrada, min_dif, num_formas);
		 cout << min_dif << " " << num_formas << endl;
		 return true;
	 }
 }

 int main() {
	 while (ejecuta_caso());
	 return 0;
 }