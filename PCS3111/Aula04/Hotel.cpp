#include "Hotel.h"
#include <iostream>
using namespace std;

bool Hotel::adicionar(Reserva* reserva){
    if(numeroDeReservas + 1 <= MAXIMO_DE_RESERVAS){
        for(int i = 0; i < numeroDeReservas; i++){
            if(reserva == reservas[i])
                return false;
        }
        reservas[numeroDeReservas] = reserva;
        numeroDeReservas++;
        return true;
    }
    return false;
}

bool Hotel::estaDisponivel(int quarto, int inicio, int fim){
    Reserva *reserva = nullptr;
    for(int i = 0; i < numeroDeReservas; i++){
        if(quarto == reservas[i]->getQuarto()){
            reserva = reservas[i];
            if((inicio >= reserva->getInicio() && inicio < reserva->getFim()) || (fim > reserva->getInicio() && fim <= reserva->getFim()))
                return false;
        }
    }
    return true;
}

Reserva* Hotel::getReserva(int i){
    return reservas[i];
}

void Hotel::imprimir(){
    cout << "Hotel com " << numeroDeReservas << " reservas" << endl;
    for(int i = 0; i < numeroDeReservas; i++){
        reservas[i]->imprimir();
    }
}