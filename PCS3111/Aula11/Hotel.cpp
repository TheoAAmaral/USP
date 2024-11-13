#include "Hotel.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Hotel::Hotel()
{
	this->quartos = new vector<Quarto *>;
	this->reservas = new list<Reserva *>;
}

Hotel::~Hotel()
{
	delete quartos;

	for (list<Reserva *>::iterator i = this->reservas->begin(); i != this->reservas->end(); i++)
	{
		delete *i;
		cout << "Reserva " << *i << " deletada" << endl;
	}
	delete reservas;

	cout << "Hotel deletado" << endl;
}

void Hotel::adicionar(Quarto *q)
{
	for (vector<Quarto *>::iterator i = this->quartos->begin(); i != this->quartos->end(); i++)
	{
		if (*i == q)
		{
			throw new invalid_argument("Quarto ja adicionado");
		}
	}

	this->quartos->push_back(q);
}

vector<Quarto *> *Hotel::getQuartos() { return this->quartos; }

void Hotel::fazer(Reserva *r)
{
	for (list<Reserva *>::iterator i = this->reservas->begin(); i != this->reservas->end(); i++)
	{
		if ((*i)->getQuarto() == r->getQuarto())
		{
			if ((*i)->getFim() > r->getInicio() &&
				(*i)->getInicio() < r->getFim())
			{
				throw new invalid_argument("Periodo indisponivel");
			}
		}
	}

	reservas->push_back(r);
}

void Hotel::cancelar(Reserva *r)
{
	for (list<Reserva*>::iterator i = reservas->begin(); i != reservas->end(); i++)
	{
		if (*i == r)
		{
			reservas->erase(i);
			return;
		}
	}
}

list<Reserva *> *Hotel::getReservas() { return reservas; }

void Hotel::imprimir()
{
	cout << "Hotel com " << quartos->size()
		 << " quarto(s):" << endl;
	for (vector<Quarto *>::iterator i = quartos->begin(); i != quartos->end(); i++)
	{
		(*i)->imprimir();
	}

	cout << "e " << reservas->size() << " reserva(s):" << endl;
	for (list<Reserva *>::iterator i = reservas->begin(); i != reservas->end(); i++)
	{
		(*i)->imprimir();
	}
}