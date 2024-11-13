#include "Hotel.h"

void teste1() {
	Hotel* h = new Hotel();
	Quarto *q1 = new Quarto(1);
	h->adicionar(q1);
	Quarto *q2 = new Quarto(2);
	h->adicionar(q2);

	h->imprimir();
	delete h;
	delete q1;
	delete q2;
}

void teste2() {
	Hotel* h = new Hotel();
	Quarto *q1 = new Quarto(1);
	h->adicionar(q1);
	Quarto *q2 = new Quarto(2);
	h->adicionar(q2);

	Reserva* r1 = new Reserva(q1, 0, 5);
	Reserva* r2 = new Reserva(q2, 5, 6);
	h->fazer(r1);
	h->fazer(r2);

	h->imprimir();
	h->cancelar(r2);
	h->imprimir();

	delete h;
	delete q1;
	delete q2;
	delete r2;
}