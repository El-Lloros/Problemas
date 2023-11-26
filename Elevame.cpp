#include <iostream>
using namespace std;
int k=31543;
int elevame(int x,int n){
    int ret;
    //caso base
    if(n==0)
        return 1;
    ret=(elevame(x,n/2))%k;
    ret=(ret*ret)%k;
    if(n%2!=0)
        ret=((ret%k)*(x%k))%k;
    return ret;
}
bool casoDePrueba() {

    //leer caso de prueba
    int n,x;
    cin>>x;
    cin>>n;
    if (x==0 && n==0)
        return false;
    else {
        cout<<elevame(x,n)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}