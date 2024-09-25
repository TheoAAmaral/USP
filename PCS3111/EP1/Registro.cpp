#include "Registro.h"
#include <iostream>

Registro::Registro(Data* d, bool entrada, bool manual):
data(d), entrada(entrada), manual(manual){}

Registro::~Registro(){}

Data* Registro::getData(){
    return data;
}

bool Registro::isEntrada(){
    return entrada;
}

bool Registro::isManual(){
    return manual;
}