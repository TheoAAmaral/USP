#include <iostream>
#include <cmath>
// Faca os includes necessarios

using namespace std;

class Reserva
{
public:
    int numeroDaSala = 0;
    int quantidadeDeAlunos = 0;
    int horaDeInicio = 0;

    int calcularDuracao();
    void imprimir();
};

int Reserva::calcularDuracao()
{
    return ceil(2 * sqrt(quantidadeDeAlunos) - 1);
}

void Reserva::imprimir()
{
    cout << "Reserva: Sala: " << numeroDaSala << ", " << quantidadeDeAlunos << " alunos, inicio as " << horaDeInicio << " e termina as " << this->calcularDuracao() + horaDeInicio << " horas." << endl;
}

class Biblioteca
{
public:
    Reserva *reserva1 = nullptr;
    Reserva *reserva2 = nullptr;

    bool adicionarReserva(Reserva *r);
    Reserva *reservaATerminar();
    void imprimir();
};

bool Biblioteca::adicionarReserva(Reserva *r)
{
    if (reserva1 == r)
        return false;
    if (reserva1 == nullptr)
    {
        reserva1 = r;
        return true;
    }
    if (reserva2 == nullptr)
    {
        reserva2 = r;
        return true;
    }
    return false;
}

Reserva *Biblioteca::reservaATerminar()
{
    if (reserva1 == nullptr && reserva2 == nullptr)
        return nullptr;
    if (reserva2 == nullptr || reserva1->calcularDuracao() + reserva1->horaDeInicio <= reserva2->calcularDuracao() + reserva2->horaDeInicio)
        return reserva1;
    return reserva2;
}

void Biblioteca::imprimir(){
    cout << "Biblioteca:" << endl;
    if(reserva1 != nullptr){
        reserva1->imprimir();
        if(reserva2 != nullptr)
            reserva2->imprimir();
    }
    cout << "Sala da reserva a terminar: " << this->reservaATerminar()->numeroDaSala;
}

void teste1()
{
    Reserva *r1 = new Reserva;
    r1->numeroDaSala = 2;
    r1->quantidadeDeAlunos = 3;
    r1->horaDeInicio = 14;
    cout << r1->calcularDuracao() << endl;

    Reserva *r2 = new Reserva;
    r2->numeroDaSala = 4;
    r2->quantidadeDeAlunos = 7;
    r2->horaDeInicio = 2;
    r2->imprimir();
}

void teste2()
{
    Reserva *r1 = new Reserva;
    r1->numeroDaSala = 2;
    r1->quantidadeDeAlunos = 3;
    r1->horaDeInicio = 14;
    r1->imprimir();

    Reserva *r2 = new Reserva;
    r2->numeroDaSala = 4;
    r2->quantidadeDeAlunos = 7;
    r2->horaDeInicio = 2;
    r2->imprimir();

    Biblioteca *b1 = new Biblioteca;
    b1->adicionarReserva(r1);
    b1->adicionarReserva(r2);
    b1->imprimir();
}


int main()
{
    teste2();
    return 0;
}
