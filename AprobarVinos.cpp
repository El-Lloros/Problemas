
#include <iostream>
using namespace std;

/* Estructura utilizada para almacenar la información de un tema */
typedef struct {
  float tiempo_req;  // tiempo requerido para estudiar el tema
  float nota_prim;   // aportación a la nota de la primera parte
  float nota_sec;    // aportación a la nota de la segunda parte
} tInfoTema;



/*
DISEÑO DEL ALGORITMO

Para superar este ejercicio, aparte de programar el algoritmo, debes 
describir aqui detalladamente su diseño (parámetros y variables utilizados,
y su cometido, cometido de los resultados devueltos por las funciones,
idea general del algoritmo, estructura de las soluciones,
análisis de casos, acciones realizadas para cada caso...)





*/
void solucion( 
//Datos del problema
const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible,
//Solucion Parcial
int k,
float notaAcumulada1,
float notaAcumulada2,
float tiempoConsumido,
//Marcaje
float &notaMaxima,
//Poda
float notaRestante1,
float notaRestante2
){
    //Caso Base
    if(num_temas==k){
         notaMaxima=(notaAcumulada1+notaAcumulada2)/2;
         return;
    }

    //Estudiamos tema k
    if(tiempoConsumido+info_temas[k].tiempo_req<=tiempo_disponible){
        solucion(info_temas,num_temas,tiempo_disponible,k+1,notaAcumulada1+info_temas[k].nota_prim,
        notaAcumulada2+info_temas[k].nota_sec,tiempoConsumido+info_temas[k].tiempo_req,notaMaxima,
        notaRestante1-info_temas[k].nota_prim,notaRestante2-info_temas[k].nota_sec);
    }

    //No estudiamos k
    if((notaAcumulada1+notaRestante1-info_temas[k].nota_prim>=5)&&(notaAcumulada2+notaRestante2-info_temas[k].nota_sec>=5)){
        if((notaAcumulada1+notaRestante1-info_temas[k].nota_prim+notaAcumulada2+notaRestante2-info_temas[k].nota_sec)/2>notaMaxima){
            solucion(info_temas,num_temas,tiempo_disponible,k+1,notaAcumulada1,
            notaAcumulada2,tiempoConsumido,notaMaxima,
            notaRestante1-info_temas[k].nota_prim,notaRestante2-info_temas[k].nota_sec);
        }

    }

    return;

}

   /* temas: Información sobre los temas de los que consta el examen (ver tInfoTema)
      num_temas: Numero de temas de los que consta el examen -su información aparece 
	             al principio de info_temas
	  tiempo_disponible: Tiempo total disponible para realizar el examen. 
	  Valor devuelto: La puntuación media máxima que se puede conseguir, o -1 si no 
	                  es posible aprobar el examen */
float mejor_puntuacion(const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible) {
	  /* ESTA FUNCIÓN SERÁ EL PUNTO DE ENTRADA AL ALGORITMO. Puedes, después, utilizar las 
	     funciones auxiliares que consideres oportuno, pero debes incluir la justificación para ello
		 en el comentario de descripción detallado del diseño de dicho algoritmo */
         float notaRestante1=0;
         float notaRestante2=0;
         for(int i=0;i<num_temas;i++){
            notaRestante1+=info_temas[i].nota_prim;
            notaRestante2+=info_temas[i].nota_sec;
         }
         float notaMaxima;
         notaMaxima=-1;
         solucion(info_temas,num_temas,tiempo_disponible,0,0,0,0,notaMaxima,notaRestante1,notaRestante2);
		 return notaMaxima;
}

/* Código para leer y ejecutar casos de prueba: no debe modificarse */
const unsigned int MAX_TEMAS = 20;

bool procesa_caso() {
	int num_temas;
	tInfoTema info_temas[MAX_TEMAS];
	cin >> num_temas;
	if (num_temas != -1) {
		float tiempo_disponible;
		cin >> tiempo_disponible;
		for (int i = 0; i < num_temas; i++) {
			cin >> info_temas[i].tiempo_req;
			cin >> info_temas[i].nota_prim;
			cin >> info_temas[i].nota_sec;
		}
		cout << mejor_puntuacion(info_temas, num_temas, tiempo_disponible) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (procesa_caso());
}