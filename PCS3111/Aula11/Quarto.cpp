#include "Quarto.h"
#include <iostream>

using namespace std;

Quarto::Quarto(int numero) { this->numero = numero; }

Quarto::~Quarto() {}

int Quarto::getNumero() { return this->numero; }

void Quarto::imprimir() { cout << "\tQuarto " << this->getNumero() << endl; }
