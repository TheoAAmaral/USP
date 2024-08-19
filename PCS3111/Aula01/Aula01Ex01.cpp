#include <iostream>
using namespace std;

double calcularPreco(double precoDiaria, bool temCafe, int numeroDePessoas){
	double preco = precoDiaria;
	if(temCafe) preco += 20;
	if(numeroDePessoas == 2) preco *= 1.5;
	else preco *= numeroDePessoas;

	return preco;
}

/*
int main(){
	cout << calcularPreco(200, true, 2) << endl;
	cout << calcularPreco(200, false, 4) << endl;
	return 0;
}
*/

