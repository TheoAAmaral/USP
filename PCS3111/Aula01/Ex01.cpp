#include <iostream>
 
using namespace std;
 
int potencia(int a, int b){
  int resultado = a;
  for (int i = 0; i < b-1; i++){
    resultado = resultado * a;
  }
 
  return resultado;
}
 
int main() {
    cout << potencia(2, 3);
    return 0;
}