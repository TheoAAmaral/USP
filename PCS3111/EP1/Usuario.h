#ifndef USUARIO_H
#define USUARIO_H
#include "Data.h"
#include <string>
#include "Registro.h"
using namespace std;

class Usuario{
    private:
        int id;
        string nome;
        int maximo;
        Registro** registros;
        int quantidadeDeRegistros = 0;
    public:
        Usuario(int id, string nome, int maximo);
        virtual ~Usuario();

        string getNome();
        int getId();

        bool entrar(Data *d);
        bool sair(Data *d);

        bool registrarEntradaManual(Data *d);
        bool registrarSaidaManual(Data* d);

        int getHorasTrabalhadas(int mes, int ano);
        Registro** getRegistros();
        int getQuantidade();
};

#endif