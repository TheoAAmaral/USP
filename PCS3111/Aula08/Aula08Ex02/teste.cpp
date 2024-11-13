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
	Apartamento* ap21 = new Apartamento(21, 60);
	Apartamento* ap31 = new Apartamento(31, 85);
	Apartamento* ap41 = new Apartamento(41, 105);

	Apartamento::setPrecoBase(150);
	ap21->imprimir();
	ap31->imprimir();
	ap41->imprimir();

	Apartamento::setPrecoBase(300);
	ap21->imprimir();
	ap31->imprimir();
	ap41->imprimir();

	delete ap21;
	delete ap31;
	delete ap41;
}
