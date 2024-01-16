
#include <iostream>
#include<algorithm>

using namespace std;


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.

(4) An�lisis de la complejidad del algoritmo

*/

bool posible(int v[], int n, int max_duelos,long long m) {
	int duelos = 1;
	int a = 0;
	int suma = 0;
	while (a<n) {
		suma += v[a];
		if (suma > m) {
			duelos++;
			suma = v[a];
			a++;
		}
		else {
			a++;
		}
		
	}
	return(duelos<=max_duelos);
}
int min_poder(int enemigos[], int n, int max_duelos,long long suma,int maxi) {
	// Punto de entrada al algoritmo: a implementar
	int a = maxi;
	long long b = suma;
	while (a < b) {
		long long m = (a + b) / 2;
		if (posible(enemigos, n, max_duelos, m)) {
			b = m;
		}
		else {
			a = m + 1;
		}

	}
	return a;
}


const int MAX_ENEMIGOS = 1000;
bool ejecuta_caso() {
	int enemigos[MAX_ENEMIGOS];
	int num_enemigos;
	cin >> num_enemigos;
	if (num_enemigos == -1) {
		return false;
	}
	else {
		int max_torneos;
		cin >> max_torneos;
		long long suma=0;
		int maxi = 0;
		for (int i = 0; i < num_enemigos; i++) {
			cin >> enemigos[i];
			suma += enemigos[i];
			maxi = max(maxi, enemigos[i]);
		}
		cout << min_poder(enemigos, num_enemigos, max_torneos,suma,maxi) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}