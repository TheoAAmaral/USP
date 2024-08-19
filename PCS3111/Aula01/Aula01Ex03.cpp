#include <iostream>
using namespace std;

int calcularServicosIguais(string servicosQuarto1[], int quantidade1, string servicosQuarto2[], int quantidade2){
    int iguais = 0;
    for(int i = 0; i < quantidade1; i++){
        for(int j = 0; j < quantidade2; j++){
            if(servicosQuarto1[i] == servicosQuarto2[j])
                iguais++;
        }
    }
    return iguais;
}

/*
int main(){
    string servicosQuarto1[] = {"massagem", "cafe da manha", "vinho", "pizza"};
    int quantidade1 = 4;
    string servicosDoQuarto2[] = {"agua", "cafe da manha", "pizza"};
    int quantidade2 = 3;
    cout << calcularServicosIguais(servicosQuarto1,quantidade1,servicosDoQuarto2,quantidade2) << endl;

    return 0;
}
*/