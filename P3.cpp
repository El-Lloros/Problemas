#include <iostream>
using namespace std;
bool resuelvecaso();
bool resuelvecaso(){
    int x,y;
    bool xtrue=false;
    bool ytrue=false;
    int x0=0;
    int y0=0;
    cin>>x>>y;
    if(x==0&&y==0){
        return false;
    }
    while(xtrue==false&&ytrue==false){
        int xm=(x+x0)/2;
        int ym=(y+y0)/2;

        cout<<"? "<<xm<<" "<<ym<<'\n';
        int r;
        cin>>r;
        if(r==0){
            x0=xm+1;
            y0=ym+1;

        }else{
            x0=0;
            y0=0;
            while(x0<x){
                int xm=(x+x0)/2;
                cout<<"? "<<xm<<" "<<ym<<'\n';
                cin>>r;
                if(r==0){
                   x0=xm+1;
                }else{
                    x=xm;
                }

            }
            xtrue=true;
            while(y0<y){
                int ym=(y+y0)/2;
                cout<<"? "<<x<<" "<<ym<<'\n';
                cin>>r;
                if(r==0){
                   y0=ym+1;
                }else{
                    y=ym;
                }

            }
            ytrue=true;
            
        }
    }
    cout<<"Respuesta: "<<x<<" "<<y<<'\n';
    return true;

    return true;
}
int main(){
    while(resuelvecaso()){
        ;
    }

    return 0;
}