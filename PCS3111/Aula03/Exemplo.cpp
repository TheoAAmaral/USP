#include <iostream>
#include <string>
using namespace std;

class Lampada{
    
    bool acesa = false;

    public:
    string nome;
    void ligar();
    void desligar();
    void imprimir();
    bool getAcesa(){
        return acesa;
    }
};

void Lampada::ligar(){
    acesa = true;
}

void Lampada::desligar(){
    acesa = false;
}

void Lampada::imprimir(){
    cout << acesa << endl;
}

int main(){
    Lampada l1; 
    Lampada l2;
    l2.nome = "L2";

    l1 = l2;
    l1.imprimir();
    l1.ligar();
    l1.imprimir();
    cout << "Nome de l1: " << l1.nome << " Nome de l2: " << l2.nome << endl;

    l2.ligar();
    l2.imprimir();
    l2.desligar();
    l2.imprimir();

    return 0;
}