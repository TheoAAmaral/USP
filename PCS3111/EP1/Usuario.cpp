#include "Usuario.h"

Usuario::Usuario(int id, string nome, int maximo){
    this->id = id;
    this->nome = nome;
    this->maximo = maximo;
    this->registros = new Registro*[maximo];
}

Usuario::~Usuario(){
    for(int i = 0; i < maximo; i++){
        delete registros[i];
    }
    delete[] registros;
}

string Usuario::getNome(){
    return nome;
}
int Usuario::getId(){
    return id;
}

bool Usuario::entrar(Data *d){
    if(quantidadeDeRegistros > 0){
        if(registros[quantidadeDeRegistros-1]->isEntrada() || d->diferenca(registros[quantidadeDeRegistros-1]->getData()) < 0)
            return false;
        if(quantidadeDeRegistros == maximo)
            return false;
    }
    registros[quantidadeDeRegistros] = new Registro(d, true, false);
    quantidadeDeRegistros++;
    return true;
}

bool Usuario::sair(Data *d){
    if(quantidadeDeRegistros > 0){
        if(!registros[quantidadeDeRegistros-1]->isEntrada() || d->diferenca(registros[quantidadeDeRegistros-1]->getData()) < 0)
            return false;
        if(quantidadeDeRegistros == maximo)
            return false;
    }
    registros[quantidadeDeRegistros] = new Registro(d, false, false);
    quantidadeDeRegistros++;
    return true;
}

bool Usuario::registrarEntradaManual(Data *d){
    if(quantidadeDeRegistros > 0){
        if(registros[quantidadeDeRegistros-1]->isEntrada() || d->diferenca(registros[quantidadeDeRegistros-1]->getData()) < 0)
            return false;
        if(quantidadeDeRegistros == maximo)
            return false;
    }
    registros[quantidadeDeRegistros] = new Registro(d, true, true);
    quantidadeDeRegistros++;
    return true;
}
bool Usuario::registrarSaidaManual(Data* d){
    if(quantidadeDeRegistros > 0){
        if(!registros[quantidadeDeRegistros-1]->isEntrada() || d->diferenca(registros[quantidadeDeRegistros-1]->getData()) < 0)
            return false;
        if(quantidadeDeRegistros == maximo)
            return false;
    }
    registros[quantidadeDeRegistros] = new Registro(d, false, true);
    quantidadeDeRegistros++;
    return true;
}

int Usuario::getHorasTrabalhadas(int mes, int ano){
    int horas = 0;
    for(int i = !registros[0]->isEntrada(); i < quantidadeDeRegistros; i++){
        if(registros[i]->getData()->getMes() == mes && registros[i]->getData()->getAno() == ano && i < quantidadeDeRegistros - 1){
            horas += registros[i+1]->getData()->diferenca(registros[i]->getData());
        }
        i++;
    }
    return horas/3600;
}
Registro** Usuario::getRegistros(){
    return registros;
}
int Usuario::getQuantidade(){
    return quantidadeDeRegistros;
}