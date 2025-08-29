#include <iostream>
using namespace std;

/*
A função retorna a média de capacidade das salas e atualiza o valor
minimo e máximo de capacidade passados por ponteiro e por referência, 
respectivamente. 

Caso o vetor de capacidades esteja vazio os valor retornado deve ser media = 0.0,
e o valores atualizados minimo = 2147483647 e maximo = -2147483648.
*/

double calcularEstatisticas(int capacidadeDasSalas[], int quantidade, int* minimo, int& maximo){
    int capacidadeTotal = 0;
    maximo = -1;
    for(int i = 0; i <  quantidade; i++){
        capacidadeTotal += capacidadeDasSalas[i];
        if(minimo == nullptr || *minimo > capacidadeDasSalas[i]){
            *minimo = capacidadeDasSalas[i];
        }
        if(maximo < capacidadeDasSalas[i]){
            maximo = capacidadeDasSalas[i];
        }
    }
    if(maximo == -1){
        *minimo = 2147483647;
        maximo = -2147483648;
    }
    return capacidadeTotal/quantidade;
}

int main(){
    int capacidadeDasSalas[1];
    int minimo; 
    int maximo;
    double media = calcularEstatisticas(capacidadeDasSalas, 1, &minimo, maximo);
    cout << "Capacidade minima: " << minimo << endl << "Capacidade maxima: " << maximo << endl << "Media: " << media << endl;
    return 0;
}