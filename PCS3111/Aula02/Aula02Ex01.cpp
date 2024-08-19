#include <iostream>
#include <string>
using namespace std;

string* procurarPessoa(string nomes[], int inicios[], int fins[], int quantidade, int inicio, int fim){
    for(int i = 0; i < quantidade; i++){
        if(inicios[i] == inicio && fins[i] == fim)
            return &nomes[i];
    }
    return nullptr;
}


int main(){
    string nomes[] = {"Gabriel", "Daniel", "Carlos"};
    int inicios[] = {1, 12, 20};
    int fins[] = {5, 17, 25};
    int inicio = 12, fim = 17, quantidade = 3;

    string* nome;
    nome = procurarPessoa(nomes, inicios, fins, quantidade, inicio, fim);

    cout << *nome << endl;
    return 0;
}
