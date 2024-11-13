#if !defined(HOTEL_H)
#define HOTEL_H

#include "Quarto.h"
#include "Reserva.h"
#include <vector>
#include <list>
using namespace std;

class Hotel {
private:
  vector<Quarto *>* quartos;
  list<Reserva *>* reservas;

public:
  Hotel();
  virtual ~Hotel();

  // metodos que usam Quarto
  void adicionar(Quarto *q);
  vector<Quarto *>* getQuartos();

  // metodos que usam Reserva
  void fazer(Reserva *r);
  void cancelar(Reserva *r);
  list<Reserva *>* getReservas();

  void imprimir();
};

#endif // HOTEL_H
