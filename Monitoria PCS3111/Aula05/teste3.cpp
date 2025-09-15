// faça os includes necessários
#include "Biblioteca.h"

void teste3(){
    Biblioteca *b1 = new Biblioteca(5);
    SalaDeEstudo *s0 = new SalaDeEstudo(0, 50);
    SalaDeEstudo *s1 = new SalaDeEstudo(1, 50);
    SalaDeEstudo *s2 = new SalaDeEstudo(2, 50);
    SalaDeEstudo *s3 = new SalaDeEstudo(3, 50);
    SalaDeEstudo *s4 = new SalaDeEstudo(4, 50);

    b1->adicionarSala(s0);
    b1->adicionarSala(s1);
    b1->adicionarSala(s2);
    b1->adicionarSala(s3);
    b1->adicionarSala(s4);

    Reserva *r1 = new Reserva(5, 1, s0);
    Reserva *r2 = new Reserva(10, 1, s1);
    Reserva *r3 = new Reserva(49, 1, s2);
    Reserva *r4 = new Reserva(2, 1, s3);
    Reserva *r5 = new Reserva(7, 1, s4);

    b1->adicionarReserva(r1);
    b1->adicionarReserva(r2);
    b1->adicionarReserva(r3);
    b1->adicionarReserva(r4);
    b1->adicionarReserva(r5);

    b1->terminarReservas(5);
    b1->imprimirReservas();
    delete b1;
}