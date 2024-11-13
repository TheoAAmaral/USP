// Faça os includes necessários
#include "Apartamento.h"
#include <iostream>
using namespace std;

double Apartamento::precoBase = 0;

Apartamento::Apartamento(int numero, double area): Acomodacao(numero) {
    this->area = area;
}

Apartamento::~Apartamento() {

}

double Apartamento::getArea() {
    return area;
}

double Apartamento::getPrecoDiaria(){
    return precoBase + (1.5*area);
}

void Apartamento::imprimir(){
    cout << "Apartamento " << getNumero() << ": " << area << " metros quadrados - diaria custa " << getPrecoDiaria() << " reais" << endl;
}

double Apartamento::getPrecoBase(){
    return Apartamento::precoBase;
}

void Apartamento::setPrecoBase(double precoBase){
    Apartamento::precoBase = precoBase;
}