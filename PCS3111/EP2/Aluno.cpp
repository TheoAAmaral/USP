#include "Aluno.h"
#include "Registro.h"
#include "Entrada.h"
#include "Saida.h"
#include <stdexcept>

int Aluno::horaFim = 23;
int Aluno::minutoFim = 0;

Aluno::Aluno(int id, string nome): Usuario(id, nome){}

Aluno::~Aluno(){}

void Aluno::setHorarioFim(int hora, int minuto){
    if(hora < HORARIO_INICIO || hora > 23)
        throw new logic_error("Hora invalida");
    if(minuto < 0 || minuto > 59)
        throw new logic_error("Minuto invalido");
    Aluno::horaFim = hora;
    Aluno::minutoFim = minuto;
}

int Aluno::getHoraFim(){
    return Aluno::horaFim;
}

int Aluno::getMinutoFim(){
    return Aluno::minutoFim;
}

bool Aluno::entrar(Data *d){
    if(d->getHora() > horaFim || (d->getHora() == horaFim && d->getMinuto() > minutoFim) || d->getHora() < HORARIO_INICIO)
        return false;
    registros->push_back(new Entrada(d));
    return true;
}

bool Aluno::sair(Data *d){
    registros->push_back(new Saida(d));
    return true;
}

bool Aluno::registrarEntradaManual(Data *d){
    return false;
}

bool Aluno::registrarSaidaManual(Data *d){
    registros->push_back(new Saida(d));
    return true;
}