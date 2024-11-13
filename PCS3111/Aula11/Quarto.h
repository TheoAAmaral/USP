#if !defined(QUARTO_H)
#define QUARTO_H

class Quarto {
private:
  int numero;

public:
  Quarto(int numero);
  virtual ~Quarto();
  int getNumero();
  void imprimir();
};

#endif // QUARTO_H
