#include <iostream>
#include <string>
using namespace std;

class Sala1{
    public:
    string nome;
    int posDaCadeira;
    string corDaMochila;

    void matricularAluno(string nome, int posDaCadeira, string corDaMochila);
    
};

void Sala1::matricularAluno(string nome, int posDaCadeira, string corDaMochila){
    this->nome = nome;
    this->posDaCadeira = posDaCadeira;
    this->corDaMochila = corDaMochila;
}

int main(){
    Sala1 *aluno1 = new Sala1;
    Sala1 *aluno2 = new Sala1;

    aluno2->matricularAluno("Bruno", 26, "Preta");

    aluno1->nome = "Ana";
    aluno1->posDaCadeira = 1;
    aluno1->corDaMochila = "Rosa";

    cout << "Nome: " << aluno2->nome << endl << "Pos da Cadeira: " << aluno2->posDaCadeira << endl << "Cor da Mochila: " << aluno2->corDaMochila << endl;

    return 0;
}