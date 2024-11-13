#ifndef USUARIO_H
#define USUARIO_H
#include "Data.h"
#include <string>
#include <vector>
#include "Registro.h"
using namespace std;

class Usuario{
    protected:
        int id;
        string nome;
        vector<Registro*>* registros;
    public:
        Usuario(int id, string nome);
        virtual ~Usuario();

        string getNome();
        int getId();

        virtual bool entrar(Data *d) = 0;
        virtual bool sair(Data *d) = 0;
        virtual bool registrarEntradaManual(Data *d) = 0;
        virtual bool registrarSaidaManual(Data* d) = 0;
};

#endif