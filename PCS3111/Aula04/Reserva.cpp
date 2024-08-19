#include "Reserva.h"

void Reserva::setQuarto(int numeroDoQuarto){
    quarto = numeroDoQuarto;
}

void Reserva::setInicio(int inicio){
    this->inicio = inicio;
}

void Reserva::setFim(int fim){
    this->fim = fim;
}

int Reserva::getInicio(){
    return inicio;
}

int Reserva::getFim(){
    return fim;
}

int Reserva::getQuarto(){
    return quarto;
}

double Reserva::getPreco()
{
    return 100*(fim - inicio);
}

void Reserva::imprimir()
{
    cout << "Reserva ("<< inicio << "-" << fim << "): Quarto " << quarto << " - " << getPreco() << " reais" << endl;
}