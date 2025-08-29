#include <iostream>
#include "Reserva.h"
#include "Biblioteca.h"
using namespace std;

void teste1 () {
    Reserva* r1 = new Reserva;
    r1->setHoraDeInicio(18);
    r1->setNumeroDaSala(25);
    r1->setQuantidadeDeAlunos(2);
    Reserva* r2 = new Reserva;
    r2->setHoraDeInicio(7);
    r2->setNumeroDaSala(64);
    r2->setQuantidadeDeAlunos(5);
    r1->imprimir();
    r2->imprimir();
}

void teste2 () {
    Reserva* r1 = new Reserva;
    r1->setHoraDeInicio(18);
    r1->setNumeroDaSala(25);
    r1->setQuantidadeDeAlunos(2);
    Reserva* r2 = new Reserva;
    r2->setHoraDeInicio(7);
    r2->setNumeroDaSala(64);
    r2->setQuantidadeDeAlunos(5);
    Biblioteca* b1 = new Biblioteca;
    b1->fazer(r1);
    b1->fazer(r2);
    b1->imprimir();
}
