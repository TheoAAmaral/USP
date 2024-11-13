#ifndef ALUNO_H
#define ALUNO_H
#include "Usuario.h"

class Aluno: public Usuario{
    private:
        static const int HORARIO_INICIO = 0;
        static int horaFim;
        static int minutoFim;
    public: 
        Aluno(int id, string nome);
        virtual ~Aluno();

        static void setHorarioFim(int hora, int minuto);
        static int getHoraFim();
        static int getMinutoFim();

        bool entrar(Data *d);
        bool sair(Data *d);
        bool registrarEntradaManual(Data *d);
        bool registrarSaidaManual(Data* d);

};

#endif