#include "GerenciadorDeUsuario.h"

GerenciadorDeUsuario::GerenciadorDeUsuario(int maximo){
    this -> MaximoUsuarios = maximo;
    U = new Usuario*[MaximoUsuarios];
}

GerenciadorDeUsuario::~GerenciadorDeUsuario(){
    delete[] U;
}

bool GerenciadorDeUsuario::adicionar(Usuario* u){
    if(Quantidade == MaximoUsuarios){//verifica se o vetor ja nao esta cheio
        return false;
    }
    for(int i=0;i < Quantidade;i++){//Verifica se o usuario ja nao esta na lista
        if(u->getId() == U[i]->getId()){
            return false;
        }
    }
    //coloca o usuario no ultimo item do vetor
    U[Quantidade] = u;
    Quantidade++;
    return true;
}

Usuario *GerenciadorDeUsuario::getUsuario(int id){
    for(int k=0;k < Quantidade; k++){
        if(U[k] -> getId() == id){
            return U[k];
        }
    }
    return nullptr;
}

Usuario** GerenciadorDeUsuario::getUsuarios(){
    return U;
}

int GerenciadorDeUsuario::getQuantidade(){
    return Quantidade;
}