
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
//Datos del problema (datos que nos da el problema, en este caso la entrada)
const tInfoTema info_temas[], unsigned int num_temas, float tiempo_disponible,
//Solucion Parcial
int k,//Tema que vamos a decidir si vamos a estudiar o no [0,numtemas-1]
float notaAcumulada1,//Nota que llevamos en la parte 1 antes de decidir que hacer con el tema k
float notaAcumulada2,//Nota que llevamos en la parte 2 antes de decidir que hacer con el tema k
float tiempoConsumido,//Tiempo que hemos consumido antes de decidir que hacer con el tema k
//Marcaje
float &notaMaxima,//Nota maxima que hemos llegado a conseguir despues de decidir que hacer con todos los temas
                  // esta nota solo se actualiza si hemos aprobado  
//Poda
float notaRestante1,//Nota que aun se puede obtener  (Si estudias todos los teamas que quedan)
                    // en la Primera parte
float notaRestante2//Nota que aun se puede obtener  (Si estudias todos los teamas que quedan)
                    // en la segunda parte
){
    //Caso Base
    if(num_temas==k){//Ya hemos decidido que hacer con todos lo temas
         notaMaxima=(notaAcumulada1+notaAcumulada2)/2;
         //si hemos llegado aqui es la nota maxima asi que actualizamos
         //la nota con la media de las dos partes
         return;
    }
    /*
        En el caso recursivo solo hay dos opciones:
        1.- Estudiamos el tema k
        2.- No estudiamos el tema k
    */
    //Estudiamos tema k
    /*
        Si estudiamos el tema K tenemos que comprobar si nos da tiempo a estudiarlo
        si no nos da tiempo nos saltamos esta opción
    */
    if(tiempoConsumido+info_temas[k].tiempo_req<=tiempo_disponible){
        solucion(info_temas,num_temas,tiempo_disponible,k+1,notaAcumulada1+info_temas[k].nota_prim,
        notaAcumulada2+info_temas[k].nota_sec,tiempoConsumido+info_temas[k].tiempo_req,notaMaxima,
        notaRestante1-info_temas[k].nota_prim,notaRestante2-info_temas[k].nota_sec);
    }
    /*
        Su llegamos aqui es por una de estas dos razones:
        1.- Ya hemos visto que pasaría si nos estudiamos K 
            y ahora vamos a comprobar el resultado si no nos estudiamos K
        2.- No nos da tiempo a estudiar el tema K

        ¿Cuándo podemos NO estudiar el tema K?
        Cuando incluso si no obtenemos la nota de K aun tenemos posibilidades 
        de aprobar si nos estudiamos los temas que nos quedan despues de K
        Para eso comprobamso que la nota que llevamos ahora (notaAcumulada) + la nota que aun podemos conseguir (notaRestante-nota del tema K (ya que no lo vamos a estudiar)) es >=5
        PODA:
        Ademas tenemos que comprobar (Segundo IF) que tenemos  posibilidades de mejorar la nota maxima ya obtenida
    */
    //No estudiamos k
    if((notaAcumulada1+notaRestante1-info_temas[k].nota_prim>=5)&&(notaAcumulada2+notaRestante2-info_temas[k].nota_sec>=5)){
        if((notaAcumulada1+notaRestante1-info_temas[k].nota_prim+notaAcumulada2+notaRestante2-info_temas[k].nota_sec)/2>notaMaxima){
            solucion(info_temas,num_temas,tiempo_disponible,k+1,notaAcumulada1,
            notaAcumulada2,tiempoConsumido,notaMaxima,
            notaRestante1-info_temas[k].nota_prim,notaRestante2-info_temas[k].nota_sec);
        }

    }
    //Si llegamos aqui ya no hay mas opciones asi que cortamos 

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
         float notaRestante1=0;//Nota que aun se puede obtener (Si estudias todos los teamas que quedan) en la Primera parte
         float notaRestante2=0;//Nota que aun se puede obtener (Si estudias todos los teamas que quedan) en la Segunda parte
         for(int i=0;i<num_temas;i++){
            //Al empezar tienes todos los puntos disponibles (No hemos descartado temas aun)
            notaRestante1+=info_temas[i].nota_prim;
            notaRestante2+=info_temas[i].nota_sec;
         }
         float notaMaxima;
         notaMaxima=-1;//Si no se puede aprobar, nos dicen que tenemos que devolver -1
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