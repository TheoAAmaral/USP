#ifndef RESERVA_H
#define RESERVA_H

#include "SalaDeEstudo.h"

class Reserva {
private:
    int quantidadeDeAlunos;
    int horaInicio;
    SalaDeEstudo* sala;
public:
    Reserva(int quantidadeDeAlunos, int horaInicio, SalaDeEstudo* sala);
    ~Reserva();
    int getQuantidadeDeAlunos();
    int getHoraInicio();
    SalaDeEstudo* getSala();
    int calculaDuracao();
    void imprimir();
};

#endif