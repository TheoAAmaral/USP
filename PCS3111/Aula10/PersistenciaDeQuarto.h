#if !defined(PERSISTENCIA_DE_QUARTO_H)
#define PERSISTENCIA_DE_QUARTO_H

#include "Quarto.h"
#include <iostream>
#include <string>

using namespace std;

class PersistenciaDeQuarto {
private:
    string arquivo;
    Quarto** quartos;
public:
    PersistenciaDeQuarto(string arquivo);
    virtual ~PersistenciaDeQuarto();
    void inserir(Quarto *q);
    Quarto **obter(int &quantidade);
};

#endif // PERSISTENCIA_DE_QUARTO_H
