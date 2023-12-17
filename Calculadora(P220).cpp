#include <iostream>
using namespace std;



bool esGanadora(int valorCalculadora, int ultimoSumado,int jugadas[9][4]);

bool esGanadora(int valorCalculadora, int ultimoSumado,int jugadas[9][4]){
    if(valorCalculadora>30){
        return true;
    }
    bool ret=false;
    if(jugadas[ultimoSumado-1][0]+valorCalculadora<=30){
            
            for (int i = 0 ; i<4;i++){ 
                if(jugadas[ultimoSumado-1][i]+valorCalculadora<=30){ 
                    if(esGanadora(valorCalculadora+jugadas[ultimoSumado-1][i],jugadas[ultimoSumado-1][i],jugadas)){
                        ret=false;  
                    }else{
                        return true;
                    }
                }
            }
        
     }else{
        return false;
     }
    return ret;
}


void casoDePrueba() {

    // TU CÓDIGO AQUÍ
    int suma;//suma acumulada
    int turno;//ultima tecla pulsada
    
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


    
    if(esGanadora(suma,turno,jugadas))
        cout<<"GANA"<<"\n";
        else
        cout<<"PIERDE"<<"\n";
} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}