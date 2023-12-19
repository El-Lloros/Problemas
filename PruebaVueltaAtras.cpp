
#include <iostream>
using namespace std;
bool nocome(int t,int r,int solParcial[9],bool asignacionParcial[9],int ultimaCol,int ultimaY){
   for(int i=0;i<ultimaCol;i++){
      if(solParcial[i]==solParcial[ultimaCol]){
        return false;
      }
      if(abs(i-ultimaCol)==abs(solParcial[i]-solParcial[ultimaCol])&&((asignacionParcial[i])||(asignacionParcial[ultimaCol]))){
        return false;
      }
   }
    return true;
}
long long calcular(int t,int r, int solParcial[9], bool asignacionParcial[9],int tparcial, int rparcial,int k)
{
    if(k==(t+r)){
        return 1;
    }
    long long ret=0;
   
    for(int y=0;y<t+r;y++){
        //ponemos reina
        solParcial[k]=y;
        asignacionParcial[k]=true;
        if(nocome(t,r,solParcial,asignacionParcial,k,y)&&(rparcial+1<=r)){
            ret+=calcular(t,r,solParcial,asignacionParcial,tparcial,rparcial+1,k+1);
        }
        
        
        //ponemos torre
        asignacionParcial[k]=false;
        if(nocome(t,r,solParcial,asignacionParcial,k,y)&&(tparcial+1<=t)){
            ret+=calcular(t,r,solParcial,asignacionParcial,tparcial+1,rparcial,k+1);
        }
        
    }
    return ret;
    
    


}

bool casoDePrueba() {

    int t,r;
    cin>>t;
    cin>>r;
    int dummy1[9];
    bool dummy2[9];
    
    

    if (t==0&&r==0)
        return false;
    else {
        cout<< calcular(t,r,dummy1,dummy2,0,0,0)<<'\n';
        return true;
     }

} // casoDePrueba

int main() {

    while(casoDePrueba()) {
    }
  
    return 0;
}
