#include "Catraca.h"
#include "GerenciadorDeUsuario.h"

Catraca::Catraca(GerenciadorDeUsuario* g):gerenciador(g){}

Catraca::~Catraca(){}

bool Catraca::entrar(int id, Data* d){
    Usuario *usuario = nullptr;
    usuario = gerenciador->getUsuario(id);
    if(usuario == nullptr)
        return false;
    else return usuario->entrar(d);
}

bool Catraca::sair(int id, Data* d){
    Usuario *usuario = nullptr;
    usuario = gerenciador->getUsuario(id);
    if(usuario == nullptr)
        return false;
    else return usuario->sair(d);
}