#include "Quarto.h"
#include <iostream>

using namespace std;

Quarto::Quarto(int numero, int numeroDeCamas)
    : numero(numero), numeroDeCamas(numeroDeCamas) {}

void Quarto::imprimir() {
    cout << "Quarto " << numero << ": " << numeroDeCamas << " cama(s)" << endl;
}

int Quarto::getNumero() { return numero; }

int Quarto::getNumeroDeCamas() { return numeroDeCamas; }
