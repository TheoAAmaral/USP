// Faca os includes necessarios
#include "Quarto.h"
#include "PersistenciaDeQuarto.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void teste1() {
    Quarto* q1 = new Quarto(1, 4);
    Quarto* q2 = new Quarto(2, 2);
    Quarto* q3 = new Quarto(3, 1);

    PersistenciaDeQuarto* persist = new PersistenciaDeQuarto("teste1.txt");

    persist->inserir(q1);
    persist->inserir(q2);
    persist->inserir(q3);

    delete q1;
    delete q2;
    delete q3;
    delete persist;
}

void teste2() {
    PersistenciaDeQuarto* persist = new PersistenciaDeQuarto("teste2.txt");
    Quarto** quartos = nullptr;
    int quantidade;
    try{
        quartos = persist->obter(quantidade);
    }catch(logic_error *e){
        cout << e->what() << endl;
        delete e;
    }
    if(quantidade > 0){
        for(int i = 0; i < quantidade; i++){
            quartos[i]->imprimir();
            delete quartos[i];
        }
    }
    delete quartos;
    delete persist;
}