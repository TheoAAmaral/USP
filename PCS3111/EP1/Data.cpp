#include "Data.h"

Data::Data(int hora, int minuto, int segundo, int dia, int mes, int ano){
    data->tm_hour = hora;
    data->tm_min = minuto;
    data->tm_sec = segundo;
    data->tm_isdst = 0;
    data->tm_mday = dia;
    data->tm_mon = mes - 1;
    data->tm_year = ano;
}

Data::~Data(){
    delete data;
}

int Data::getHora(){
    return data->tm_hour;
}
int Data::getMinuto(){
    return data->tm_min;
}
int Data::getSegundo(){
    return data->tm_sec;
}
int Data::getDia(){
    return data->tm_mday;
}
int Data::getMes(){
    return data->tm_mon+1;
}
int Data::getAno(){
    return data->tm_year;
}

int Data::diferenca(Data *dataComp){
    time_t t = mktime(data);
    time_t tComp = mktime(dataComp->data);
    return (int) difftime(t, tComp);
}