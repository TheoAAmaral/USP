#include "Entrada.h"

Entrada::Entrada(Data* d): Registro(d){
    this->entrada = true;
}

Entrada::Entrada(Data* d, bool manual): Registro(d, manual){
    this->entrada = true;
}

Entrada::~Entrada(){}