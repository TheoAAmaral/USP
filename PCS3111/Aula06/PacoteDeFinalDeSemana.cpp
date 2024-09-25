#include "PacoteDeFinalDeSemana.h"

PacoteDeFinalDeSemana::PacoteDeFinalDeSemana(Quarto* quarto, int inicio, bool temCafe): Reserva(quarto, inicio, inicio+2){
    this->cafe = temCafe;
    this->precoTotal = this->quarto->getPrecoDiaria()*2 + (temCafe*40);
}

PacoteDeFinalDeSemana::~PacoteDeFinalDeSemana(){

}

