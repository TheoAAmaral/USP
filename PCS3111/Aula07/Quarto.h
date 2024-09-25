#ifndef QUARTO_H
#define QUARTO_H

#include <string>

using namespace std;

// Modifique o que for necessário

class Quarto {
protected:
    int numeroDoQuarto = 0;
    int numeroDePessoas = 0;
    int numeroDeCamas = 0;

public:
    Quarto(int numeroDoQuarto, int numeroDePessoas, int numeroDeCamas);

    virtual double getPrecoDiaria();
    int getNumeroDoQuarto();
    int getNumeroDePessoas();
    int getNumeroDeCamas();

    virtual void imprimir();
};

#endif  // QUARTO_H
