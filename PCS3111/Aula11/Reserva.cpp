#include "Reserva.h"
#include <iostream>

using namespace std;

Reserva::Reserva(Quarto *q, int inicio, int fim) {
  this->q = q;
  this->inicio = inicio;
  this->fim = fim;
}

Reserva::~Reserva() {}

int Reserva::getInicio() { return this->inicio; }

int Reserva::getFim() { return this->fim; }

Quarto *Reserva::getQuarto() { return q; }

void Reserva::imprimir() {
  cout << "\tReserva de inicio " << this->getInicio() << ", fim "
       << this->getFim() << " e quarto " << this->getQuarto()->getNumero()
       << endl;
}
