#include "Reserva.h"
#include "Hotel.h"



void teste1() {
    Quarto *quarto23 = new Quarto(23, 3, 2);
    quarto23->imprimir();
    Reserva *reserva = new Reserva(quarto23, 2, 8);
    reserva->imprimir();
    delete reserva;
    delete quarto23;
}

void teste2() {
    Hotel *hotel = new Hotel(10, 20);
    Quarto *q25 = new Quarto(25, 4, 2);
    hotel->adicionar(q25);
    Reserva *q25_1 = new Reserva(q25, 2, 30);
    hotel->fazer(q25_1);
    Quarto *q32 = new Quarto(32, 2, 1);
    hotel->adicionar(q32);
    Reserva *q32_1 = new Reserva(q32, 10, 12);
    hotel->fazer(q32_1);
    Reserva *q32_2 = new Reserva(q32, 8, 9);
    hotel->fazer(q32_2);
    hotel->cancelar(q32_1);
    hotel->imprimir();
    delete hotel;
}