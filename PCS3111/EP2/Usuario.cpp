#include "Usuario.h"
#include <string>

Usuario::Usuario(int id, string nome){
    this->id = id;
    this->nome = nome;
}

Usuario::~Usuario(){}

int Usuario::getId(){
    return id;
}

string Usuario::getNome(){
    return nome;
}