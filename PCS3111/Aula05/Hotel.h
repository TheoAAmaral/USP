#ifndef HOTEL_H
#define HOTEL_H

#include "Reserva.h"
#include "Quarto.h"

class Hotel {
private:
    Quarto** quartos;
    Reserva** reservas;
    
    int maximoQuartos;
    int maximoReservas;
    int quantidadeDeReservas = 0;
    int quantidadeDeQuartos = 0;

public:
    Hotel(int maximoQuartos, int maximoReservas);
    ~Hotel();

    Quarto** getQuartos();
    Reserva** getReservas();
    int getQuantidadeReservas();
    int getQuantidadeQuartos();

    bool adicionar(Quarto* q);
    bool fazer(Reserva* r);
    bool cancelar(Reserva *r);
    void imprimir();
};

#endif  // HOTEL_H
