#include "Hotel.h"

#include <iostream>

Hotel::Hotel(int maximoReservas)
{
    this->maximoReservas = maximoReservas;
    reservas = new Reserva *[maximoReservas];
}

Hotel::~Hotel(){};

Reserva **Hotel::getReservas()
{
    return reservas;
}

int Hotel::getQuantidadeReservas()
{
    return quantidadeDeReservas;
}


bool Hotel::fazer(Reserva *r)
{
    if (quantidadeDeReservas >= maximoReservas)
    {
        return false;
    }

    reservas[quantidadeDeReservas] = r;
    quantidadeDeReservas++;
    return true;
}

void Hotel::imprimir()
{
    cout << "=== HOTEL ===" << endl;

    cout << "Reservas:" << endl;
    for (int j = 0; j < quantidadeDeReservas; j++)
    {
        reservas[j]->imprimir();
    }
}

bool Hotel::estaDisponivel(Quarto *q, int inicio, int fim)
{
    for(int i = 0; i < this->quantidadeDeReservas; i++){
        if(this->reservas[i]->getQuarto() == q && (
            (this->reservas[i]->getInicio() <= inicio && inicio < this->reservas[i]->getFim()) || 
            (this->reservas[i]->getInicio() < fim && this->reservas[i]->getFim() >= fim))){
            return false;
        }
    }
    return true;
}