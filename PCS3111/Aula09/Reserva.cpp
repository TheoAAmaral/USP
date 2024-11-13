// Faca os includes necessarios
#include "Reserva.h"
#include "SemEspaco.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Reserva::Reserva(Quarto *quarto, int inicio, int fim, int numeroDePessoas) {
  if(inicio >= fim)
    throw new invalid_argument ("Duracao invalida");
  if(numeroDePessoas < 1)
    throw new invalid_argument ("Numero de pessoas invalido");
  try{
    preco = quarto->getPrecoDiaria(numeroDePessoas);
  } catch (SemEspaco *e){
    throw new invalid_argument ("Quarto sem espaco");
  }
  this->quarto = quarto;
  this->inicio = inicio;
  this->fim = fim;
  this->numeroDePessoas = numeroDePessoas;
}

Reserva::~Reserva() {}

int Reserva::getInicio() { return inicio; }

int Reserva::getFim() { return fim; }

int Reserva::getNumeroDePessoas() { return numeroDePessoas; }

Quarto* Reserva::getQuarto() { return quarto; }

double Reserva::getPreco() { return preco; }

void Reserva::imprimir() {
  cout << "Reserva de inicio " << inicio << ", fim " << fim << " e preco "
       << preco << endl;
}
