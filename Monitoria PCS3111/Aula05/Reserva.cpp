#include "Reserva.h"
#include <iostream>
#include <cmath>
using namespace std;

// Implemente o construtor e destrutor

int Reserva::getQuantidadeDeAlunos(){
    return quantidadeDeAlunos;
}

int Reserva::getHoraInicio(){
    return horaInicio;
}

SalaDeEstudo* Reserva::getSala(){
    return sala;
}

int Reserva::calculaDuracao(){
    return ceil(2*sqrt(quantidadeDeAlunos)-1);
}

void Reserva::imprimir(){
    cout << "Reserva ("<< (this->calculaDuracao()) <<" horas):" << endl;
    sala->imprimir();
}
