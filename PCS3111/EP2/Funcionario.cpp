#include "Funcionario.h"
#include "Registro.h"
#include "Entrada.h"
#include "Saida.h"

Funcionario::Funcionario(int id, string nome):Usuario(id, nome){
    this->registros = new vector<Registro*>;
}

Funcionario::Funcionario(int id, string nome, vector<Registro*>* registros): Usuario(id, nome){
    this->registros = registros;
}

Funcionario::~Funcionario(){
    for(int i = 0; i < registros->size(); i++){
        delete (*registros)[i];
    }
    delete registros;
}

bool Funcionario::entrar(Data *d){
    if(registros->size() > 0){
        if(dynamic_cast<Entrada*> ((*registros)[registros->size()-1]) != nullptr || d->diferenca((*registros)[registros->size() - 1]->getData()) < 0)
            return false;
    }
    registros->push_back(new Entrada(d, false));
    return true;
}

bool Funcionario::sair(Data *d){
    if(registros->size() > 0){
        if(dynamic_cast<Saida*> ((*registros)[registros->size()-1]) != nullptr || d->diferenca((*registros)[registros->size() - 1]->getData()) < 0)
            return false;
    }
    registros->push_back(new Saida(d, false));
    return true;
}

bool Funcionario::registrarEntradaManual(Data *d){
if(registros->size() > 0){
        if(dynamic_cast<Entrada*> ((*registros)[registros->size()-1]) != nullptr || d->diferenca((*registros)[registros->size() - 1]->getData()) < 0)
            return false;
    }
    registros->push_back(new Entrada(d, true));
    return true;
}
bool Funcionario::registrarSaidaManual(Data* d){
    if(registros->size() > 0){
        if(dynamic_cast<Saida*> ((*registros)[registros->size()-1]) != nullptr || d->diferenca((*registros)[registros->size() - 1]->getData()) < 0)
            return false;
    }
    registros->push_back(new Saida(d, true));
    return true;
}

vector<Registro*>* Funcionario::getRegistros(){
    return registros;
}

int Funcionario::getHorasTrabalhadas(int mes, int ano){
    int horas = 0;
    for(int i = dynamic_cast<Entrada*>((*registros)[0]) == nullptr; i < registros->size(); i++){
        if((*registros)[i]->getData()->getMes() == mes && (*registros)[i]->getData()->getAno() == ano && i < registros->size() - 1){
            horas += (*registros)[i+1]->getData()->diferenca((*registros)[i]->getData());
        }
        i++;
    }
    return horas/3600;
}