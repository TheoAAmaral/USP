#include <iostream>
#include <string>
using namespace std;

class List{
    public:
        int chave;

        List *proximo;
        List *inicio;

        void addNode(int key){
            proximo = new List;
            proximo->chave = key;
        }
};

int main(){
    List *S1 = new List;

    S1->inicio = new List;
    S1->inicio->chave = 10;
    S1->inicio->addNode(20);
    S1->inicio->proximo->addNode(30);
    S1->inicio->proximo->proximo->proximo = S1->inicio;

    cout << "Item 1: " << S1->inicio->chave << endl;
    cout << "Item 2: " << S1->inicio->proximo->chave << endl;
    cout << "Item 3: " << S1->inicio->proximo->proximo->chave << endl;
    return 0;
}