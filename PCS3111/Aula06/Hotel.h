#ifndef HOTEL_H
#define HOTEL_H

#include "Reserva.h"
#include "Quarto.h"

class Hotel {
private:
    Reserva** reservas;
    
    int maximoReservas;
    int quantidadeDeReservas = 0;

public:
    Hotel(int maximoReservas);
    ~Hotel();

    Reserva** getReservas();
    int getQuantidadeReservas();

    bool fazer(Reserva* r);
    bool estaDisponivel(Quarto *q, int inicio, int fim);
    void imprimir();
};

#endif  // HOTEL_H
