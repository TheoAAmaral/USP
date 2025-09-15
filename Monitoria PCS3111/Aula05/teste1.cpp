#include "SalaDeEstudo.h"

void teste1(){
    SalaDeEstudo *s1 = new SalaDeEstudo(1, 30);
    s1->imprimir();
    delete s1;
}