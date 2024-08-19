/*
 * Coloque a definicao da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 *
 *  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
 */
#include <iostream>
using namespace std;
#ifndef RESERVA_H
#define RESERVA_H

class Reserva
{
    int quarto;
    int inicio = 0;
    int fim = 0;




    
public:

    void setQuarto(int numeroDoQuarto);
    void setInicio(int inicio);
    void setFim(int fim);
    
    int getInicio();
    int getFim();
    int getQuarto();
    double getPreco();
    
    void imprimir();
};
#endif