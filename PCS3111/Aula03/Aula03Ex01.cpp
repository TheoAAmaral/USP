#include <iostream>
#include <string>
using namespace std;

class Quarto {
public:
    int numeroDoQuarto = 0;
    int numeroDePessoas = 0;
    int numeroDeCamas = 0;
    double getPrecoDiaria();
    void imprimir();
};

double Quarto::getPrecoDiaria(){
    if(numeroDePessoas == 2)
        return 150;
    else
        return 100*numeroDePessoas;
}

void Quarto::imprimir(){
    cout << "Quarto " << numeroDoQuarto << ": " << numeroDePessoas << " pessoas, " << numeroDeCamas << " camas - Diaria custa " << getPrecoDiaria() << endl;
    
    return;
}

void teste1(){
    Quarto *q31 = new Quarto;
    Quarto *q32 = new Quarto;

    q31->numeroDoQuarto = 31;
    q31->numeroDePessoas = 3;
    q31->numeroDeCamas = 2;
    q31->imprimir();

    q32->numeroDoQuarto = 32;
    q32->numeroDePessoas = 2;
    q32->numeroDeCamas = 1;
    q32->imprimir();

    return;
}

/*
int main(){
    teste1();

    return 0;
}   
*/