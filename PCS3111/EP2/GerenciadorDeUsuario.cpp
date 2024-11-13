#include "GerenciadorDeUsuario.h"
#include <stdexcept>
using namespace std;

GerenciadorDeUsuario::GerenciadorDeUsuario()
{
    this->usuarios = new vector<Usuario *>;
}

GerenciadorDeUsuario::GerenciadorDeUsuario(vector<Usuario *> *usuarios)
{
    this->usuarios = new vector<Usuario *>;
    for (int i = 0; i < usuarios->size(); i++)
    {
        this->usuarios->push_back((*usuarios)[i]);
    }
}

GerenciadorDeUsuario::~GerenciadorDeUsuario()
{
    for (int i = 0; i < usuarios->size(); i++)
    {
        delete (*usuarios)[i];
    }
    delete usuarios;
}

void GerenciadorDeUsuario::adicionar(Usuario *u)
{
    for (int i = 0; i < usuarios->size(); i++)
    { // Verifica se o usuario ja nao esta na lista
        if (u->getId() == (*usuarios)[i]->getId())
        {
            throw new invalid_argument("Usuario ja esta registrado");
        }
    }
    // coloca o usuario no primeiro item do vector
    usuarios->push_back(u);
}

Usuario *GerenciadorDeUsuario::getUsuario(int id)
{
    for (int k = 0; k < usuarios->size(); k++)
    { // vasculha pelo ID do usuariono vetor
        if ((*usuarios)[k]->getId() == id)
        {
            return (*usuarios)[k]; // retorna o usuario do vector
        }
    }
    return nullptr;
}

vector<Usuario *> *GerenciadorDeUsuario::getUsuarios()
{
    return usuarios; // retorna o ponteiro para o vector
}