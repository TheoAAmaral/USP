#include "Hotel.h"
#include <iostream>

using namespace std;

Hotel::Hotel(int maximoQuartos, int maximoReservas){
    this->maximoQuartos = maximoQuartos;
    this->maximoReservas = maximoReservas;
    this->quartos = new Quarto*[this->maximoQuartos];
    this->reservas = new Reserva*[this->maximoQuartos];
}
Hotel::~Hotel(){
    delete[] quartos;
    delete[] reservas;
}

Quarto **Hotel::getQuartos()
{
    return quartos;
}

Reserva **Hotel::getReservas()
{
    return reservas;
}

int Hotel::getQuantidadeReservas()
{
    return quantidadeDeReservas;
}

int Hotel::getQuantidadeQuartos()
{
    return quantidadeDeQuartos;
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

bool Hotel::adicionar(Quarto *q)
{
    if (quantidadeDeQuartos >= maximoQuartos)
    {
        return false;
    }

    quartos[quantidadeDeQuartos] = q;
    quantidadeDeQuartos++;
    return true;
}

void Hotel::imprimir()
{
    cout << "=== HOTEL ===" << endl;

    cout << "Quartos:" << endl;
    for (int i = 0; i < quantidadeDeQuartos; i++)
    {
        quartos[i]->imprimir();
    }

    cout << "Reservas:" << endl;
    for (int j = 0; j < quantidadeDeReservas; j++)
    {
        reservas[j]->imprimir();
    }
}

bool Hotel::cancelar(Reserva *r)
{
    for(int i = 0; i < quantidadeDeReservas; i++){
        if(reservas[i] == r){
            delete reservas[i];
            for(int j = i+1; j < quantidadeDeReservas; j++){
                reservas[j-1] = reservas[j];
                reservas[j] = nullptr;
            }
            quantidadeDeReservas--;
            return true;
        }
    }
    return false;
}

