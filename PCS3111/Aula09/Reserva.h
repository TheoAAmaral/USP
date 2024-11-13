#if !defined(RESERVA_H)
#define RESERVA_H

#include "Quarto.h"

class Reserva {
private:
  int inicio;
  int fim;
  int numeroDePessoas;
  double preco;
  Quarto* quarto;

public:
  Reserva(Quarto *quarto, int inicio, int fim, int numeroDePessoas);
  ~Reserva();
  Quarto *getQuarto();
  int getInicio();
  int getFim();
  int getNumeroDePessoas();
  double getPreco();
  void imprimir();
};

#endif // RESERVA_H