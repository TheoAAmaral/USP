#include "Biblioteca.h"
#include <iostream>
using namespace std;

Biblioteca::Biblioteca(int maximo){
    // implemente
}

Biblioteca::~Biblioteca(){
    // implemente
}

SalaDeEstudo** Biblioteca::getSalasDeEstudo(){
    return salas;
}

Reserva** Biblioteca::getReservas(){
    return reservas;
}

int Biblioteca::getQuantidadeDeSalas(){
    return quantidadeDeSalas;
}

int Biblioteca::getMaximo(){
    return maximo;
}

int Biblioteca::getQuantidadeDeReservas(){
    return quantidadeDeReservas;
}

bool Biblioteca::adicionarReserva(Reserva* r){
    if(quantidadeDeReservas < maximo){
        reservas[quantidadeDeReservas++] = r;
        return true;
    }

    return false;
}

bool Biblioteca::adicionarSala(SalaDeEstudo* s){
    if(quantidadeDeSalas < maximo){
        salas[quantidadeDeSalas++] = s;
        return true;
    }

    return false;
}

void Biblioteca::imprimirReservas(){
    for(int i = 0; i < quantidadeDeReservas; i++){
        reservas[i]->imprimir();
    }
}

int Biblioteca::terminarReservas(int horaAtual){
    // implemente
    return 0;
}
