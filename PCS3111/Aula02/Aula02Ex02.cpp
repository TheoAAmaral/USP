#include <iostream>
#include <string>
using namespace std;

bool obterPrimeiraDisponibilidade(int inicios[], int fins[], int quantidade, int duracao, int dataMaxima, int* inicio, int& fim){
    if(quantidade == 0){
        *inicio = 1;
        fim = 1 + duracao;
        return true;
    }
    if(inicios[0] >= 1 + duracao && 1 + duracao <= dataMaxima){
        *inicio = 1;
        fim = duracao + 1;
        return true;
    }
    for(int i = 0; i < quantidade - 1; i++){
        if(fins[i] + duracao <= inicios[i + 1] && fins[i] + duracao <= dataMaxima){
            *inicio = fins[i];
            fim = fins[i] + duracao;
            return true;
        }
    }
    if(fins[quantidade-1] + duracao <= dataMaxima){
        *inicio = fins[quantidade-1];
        fim = fins[quantidade-1] + duracao;
        return true;
    }


    *inicio = 0;
    fim = 0;
    return false;
}

/*
int main(){
    int inicios[] = {1, 5, 12};
    int fins[] = {5, 10, 15};
    int quantidade = 3;
    int duracao = 10;
    int dataMaxima = 30;
    int inicio, fim;

    bool achou = obterPrimeiraDisponibilidade(inicios, fins, quantidade, duracao, dataMaxima, &inicio, fim);

    cout << "Achou: " << achou << endl;
    cout << "Inicio: " << inicio << endl << "Fim: " << fim << endl;
    
    return 0;
}
*/
