#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Acomodacao.h"

// Faça os includes necessários

class Apartamento: public Acomodacao
{
private:
  double area;
public:
  Apartamento(int numero, double area);
  ~Apartamento();

  // Lembre de implementar os métodos não implementados
  double getArea();
  double getPrecoDiaria();
  void imprimir();
};
#endif