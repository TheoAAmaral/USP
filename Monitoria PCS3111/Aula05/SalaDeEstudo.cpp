#include "SalaDeEstudo.h"
#include <iostream>
using namespace std;

// implemente o construtor e o destrutor
SalaDeEstudo::SalaDeEstudo(int numero, int capacidade){
    this->numero = numero;
    this->capacidade = capacidade;
}

SalaDeEstudo::~SalaDeEstudo(){}

int SalaDeEstudo::getCapacidade(){
    return capacidade;
}

int SalaDeEstudo::getNumero(){
    return numero;
}

void SalaDeEstudo::imprimir(){
    cout << "Sala de Estudo | Numero: " << numero << " | Capacidade: " << capacidade << endl;
}