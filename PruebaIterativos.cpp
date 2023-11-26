#include <iostream>
#include<algorithm>
using namespace std;
int v[200000];
long long numParejas(int v[], int n, int k);
long long numParejas(int v[], int n, int k){
    long long ret=0;
    int a=0;
    int b=n-1;

    while(b>a){
        if (v[a]+v[b]<=k)
        {
            ret+=b-a;
            ++a; 
        }else{
            --b;
        }
        
    }

    return ret;
}
bool casoDePrueba() {
    int n;
    int k;
    cin>>n;
    cin>>k;
    //leer caso de prueba
    if (n==0&&k==0)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ
        for (int i = 0; i < n; i++)
        {
            cin>>v[i];
        }
        sort(v, v + n);
        cout<<numParejas(v, n, k)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}