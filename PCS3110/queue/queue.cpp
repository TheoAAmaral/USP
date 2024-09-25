#include <iostream>
using namespace std;


class List{
    public:
        int chave;
        List *inicio = nullptr;
        List *proximo = nullptr;
};

bool queueEmpty(List *q){
    return q->inicio == nullptr;
}

void enqueue(List *q, int key){
    List *actual = nullptr;
    if(queueEmpty(q)){
        q->inicio = new List;
        q->inicio->chave = key;
    }
    else{
        actual = q->inicio;
        while(actual->proximo != nullptr){
            actual = actual->proximo;
        }
        actual->proximo = new List;
        actual->proximo->chave = key;
    }

    actual = nullptr;
    delete actual;
    return;
}
int dequeue(List *q){
    List *newStart = nullptr;
    List *oldStart = q->inicio;
    int key = q->inicio->chave;
    newStart = q->inicio->proximo;
    q->inicio = newStart;
    newStart = nullptr;
    delete newStart;
    delete oldStart;
    return key;
}


int main(){
    List *q = new List;

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    cout << dequeue(q) << dequeue(q) << dequeue(q) << endl;
    return 0;
}