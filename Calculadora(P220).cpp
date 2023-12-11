#include <iostream>
using namespace std;

void calculadora(int suma, int turno, bool player, bool &pierde, int jugadas[9][4]);

void calculadora(int suma, int turno, bool player, bool &pierde, int jugadas[9][4]){
    if(jugadas[turno][0]+suma < 31 ){
        player=!player;
        for (int i = 0 ; i<4;i++){
            if(jugadas[turno-1][i]+suma<31){
                calculadora(jugadas[turno-1][i]+suma,jugadas[turno-1][i],player,pierde,jugadas);
            }

        }
    }else{
        if(player){
            pierde=true;
        }else{                
            return;
        }
    }
    
    return;
}

void casoDePrueba() {

    // TU CÓDIGO AQUÍ
    int suma;//suma acumulada
    int turno;//ultima tecla pulsada
    bool player=true; //si player es true le toca jugar al jugador que importa
    bool pierde=false;// ¿sera false hasta que encuentre una combinación que pierda?
    cin>>suma;
    cin>>turno;
    int jugadas[9][4] = {//posibles jugadas segun la tecla que se ha pulsado antes
        {2, 3, 4, 7},
        {1, 3, 5, 8},
        {1, 2, 6, 9},
        {1, 5, 6, 7},
        {2, 4, 6, 8},
        {3, 4, 5, 9},
        {1, 4, 8, 9},
        {2, 5, 7, 9},
        {3, 6, 7, 8}
    };


    calculadora(suma,turno,player,pierde,jugadas);
    if(pierde)
        cout<<"PIERDE"<<"\n";
        else
        cout<<"GANA"<<"\n";
} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}