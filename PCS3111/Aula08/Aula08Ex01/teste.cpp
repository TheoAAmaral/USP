#include "Apartamento.h"

void teste1() {
	Apartamento* ap33 = new Apartamento(33, 55);
	Apartamento* ap43 = new Apartamento(43, 70);
	Apartamento* ap53 = new Apartamento(53, 120);

	ap33->imprimir();
	ap43->imprimir();
	ap53->imprimir();

	delete ap33;
	delete ap43;
	delete ap53;
}

void teste2() {
}