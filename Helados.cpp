#include <iostream>
using namespace std;
#include <string>


void cucurucho(//descripcion del problema
                int choco,int vainilla,
                //Sol parcial
                string solucion, int k,
                //marcaje
                int bolasC,int bolasV);

bool valido(//descripcion del problema
                int choco,int vainilla,
                //Sol parcial
                string solucion, int k,
                //marcaje
                int bolasC,int bolasV, int &primercaso);




bool valido(//descripcion del problema
                int choco,int vainilla,
                int bolasC,int bolasV
){
                    
    if(bolasC<=choco && bolasV<=vainilla)
        return true;
    else    
        return false;

                
}                

void cucurucho( //descripcion del problema
                int choco,int vainilla,
                //Sol parcial
                string solucion, int k,
                //marcaje
                int bolasC,int bolasV,
                int &primercaso
            

){
    //Caso base
    if(k==(choco+vainilla)){
        if(primercaso==1)
            cout<<" ";
        else
            primercaso=1;
        for (int i=0;i<k;i++){
            cout<<solucion[i];
        }
              
        return;
    }
    solucion[k]='C';
    if(valido(choco,vainilla,bolasC+1,bolasV)){
        bolasC++;
        cucurucho(choco,vainilla,solucion,k+1,bolasC,bolasV,primercaso);
        bolasC--;
    }
    solucion[k]='V';
    if(valido(choco,vainilla,bolasC,bolasV+1)){
        bolasV++;
        cucurucho(choco,vainilla,solucion,k+1,bolasC,bolasV,primercaso);
        bolasV--;
    }

return;
}
void casoDePrueba() {
    int choco, vainilla;
    int primercaso=0;
    cin >>choco>>vainilla;
    string solucion;
    cucurucho(choco,vainilla,solucion,0,0,0,primercaso);
    cout<<'\n';
    return;

} // casoDePrueba

int main() {
    unsigned int numCasos;

    cin >> numCasos;
    for (unsigned int i = 0; i < numCasos; ++i) {
        casoDePrueba();
    }
  
    return 0;
}