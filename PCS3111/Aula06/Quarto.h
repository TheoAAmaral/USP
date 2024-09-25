#ifndef QUARTO_H
#define QUARTO_H

#include <string>

using namespace std;

class Quarto {
private:
    int numeroDoQuarto = 0;
    int numeroDePessoas = 0;
    int numeroDeCamas = 0;

public:
    Quarto(int numeroDoQuarto, int numeroDePessoas, int numeroDeCamas);

    double getPrecoDiaria();
    int getNumeroDoQuarto();
    int getNumeroDePessoas();
    int getNumeroDeCamas();

    void imprimir();
};

#endif  // QUARTO_H
