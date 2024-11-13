#include "PersistenciaDeQuarto.h"
#include <fstream>
#include <stdexcept>
// inclua o que for necessario

PersistenciaDeQuarto::PersistenciaDeQuarto(string arquivo) {
    this->arquivo = arquivo;
}

PersistenciaDeQuarto::~PersistenciaDeQuarto() {
}

// Implemente
void PersistenciaDeQuarto::inserir(Quarto *q) {
    ofstream output;
    output.open(arquivo, ios_base::app);
    output << q->getNumero() << endl;
    output << q->getNumeroDeCamas() << endl;
}

// Implemente
Quarto **PersistenciaDeQuarto::obter(int &quantidade) {
    ifstream input;
    quantidade = 0;
    input.open(arquivo);
    if(input.fail()){
        input.close();
        throw new invalid_argument("Erro de leitura");
    }
    quartos = new Quarto*[10];
    int numero, camas;
    input >> numero;
    while(input && !input.eof()){
        input >> camas;
        quartos[quantidade] = new Quarto(numero, camas);
        quantidade++;
        input >> numero;
    }

    if(!input.eof())
        throw new logic_error("Arquivo com formatacao inesperada");

    input.close();
    if(!quantidade)
        return nullptr;
    return quartos;
}
