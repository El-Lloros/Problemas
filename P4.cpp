#include <iostream>
#include<algorithm>
using namespace std;
bool resuelvecaso();
bool resuelvecaso(){

    int tamx,tamy;
    int x0=0, y0=0,ret=0;
    bool termina=false;
    cin>>tamx>>tamy;
    if(tamx==0&&tamy==0){
        return false;
    }
    while(y0<tamy){
        int cuenta=1;
        int posibles;
        int finalanterior;
        int x0=0;
        cout<<"? "<<x0<<" "<<y0<<'\n';
        int inicio;
        cin>>inicio;
        cout<<"? "<<(tamx-1)<<" "<<y0<<'\n';
        int final;
        cin>>final;
        posibles=min((final-inicio+1),tamx);
        if(final!=inicio){
            cuenta++;
        }
        if(y0>0&&(finalanterior==inicio))
            ret--;
        int xf=tamx-1;
        while((x0<((xf+x0)/2))&&(cuenta<posibles)&&(final-inicio>1)){
            int xm=(xf+x0)/2;
            cout<<"? "<<xm<<" "<<y0<<'\n';
            int r;
            cin>>r;
            if(r==inicio){
                x0=xm;
            }
            if(r==final){
                xf=xm;
            }
            if(r!=final && r!=inicio ){
                x0++;
                cout<<"? "<<x0<<" "<<y0<<'\n';
                cin>>r;
                if(r!=inicio){
                    cuenta++;
                    inicio=r;
                }
                if(xf-x0>2){    
                    xf--;
                    cout<<"? "<<xf<<" "<<y0<<'\n';
                    cin>>r;
                    if(r!=final){
                        final=r;
                        if(inicio!=final)
                            cuenta++;

                    }
                }
            }

        }
        y0++;
        finalanterior=final;
        ret+=cuenta;
        
    }
    cout<<"Respuesta: "<<ret<<'\n';
    return true;
}


int main(){
    while(resuelvecaso()){
        ;
    }

    return 0;
}