// faça os includes necessários
#include "Reserva.h"

void teste2(){
    SalaDeEstudo *s1 = new SalaDeEstudo(1, 30);
    Reserva *r1 = new Reserva(24, 0, s1);
    r1->imprimir();
    delete r1;
    delete s1;
}