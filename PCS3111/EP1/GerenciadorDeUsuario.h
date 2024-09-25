#ifndef GERENCIADORDEUSUARIO_H
#define GERENCIADORDEUSUARIO_H
#include "Usuario.h"

class GerenciadorDeUsuario{
    private:
        int MaximoUsuarios;
        int Quantidade = 0;//O ultimo indice que pode estar preenchido por um usuario
        Usuario** U;

    public:
        GerenciadorDeUsuario(int maximo);
        virtual ~GerenciadorDeUsuario();
        bool adicionar(Usuario* u);
        Usuario* getUsuario(int id);
        Usuario** getUsuarios();
        int getQuantidade();
};

#endif