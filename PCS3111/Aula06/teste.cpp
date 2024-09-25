#include "Quarto.h"
#include "Reserva.h"
#include "Hotel.h"
#include "PacoteDeFinalDeSemana.h"

void teste1() {
    Quarto *q25 = new Quarto(25, 3, 2);
    Reserva *q25_1 = new Reserva(q25, 2, 4);
    Reserva *q25_2 = new PacoteDeFinalDeSemana(q25, 5, true);
    q25_1->imprimir();
    q25_2->imprimir();
}

void teste2() {
    Quarto *q25 = new Quarto(25, 3, 2);
    Reserva *q25_1 = new Reserva(q25, 2, 4);
    Reserva *q25_2 = new PacoteDeFinalDeSemana(q25, 5, true);
    q25_1->imprimir();
    q25_2->imprimir();
    Hotel *hotel = new Hotel(10);
    hotel->fazer(q25_1);
    hotel->fazer(q25_2);
    Quarto *q32 = new Quarto(32, 4, 2);
    Reserva *q32_1 = new PacoteDeFinalDeSemana(q32, 7, true);
    hotel->fazer(q32_1);
    hotel->imprimir();

    delete hotel;
    delete q32_1;
    delete q25_2;
    delete q25_1;
    delete q32;
    delete q25;
}