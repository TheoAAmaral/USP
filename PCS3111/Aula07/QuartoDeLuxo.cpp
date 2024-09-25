// Faça os includes necessários
#include "QuartoDeLuxo.h"
#include <iostream>
using namespace std;

QuartoDeLuxo::QuartoDeLuxo(int numeroDoQuarto, bool kingSize, bool sacada) :  Quarto(numeroDoQuarto, 2, 1){
	this->kingSize = kingSize;
	this->sacada = sacada;
}

QuartoDeLuxo::~QuartoDeLuxo() {

}

double QuartoDeLuxo::getPrecoDiaria() {
	return 300 + kingSize*75 + sacada*150;
}

double QuartoDeLuxo::getPrecoDiaria(double desconto) {
	return getPrecoDiaria() * (1.0-desconto);
}

void QuartoDeLuxo::imprimir() {
	cout << "Quarto de luxo " << numeroDoQuarto << ": Diaria custa " << getPrecoDiaria() << " reais" << endl;
}