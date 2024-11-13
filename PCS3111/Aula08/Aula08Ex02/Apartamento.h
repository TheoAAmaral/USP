#ifndef APARTAMENTO_H
#define APARTAMENTO_H
#include "Acomodacao.h"

// Faça os includes necessários

class Apartamento: public Acomodacao
{
private:
  double area;
  static double precoBase;
public:
  Apartamento(int numero, double area);
  ~Apartamento();

  // Lembre de implementar os métodos não implementados
  double getArea();
  double getPrecoDiaria();
  void imprimir();
  static double getPrecoBase();
  static void setPrecoBase(double precoBase);
};
#endif