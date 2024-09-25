#include <iostream>
#include<string>
using namespace std;

class Tablet{
    public:
    string cor;
    bool temCapinha;
};

int main(){
    Tablet *tablet1 = new Tablet;
    Tablet *tablet2 = new Tablet;

    tablet1->cor = "Amarelo";
    tablet1->temCapinha = true;

    tablet2->cor = "Azul";
    tablet2->temCapinha = false;


}