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
}

class Reserva {
public:
    Quarto *quarto1 = nullptr;
    Quarto *quarto2 = nullptr;
    int inicio = 0;
    int fim = 0;
    bool adicionarQuarto(Quarto *q);
    double calcularPreco();
    void imprimir();
};

bool Reserva::adicionarQuarto(Quarto *q){
    if(quarto1 == nullptr){
        quarto1 = q;
        return true;
    }
    else if(quarto2 == nullptr && q != quarto1){
        quarto2 = q;
        return true;
    }
    else
        return false;
}

double Reserva::calcularPreco(){
    double preco;
    int duracao = this->fim - this->inicio;

    if(quarto1 == nullptr && quarto2 == nullptr)
        return 0;
    if(quarto1 != nullptr)
        preco = quarto1->getPrecoDiaria() * duracao;
    if(quarto2 != nullptr)
        preco += quarto2->getPrecoDiaria() * duracao;

    return preco;
}


void Reserva::imprimir(){
    cout << "Reserva:" << endl;
    if(quarto1 != nullptr)
        quarto1->imprimir();
    if(quarto2 != nullptr)
        quarto2->imprimir();        
    cout << "Preco total: " << this->calcularPreco() << endl;

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
void teste2(){
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

    Reserva *reserva = new Reserva;
    reserva->inicio = 2;
    reserva->fim = 13;
    reserva->adicionarQuarto(q31);
    reserva->adicionarQuarto(q32);
    reserva->imprimir();

    return;
}

/*
int main(){
    teste2();

    return 0;
}
*/
