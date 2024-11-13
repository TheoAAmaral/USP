#if !defined(RESERVA_H)
#define RESERVA_H

#include "Quarto.h"

class Reserva {
private:
  Quarto *q;
  int inicio;
  int fim;

public:
  Reserva(Quarto *q, int inicio, int fim);
  virtual ~Reserva();

  int getInicio();
  int getFim();
  Quarto *getQuarto();
  void imprimir();
};

#endif // RESERVA_H
