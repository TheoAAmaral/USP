#include <iostream>
#include <string>
#include "teste.h"

using namespace std;

void teste1() {
    Reserva *quarto31 = new Reserva;
    quarto31->setQuarto(31);
    quarto31->setInicio(1);
    quarto31->setFim(6);

    quarto31->imprimir();
}

void teste2() {
    Reserva *quarto22 = new Reserva;
    Reserva *quarto25 = new Reserva;

    quarto22->setFim(8);
    quarto22->setInicio(1);
    quarto22->setQuarto(22);

    quarto25->setFim(9);
    quarto25->setInicio(5);
    quarto25->setQuarto(25);

    Hotel *hotel = new Hotel;

    hotel->adicionar(quarto22);
    hotel->adicionar(quarto25);
    hotel->imprimir();  
}