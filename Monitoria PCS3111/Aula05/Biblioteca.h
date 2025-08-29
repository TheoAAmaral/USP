#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "SalaDeEstudo.h"
#include "Reserva.h"

class Biblioteca {
private:
    SalaDeEstudo** salas;
    Reserva** reservas;
    int quantidadeDeSalas, quantidadeDeReservas, maximo;

public:
    Biblioteca(int maximo);
    ~Biblioteca();

    SalaDeEstudo** getSalasDeEstudo();
    Reserva** getReservas();

    int getQuantidadeDeSalas();
    int getQuantidadeDeReservas();
    int getMaximo();

    bool adicionarReserva(Reserva* r);
    bool adicionarSala(SalaDeEstudo* s);

    void imprimirReservas();

    int terminarReservas(int horaAtual);
};

#endif