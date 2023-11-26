#include <iostream>
using namespace std;
int trocea(int h,int c);

int trocea(int h, int c) {
    if (c <= h || c <= 2 * h) {
        return 0;
    } else {
        if (c / 3 > h) {
            return 1 + trocea(h, c / 3);
        } else {
            return 1 + trocea(h, c - (c / 3));
        }
    }
}
bool casoDePrueba() {

    //leer caso de prueba
    int h;
    int c;
    int trozos =0;
    
    cin >> h>>c;
    if (h==0&&c==0)
        return false;
    else {
        // CÓDIGO PRINCIPAL AQUÍ
        
        cout<<trocea(h,c)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}