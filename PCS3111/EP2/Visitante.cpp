#include "Visitante.h"
#include "Registro.h"
#include "Entrada.h"
#include "Saida.h"
#include <stdexcept>

Visitante::Visitante(int id, string nome, Data* inicio, Data* fim):Usuario(id, nome){
    if(inicio == nullptr || fim == nullptr || fim->diferenca(inicio) < 0)
        throw new logic_error("Data de inicio e/ou fim invalidas");
    this->inicio = inicio;
    this->fim = fim;
}

Visitante::~Visitante(){
    delete inicio;
    delete fim;
}

Data* Visitante::getDataInicio(){
    return inicio;
}

Data* Visitante::getDataFim(){
    return fim;
}

bool Visitante::entrar(Data* d){
    if(d->diferenca(inicio) < 0 || fim->diferenca(d) < 0)
        return false;
    registros->push_back(new Entrada(d));
    return true;
}

bool Visitante::sair(Data* d){
    if(d->diferenca(inicio) < 0 || fim->diferenca(d) < 0)
        return false;
    registros->push_back(new Saida(d));
    return true;
}

bool Visitante::registrarEntradaManual(Data* d){
    return false;
}

bool Visitante::registrarSaidaManual(Data* d){
    return false;
}
