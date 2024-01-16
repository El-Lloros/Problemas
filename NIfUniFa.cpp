/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
using namespace std;


/*
Nota: NO es necesario que especifiques el algoritmo, ni las
funciones auxiliares utilizadas. Pero, en caso de utilizar
una generalización, sí debes describir sus parámetros, 
su resultado, y el próposito de los mismos 

(1) SI UTILIZAS UNA GENERALIZACION, DETALLA AQUÍ SUS PARÁMETROS,
    SU RESULTADO, Y EL PROPÓSITO DE LOS MISMOS 


(2) DISEÑO (CASOS)


(3) JUSTIFICACION DE LA TERMINACION DEL ALGORITMO


(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE


(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO


*/

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/
bool hay_nifunifa(int v[],int a, int b){
    int numelementos=b-a;
    if(numelementos<=2){
        return false;
    }
    if(v[a]==v[b-1]){
        return false;
    }

    int m=(b-a)/2;
    if(v[a]==v[m]){
        return hay_nifunifa(v,m,b);
    }else if(v[b-1]==v[m]){
        return hay_nifunifa(v,a,m+1);
    }else{
        return true;
    }
}
bool hay_nifunifa(int a[], int n) {
	// A IMPLEMENTAR
    int max=a[n-1];
    int min=a[0];
    int a0=0;
    int b=n-1;
    if(min==max||max-min==1){
        return false;
    }else{
        int m;
        while(b-a0>1){
            m=(a0+b)/2;
            if(a[m]==a[b]){
                b=m;
            }else if(a[m]==a[b]){
                a0=m;
            }else{
                return true;
            }  
        }
        return false;

        
    }

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
	  if (hay_nifunifa(a,n)) {
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