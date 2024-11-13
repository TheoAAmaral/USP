#if !defined(QUARTO_H)
#define QUARTO_H

class Quarto
{
protected:
    int numero;
    int numeroDeCamas;

public:
    Quarto(int numero, int numeroDeCamas);
    void imprimir();
    int getNumero();
    int getNumeroDeCamas();
};

#endif // QUARTO_H
