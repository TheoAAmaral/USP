#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include "Usuario.h"
#include <vector>

class Funcionario: public Usuario{
    public:
        Funcionario(int id, string nome);
        Funcionario(int id, string nome, vector<Registro*>* registros);
        virtual ~Funcionario();

        int getHorasTrabalhadas(int mes, int ano);
        vector<Registro*>* getRegistros();

        bool entrar(Data *d);
        bool sair(Data *d);
        bool registrarEntradaManual(Data *d);
        bool registrarSaidaManual(Data* d);
};

#endif