#include "Quarto.h"
#include <stdexcept>
#include <iostream>
#include "SemEspaco.h"
#include "Reserva.h"
using namespace std;

void teste1() {
    try {
        Quarto* q1 = new Quarto(0, 1);
    } catch (invalid_argument *e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
    try{
        Quarto* q2 = new Quarto(2, -1);
    } catch (invalid_argument *e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
}

void teste2() {
        Quarto* q1 = new Quarto(1, 2);
        q1->imprimir();
    try{
        q1->getPrecoDiaria(5);
    } catch(SemEspaco *e){
        cout << "Erro: " << e->what() << endl;
        delete e;
    }
    delete q1;
}

void teste3() {
    Quarto* q1 = new Quarto(1, 1);
    try{
        Reserva* r1 = new Reserva(q1, 2, 1, 2);
    } catch(invalid_argument *e){
        cout << e->what() << endl;
        delete e;
    }
    try{
        Reserva* r2 = new Reserva(q1, 0, 1, 0);
    } catch(invalid_argument *e){
        cout << e->what() << endl;
        delete e;
    }
    try{
        Reserva* r3 = new Reserva(q1, 0, 1, 3);
    } catch(invalid_argument *e){
        cout << e->what() << endl;
        delete e;
    }
    Reserva* r4 = new Reserva(q1, 0, 1, 2);
    r4->imprimir();
    delete r4;
    delete q1;
}
