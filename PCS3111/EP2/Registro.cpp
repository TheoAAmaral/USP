#include "Registro.h"
#include <stdexcept>
using namespace std;

Registro::Registro(Data *d){
    if(d == nullptr)
        throw new invalid_argument("Data invalida");
    this->data = d;
    this->manual = false;
}

Registro::Registro(Data *d, bool manual){
    if(d == nullptr)
        throw new invalid_argument("Data invalida");    
    this->data = d;
    this->manual = manual;
}

Registro::~Registro(){}

bool Registro::isManual(){
    return manual;
}

Data* Registro::getData(){
    return data;
}