/*
 * Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 */
#ifndef HOTEL_H
#define HOTEL_H
#include "Reserva.h"
#define MAXIMO_DE_RESERVAS 10

class Hotel {
    Reserva *reservas[MAXIMO_DE_RESERVAS];
    int numeroDeReservas;
public:
    bool adicionar(Reserva* reserva);

    bool estaDisponivel(int quarto,int inicio, int fim);

    Reserva* getReserva(int i);
    
    void imprimir();
};
#endif