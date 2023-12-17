#include <iostream>

using namespace std;

typedef unsigned long long t_num;
	

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

Dado un dígito d, un número a > 0, y un número natural n, n se denomina d-a-limpio cuando toda
secuencia de ocurrencias consecutivas de d en n tiene longitud menor que a.
Diseña e implementa un algoritmo “vuelta atrás” que, dados cuatro valores d, a, s y n, calcule cuántos
números menores que n hay, que: (i) sean d-a-limpios; (ii) no contengan ningún 0; y (iii) sus dígitos
sumen s.



*/
int calcular(unsigned short d, unsigned short alpha, t_num n, unsigned int s,
               unsigned int sumaParcial,t_num solParcial,
                unsigned short dSeguidos

                ){

        //caso base
        if(sumaParcial==s){
            return 1;
        }
       
        //caso recursivo
        int ret=0;
        for(int i = 1;i<10;i++){
            if((solParcial*10+i<n)&&(dSeguidos+(d==i)<alpha)&&(sumaParcial+i<=s)){
                if(d==i){
                    ret+=calcular(d,alpha,n,s,sumaParcial+i,solParcial*10+i,dSeguidos+1);
                }else{
                    ret+=calcular(d,alpha,n,s,sumaParcial+i,solParcial*10+i,0);

                }
            }
        }
        return ret;
}


int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
	// PUNTO DE ENTRADA DEL ALGORITMO
    return calcular(d,alpha,n,s,0,0,0);
}


bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha; 
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}