#include <iostream>
using namespace std;
bool resuelvecaso();

bool resuelvecaso(){
    int a,b;
    cin>>a>>b;
    if(a==0&&b==0){
        return false;
    }
    while(a<b){
        int m=(a+b)/2;
        cout<<"? "<<m<<'\n';
        string r;
        cin>>r;
        if(r=="<="){
            b=m;
        }else{
            a=m+1;
        }
    }
    cout<<"Respuesta: "<<a<<'\n';
    return true;
}
int main(){
    while(resuelvecaso()){
        ;
    }
    return 0;
}