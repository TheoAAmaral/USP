#include <iostream>
using namespace std;

class List{
    public:
        int chave = 0;

        List *proximo;

        void addNode(int key){
            proximo = new List;
            proximo->chave = key;
        }
};
bool hashInsert(List *list[], int key){
    int index = key%sizeof(list) / sizeof(List);
    if(list[index] == nullptr){
        list[index] = new List;
        list[index]->chave = key;
        return true;
    }
    else{
        List *actual = list[index];
        List *nextAddr = nullptr;
        while(actual->proximo != nullptr){
            if(actual->proximo->chave >= key){
                nextAddr = actual->proximo;
                actual->proximo = new List;
                actual->proximo->proximo = nextAddr;
                actual->proximo->chave = key;
                actual = nullptr;
                nextAddr = nullptr;
                delete actual, nextAddr;
                return true;
            }
            else
                actual = actual->proximo;
        }
    }
}


int main(){
    List *list[10];

    hashInsert(list, 10);
    hashInsert(list, 20);


    return 0;
}

