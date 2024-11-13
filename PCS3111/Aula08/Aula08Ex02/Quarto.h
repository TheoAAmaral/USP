#ifndef QUARTO_H
#define QUARTO_H
#include "Acomodacao.h"

// Faça os includes necessários e modifique a classe!

class Quarto: public Acomodacao {
protected:
    int numeroDePessoas = 0;
    int numeroDeCamas = 0;

public:
    Quarto(int numeroDoQuarto, int numeroDePessoas, int numeroDeCamas);

    double getPrecoDiaria();
    int getNumeroDePessoas();
    int getNumeroDeCamas();
    void imprimir();
};

#endif  // QUARTO_H
