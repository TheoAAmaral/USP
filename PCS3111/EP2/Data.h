#ifndef DATA_H
#define DATA_H
#include <ctime>


class Data{
    private:
        tm* data = new tm;
    public:
        Data(int hora, int minuto, int segundo, int dia, int mes, int ano);
        virtual ~Data();


        int getHora();
        int getMinuto();
        int getSegundo();
        int getDia();
        int getMes();
        int getAno();
        int diferenca(Data* d);
};

#endif