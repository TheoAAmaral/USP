#include <iostream> 
using namespace std;

/*
A função deve retornar um ponteiro para o número da sala com a 
menor capacidade que suporte a quantidade de alunos pedida.

Caso nenhuma sala satisfaça essa condição, deve retornar nullptr.
*/

int* encontrarMelhorDisponivel(int capacidadeDasSalas[], int numeroDasSalas[], int quantidade, int quantidadeDeAlunos){
    int* melhor = nullptr;
    int melhorCapacidade = -1;

    for(int i = 0; i < quantidade; i++){
        if(capacidadeDasSalas[i] >= quantidadeDeAlunos && (melhor == nullptr || capacidadeDasSalas[i] < melhorCapacidade ) ){
            melhorCapacidade = capacidadeDasSalas[i];
            melhor = &numeroDasSalas[i];
        }
    }

    return melhor;
}