#include "Quarto.h"

#include <iostream>

using namespace std;

Quarto::Quarto(int numeroDoQuarto, int numeroDePessoas, int numeroDeCamas): Acomodacao(numeroDoQuarto)
{
    this->numeroDeCamas = numeroDeCamas;
    this->numeroDePessoas = numeroDePessoas;
}

int Quarto::getNumeroDeCamas()
{
    return numeroDeCamas;
}

int Quarto::getNumeroDePessoas()
{
    return numeroDePessoas;
}

double Quarto::getPrecoDiaria()
{
    if (numeroDePessoas == 2)
    {
        return (double) 100 * 1.5;
    }
    else
    {
        return 100 * numeroDePessoas;
    }
}

 void Quarto::imprimir()
 {
     cout << "Quarto " << getNumero() << ": " << numeroDePessoas << " pessoas, "
          << numeroDeCamas << " camas - Diaria custa " << this->getPrecoDiaria() << endl;
 }