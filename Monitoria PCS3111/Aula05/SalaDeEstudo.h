#ifndef SALADEESTUDO_H
#define SALADEESTUDO_H

class SalaDeEstudo {
private:
    int numero;
    int capacidade;
public:
    SalaDeEstudo(int numero, int capacidade);
    ~SalaDeEstudo();
    int getCapacidade();
    int getNumero();
    void imprimir();
};

#endif