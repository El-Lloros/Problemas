#include <iostream>

using namespace std;
int viajes(int n, bool &pe);

int viajes(int n, bool &pe) {
   //caso base
   if(n==0){
    return 0;
   }
    if(pe){
        pe=false;
        return 1+viajes(n-1,pe);
    }else{
        if(n%2==0){
            pe=true;
            return 1+viajes(n-2,pe);

        }else{
            pe=true;
            return 1+viajes(n-1,pe);
        }


    }
}

int main() {
    int n;
    cin >> n ;
    while ((n != 0)) {
        bool pe=true;
        int cont = viajes(n,pe);
        cout << cont << '\n';
        cin >> n;
    }

    return 0;
}
