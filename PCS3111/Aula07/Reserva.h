#ifndef Reserva_H
#define Reserva_H

#include "Quarto.h"

class Reserva {
private:
    Quarto *quarto = nullptr;
    int inicio = 0;
    int fim = 0;
public:
    Reserva(Quarto* quarto, int inicio, int fim);
    ~Reserva();
    
    Quarto* getQuarto();
    int getInicio();
    int getFim();
    
    double calcularPreco();

    void imprimir();
};

#endif  // Reserva_H
