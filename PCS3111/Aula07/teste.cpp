#include "Quarto.h"
#include "QuartoDeLuxo.h"
#include "Hotel.h"
#include "iostream"
using namespace std;

void teste1() {
    Quarto *q18 = new QuartoDeLuxo(18, true, false);
    Quarto *q19 = new QuartoDeLuxo(19, true, true);
    Quarto *q20 = new QuartoDeLuxo(20, false, false);

    q18->imprimir();
    q19->imprimir();
    q20->imprimir();
}

void teste2() {
    int quantidade;
    Hotel *hotel = new Hotel(2, 2);
    hotel->getQuartosDeLuxo(quantidade);
    cout << quantidade << endl;
    
    Quarto *q20 = new Quarto(20, 4, 2);
    hotel->adicionarQuarto(q20);
    hotel->getQuartosDeLuxo(quantidade);
    cout << quantidade << endl;

    Quarto *q21 = new QuartoDeLuxo(21, true, true);
    hotel->adicionarQuarto(q21);
    hotel->getQuartosDeLuxo(quantidade);
    cout << quantidade << endl;
    delete hotel;
}