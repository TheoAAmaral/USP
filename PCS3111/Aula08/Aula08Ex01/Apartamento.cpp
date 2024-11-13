// Faça os includes necessários
#include "Apartamento.h"
#include <iostream>
using namespace std;

Apartamento::Apartamento(int numero, double area): Acomodacao(numero) {
    this->area = area;
}

Apartamento::~Apartamento() {

}

double Apartamento::getArea() {
    return area;
}

double Apartamento::getPrecoDiaria(){
    return 200 + (1.50 * area);
}

void Apartamento::imprimir(){
    cout << "Apartamento " << getNumero() << ": " << area << " metros quadrados - diaria custa " << getPrecoDiaria() << " reais" << endl;
}