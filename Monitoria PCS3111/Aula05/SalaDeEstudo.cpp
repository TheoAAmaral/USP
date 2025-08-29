#include "SalaDeEstudo.h"
#include <iostream>
using namespace std;

// implemente o construtor e o destrutor

int SalaDeEstudo::getCapacidade(){
    return capacidade;
}

int SalaDeEstudo::getNumero(){
    return numero;
}

void SalaDeEstudo::imprimir(){
    cout << "Sala de Estudo | Numero: " << numero << " | Capacidade: " << capacidade << endl;
}


