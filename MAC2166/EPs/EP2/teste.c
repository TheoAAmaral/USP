#include <stdio.h>

double Log2(double z, double eps){
  double resultado = 0;
  double potenciado;
  double adicionar;
  double fracao = (z-1)/(z+1);
  double doissobreln2 = 2.0/0.69314718056;
  int i = 1;
  int j;

  for(i=1; i<100000000; i++){
    if(i%2!=0){
      potenciado = fracao;
      for(j=2; j<=i; j++){
        potenciado = potenciado*fracao;
      }
      adicionar = (1.0/i)*potenciado;
      resultado = resultado + adicionar;    
      if(potenciado<eps && potenciado>-eps) break;
    }
  }
  resultado = doissobreln2*resultado;
  return resultado;
}

int main(){
    printf("%g\n", Log2(0.0156249755860, 1e-4));
    return 0;
}