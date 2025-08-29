/*
 * Coloque a implementação da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessários para a classe.
 */
#include "Reserva.h"
#include <cmath>
#include <iostream>
using namespace std;

void Reserva::setHoraDeInicio(int horaDeInicio){
    this->horaDeInicio = horaDeInicio;
    return;
}

void Reserva::setNumeroDaSala(int numeroDaSala){
    this->numeroDaSala = numeroDaSala;
    return;
}

void Reserva::setQuantidadeDeAlunos(int quantidadeDeAlunos){
    this->quantidadeDeAlunos = quantidadeDeAlunos;
    return;
}

int Reserva::getHoraDeInicio(){
    return horaDeInicio;
}

int Reserva::getNumeroDaSala(){
    return numeroDaSala;
}

int Reserva::getQuantidadeDeAlunos(){
    return quantidadeDeAlunos;
}

int Reserva::calcularDuracao(){
    return (int) floor(log(2*quantidadeDeAlunos + 1));
}

void Reserva::imprimir(){
    cout << "Sala: " << numeroDaSala << ", " 
              << quantidadeDeAlunos << " alunos, inicio as "  
              << horaDeInicio  << " horas e termina as " 
              << horaDeInicio + calcularDuracao() <<" horas." << endl;

}