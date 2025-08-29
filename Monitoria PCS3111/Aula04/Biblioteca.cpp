/*
 * Coloque a implementação da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessários para a classe.
 */
#include "Biblioteca.h"
#include <iostream>
using namespace std;

bool Biblioteca::fazer(Reserva* reserva){
    if(quantidade < MAXIMO_DE_RESERVAS){
        for(int i = 0; i < quantidade; i++)
            if(reservas[i] == reserva)
                return false;
        reservas[quantidade++] = reserva;
        return true;
    }
    return false;
}

Reserva* Biblioteca::reservaATerminar(){
    int maisProxima = -1;
    Reserva* r = nullptr;
    for(int i = 0; i < quantidade; i++){
        if(maisProxima == -1 || reservas[i]->calcularDuracao()+reservas[i]->getHoraDeInicio() < maisProxima){
            r = reservas[i];
            maisProxima = r->getHoraDeInicio()+r->calcularDuracao();
        }
    }
    return r;
}

void Biblioteca::imprimir(){
    /*Não modifique este método*/
    // o vetor precisa chamar reservas e a quantidade de elementos deve-se chamar quantidade
    cout << "Biblioteca com " << quantidade << " reservas " << endl;
    for (int i = 0; i < quantidade; i++)
        reservas[i]->imprimir();
    if (quantidade > 0)
        cout << "Sala da reserva a terminar: " << this->reservaATerminar()->getNumeroDaSala() << endl;

}

Reserva* Biblioteca::getReserva(int posicao) {
    /*Não modifique este método*/
    // o vetor precisa chamar reservas
    return reservas[posicao];
}