#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

#define FILENAME "multiplicador_tb_arquivo.dat"


int main(){
    ofstream f(FILENAME);

    for(int i = 0; i <= 0b1111; i++){
        for(int j = 0; j <= 0b1111; j++){
            std::bitset<4> J(j);
            std::bitset<4> I(i);
            std::bitset<8> JI(j*i);
            f << J << " " << I << " " << JI << endl;
        }
    }

    f.close();
}