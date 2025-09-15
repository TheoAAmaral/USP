#include "Biblioteca.h"
#include <iostream>
using namespace std;

Biblioteca::Biblioteca(int maximo){
    this->maximo = maximo;
    reservas = new Reserva*[maximo];
    salas = new SalaDeEstudo*[maximo];
    quantidadeDeReservas = 0;
    quantidadeDeSalas = 0;
}

Biblioteca::~Biblioteca(){
    delete[] reservas;
    delete[] salas; 
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
    for(int i = 0; i < quantidadeDeReservas; i++){
        if(reservas[i]->calculaDuracao()+reservas[i]->getHoraInicio() <= horaAtual){
            delete reservas[i];
            quantidadeDeReservas--;
            for(int j = i; j < quantidadeDeReservas; j++){
                reservas[j] = reservas[j+1];
            }
        }
    }
    return 0;
}
