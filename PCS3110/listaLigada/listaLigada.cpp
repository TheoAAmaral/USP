#include <iostream>
#include <string>
using namespace std;

class List{
    public:
        int key;

        List *next;

        void addNode(int key){
            next = new List;
            next->key = key;
        }
};

int main(){
    List *S1 = new List;

    S1->addNode(10);
    S1->next->addNode(20);
    S1->next->next->addNode(30);

    cout << "Item 1: " << S1->next->key << endl;
    cout << "Item 2: " << S1->next->next->key << endl;
    cout << "Item 3: " << S1->next->next->next->key << endl;
    return 0;
}