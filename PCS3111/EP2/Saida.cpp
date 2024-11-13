#include "Saida.h"

Saida::Saida(Data* d): Registro(d){
    this->entrada = false;
}

Saida::Saida(Data* d, bool manual): Registro(d, manual){
    this->entrada = false;
}

Saida::~Saida(){}