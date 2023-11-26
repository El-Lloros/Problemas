#include <iostream>
using namespace std;
int sumadigitos(int n);

int sumadigitos(int n){
    int sum;
    //Caso Base
    if(n<10){
        cout<<n;
        return n;
    }

    sum=sumadigitos(n/10);
    cout<<" + "<<n%10;
    return sum+=n%10;
}
bool casoDePrueba() {
    int n;
    cin>>n;

    if (n<0)
        return false;
    else {
        cout<<" = "<<sumadigitos(n)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}