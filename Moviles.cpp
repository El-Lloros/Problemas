#include <iostream>
#include<algorithm>
using namespace std;
bool movil(int pi,int di,int pd,int dd,int &w);

bool movil(int pi,int di,int pd,int dd,int &peso){
     bool left = true;
    if (pi == 0) {
        int pii, dii, pdi, ddi;
        cin>>pii>>dii>>pdi>>ddi;
        left = movil(pii, dii, pdi, ddi, pi);
    }

    bool right = true;
    if (pd == 0) {
        int pid, did, pdd, ddd;
        cin>>pid>>did>>pdd>>ddd;
        right = movil(pid, did, pdd, ddd, pd);
    }
    peso = pi + pd;
    return left && right && pi*di == pd*dd;



    
}
bool casoDePrueba() {
    int pi , di , pd, dd, peso;
    
    cin>>pi>>di>>pd>>dd;
    
    //leer caso de prueba
    if (pi==0&&di==0&&pd==0&&dd==0)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ
        if(movil(pi,di,pd,dd,peso)){
            cout<<"SI"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
        
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}