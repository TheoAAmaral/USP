#include <iostream>
using namespace std;


class List{
    public:
        int key;
        List *start = nullptr;
        List *next = nullptr;
};

bool queueEmpty(List *q){
    return q->start == nullptr;
}

void enqueue(List *q, int key){
    List *actual = nullptr;
    if(queueEmpty(q)){
        q->start = new List;
        q->start->key = key;
    }
    else{
        actual = q->start;
        while(actual->next != nullptr){
            actual = actual->next;
        }
        actual->next = new List;
        actual->next->key = key;
    }

    actual = nullptr;
    delete actual;
    return;
}
int dequeue(List *q){
    List *newStart = nullptr;
    List *oldStart = q->start;
    int key = q->start->key;
    newStart = q->start->next;
    q->start = newStart;
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