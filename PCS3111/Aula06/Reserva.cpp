#include "Reserva.h"

#include <iostream>

using namespace std;

Reserva::Reserva(Quarto *quarto, int inicio, int fim)
{
    this->quarto = quarto;
    this->inicio = inicio;
    this->fim = fim;
    
    int diarias = fim - inicio;
    precoTotal = quarto->getPrecoDiaria() * diarias;
}

Reserva::~Reserva()
{
    cout << "Reserva para o quarto " << quarto->getNumeroDoQuarto() << " destruida" << endl;
}

Quarto *Reserva::getQuarto()
{
    return quarto;
}

int Reserva::getInicio()
{
    return inicio;
}

int Reserva::getFim()
{
    return fim;
}

double Reserva::calcularPreco()
{
    return precoTotal;
}

bool Reserva::temCafe()
{
    return this->cafe;
}

void Reserva::imprimir()
{
    cout << "Reserva (" << fim - inicio << " dias):" << endl;
    quarto->imprimir();
    cout << "Preco total: " << calcularPreco();
    cout << endl;
}