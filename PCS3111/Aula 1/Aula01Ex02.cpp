#include <iostream>
using namespace std;

bool estaDisponivel(int inicio, int fim, int reservasInicio[], int reservasFim[], int quantidade){
    bool disponivel = true;
    for(int i = 0; i < quantidade && disponivel; i++){
        if(inicio >= reservasInicio[i] && inicio < reservasFim[i]) disponivel = false;
        else if(fim > reservasInicio[i] && fim <= reservasFim[i]) disponivel = false;
    }
    return disponivel;
}

/*
int main(){

    int inicio = 3, fim = 4;
    int reservasInicio[] = {1, 3, 8};
    int reservasFim[] = {3, 7, 10 };
    int quantidade = 3;
    cout << estaDisponivel(inicio, fim, reservasInicio, reservasFim, quantidade) << endl;

    return 0;
}
*/