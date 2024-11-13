#if !defined(QUARTO_H)
#define QUARTO_H

class Quarto {
private:
  int numeroDoQuarto;
  int numeroDeCamas;
  static double precoBase;

public:
  Quarto(int numeroDoQuarto, int numeroDeCamas);
  ~Quarto();
  double getPrecoDiaria(int numeroDePessoas);
  void imprimir();
};

#endif // QUARTO_H
