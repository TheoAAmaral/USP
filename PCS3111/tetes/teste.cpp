#include <iostream>
using namespace std;

void func1(int v[]){
    v[0] = 1;
    cout << "Vetor funcao: " << &v[0] << endl;
}


int main(){
    int v[5];
    v[0] = 0;
    cout << "V[0] antes = " << v[0] << endl;
    cout << "Vetor original: " << &v[0] << endl;
    func1(v);
    cout << "V[0] depois = " << v[0] << endl;
    return 0;
}