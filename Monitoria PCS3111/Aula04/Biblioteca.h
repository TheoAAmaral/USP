/*
 * Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 */

#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#define MAXIMO_DE_RESERVAS 10
#include "Reserva.h"

class Biblioteca {
private:
    Reserva** reservas = new Reserva*[MAXIMO_DE_RESERVAS];
    int quantidade = 0;
public:
    bool fazer(Reserva* reserva);
    Reserva* reservaATerminar();
    Reserva* getReserva(int posicao);
    void imprimir();
};

#endif