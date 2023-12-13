/*(((a op1 b) op2 c) op3 d) op4 e=K*/
#include <iostream>
using namespace std;
bool esPosible(int k,int numeros[5],int op,int parcial);
int operacion(int num,int operacion, int parcial );
bool esPosible(int k,int numeros[5],int op,int parcial){
    /*IDEA: vamos probando operaciones que se aplican siempre con lo que hay en parcial
     y cuando lleguemos a 4 operaciones comprobamos si el parcial es igual que K*/
     //Caso base
     if(op==4){
        if(parcial==k){
            return true;
        }else{
            return false;
        }

    for(int i=0;i<4;i++){
        int operamos = operacion(numeros[op+1],i,parcial);
        if(esPosible(k,numeros,op,parcial)){
            return true;
        }
    }

     }
}



bool casoDePrueba() {

    //leer el inicio del caso de prueba (cin)
    int k,numeros[5];
    cin>>k;
    int parcial;
    for(int i=0;i<5;i++){
        cin>>numeros[i];
    }
    parcial=numeros[0];
    if (!cin)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ (incluyendo el resto de la lectura)
        if(esPosible(k,numeros,0,parcial)){
            cout<<"SI"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }
        return true;
    }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}