#include <iostream>
using namespace std;
int k=46337;
void multiplicarMatriz(long long int F[2][2], long long int M[2][2])
{
  int x =  (F[0][0]*M[0][0] + F[0][1]*M[1][0])%k;
  int y =  (F[0][0]*M[0][1] + F[0][1]*M[1][1])%k;
  int z =  (F[1][0]*M[0][0] + F[1][1]*M[1][0])%k;
  int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%k;

  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void potenciaMatriz(long long int F[2][2], int n)
{
  if( n == 0 || n == 1) return;
  long long int M[2][2] = {{1,1},{1,0}};
  potenciaMatriz(F, n/2);
  multiplicarMatriz(F, F);

  if (n%2 != 0)
     multiplicarMatriz(F, M);
}
int fib(long long int n)
{
  long long int F[2][2] = {{1,1},{1,0}};
  if (n == 0) return 0;
  potenciaMatriz(F, n-1);
  return F[0][0];
}

bool casoDePrueba() {

    //leer caso de prueba
    long long int n;
    cin>>n;
    if ( n==0)
        return false;
    else {
        cout<<fib(n)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}