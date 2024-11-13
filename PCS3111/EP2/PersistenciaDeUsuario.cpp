#include "PersistenciaDeUsuario.h"
#include <string.h>
#include <fstream>
#include "Funcionario.h"
#include "Aluno.h"
#include "Visitante.h"
#include "Entrada.h"
#include "Saida.h"

void escreveData(ofstream &output, Data* d){
    output << d->getHora() << " ";
    output << d->getMinuto() << " ";
    output << d->getSegundo() << " ";
    output << d->getDia() << " ";
    output << d->getMes() << " ";
    output << d->getAno() << " ";
}

Data* leData(ifstream &input){
    int hora, minuto, segundo, dia, mes, ano;
    
    input >> hora;
    input >> minuto;
    input >> segundo;
    input >> dia;
    input >> mes;
    input >> ano;

    return new Data(hora, minuto, segundo, dia, mes, ano);
}

vector<Registro*>* leRegistros(ifstream &input, int quantidadeDeRegistros){
    vector<Registro*>* registros = new vector<Registro*>;
    char tipoDeRegistro;
    bool isManual;
    Data* d = nullptr;
    int i = 0;

    while(i < quantidadeDeRegistros){
        input >> tipoDeRegistro;
        d = leData(input);
        input >> isManual;
        if(tipoDeRegistro == 'E')
            registros->push_back(new Entrada(d, isManual));
        else
            registros->push_back(new Saida(d, isManual));
        i++;
    }
    if(!i)
        return nullptr;
    else
        return registros;
}


PersistenciaDeUsuario::PersistenciaDeUsuario(){}

PersistenciaDeUsuario::~PersistenciaDeUsuario(){}


void PersistenciaDeUsuario::salvar(string arquivo, vector<Usuario*>* v){
    ofstream output;
    output.open(arquivo);
    if(output.fail()){
        output.close();
        throw new logic_error("Erro ao abrir o arquivo");
    }
    string texto;
    for(int i = 0; i < v->size(); i++){
        if(dynamic_cast<Funcionario*> ((*v)[i]) != nullptr){
            Funcionario* funcionario = dynamic_cast<Funcionario*> ((*v)[i]);
            output << "F " << funcionario->getId() << " " << funcionario->getNome() << endl;
            output << funcionario->getRegistros()->size() << endl;
            for(vector<Registro*>::iterator i = funcionario->getRegistros()->begin(); i != funcionario->getRegistros()->end(); i++){
                if(dynamic_cast<Entrada*>(*i) != nullptr)
                    output << "E ";
                else
                    output << "S ";

                escreveData(output, ((*i)->getData()));

                if((*i)->isManual())
                    output << "1" << endl;
                else
                    output << "0" << endl;
            }

            funcionario = nullptr;
            delete funcionario;
        }
        else if(dynamic_cast<Aluno*>((*v)[i]) != nullptr){
            Aluno* aluno = dynamic_cast<Aluno*>((*v)[i]);
            output << "A " << aluno->getId() << " " << aluno->getNome() << endl;

            aluno = nullptr;
            delete aluno;
        }
        else{
            Visitante* visitante = dynamic_cast<Visitante*>((*v)[i]);
            output << "V " << visitante->getId() << " ";
            output << visitante->getNome() << " ";
            escreveData(output, visitante->getDataInicio());
            output << " ";
            escreveData(output, visitante->getDataFim());

            output << endl;
            visitante = nullptr;
            delete visitante;
        }
    }
    output.close();
}

vector<Usuario*>* PersistenciaDeUsuario::carregar(string arquivo){
    vector<Usuario*>* usuarios = new vector<Usuario*>;
    char tipoDeUsuario;
    int id;
    string nome;
    ifstream input;
    input.open(arquivo);
    if(input.fail()){
        input.close();
        throw new logic_error("Falha ao abrir o arquivo");
    }

    input >> tipoDeUsuario;
    while(!input.eof()){
        input >> id;
        input >> nome;
        if(tipoDeUsuario == 'F'){
            int quantidadeDeRegistros;
            input >> quantidadeDeRegistros;
            vector<Registro*>* registros = leRegistros(input, quantidadeDeRegistros);
            usuarios->push_back(new Funcionario(id, nome, registros));

            registros = nullptr;
            delete registros;
        }
        else if(tipoDeUsuario == 'A'){
            usuarios->push_back(new Aluno(id, nome));
        }
        else{
            Data* dataInicio = leData(input);
            Data* dataFim = leData(input);

            usuarios->push_back(new Visitante(id, nome, dataInicio, dataFim));
            dataInicio = nullptr;
            dataFim = nullptr;

            delete dataInicio;
            delete dataFim;

        }

        input >> tipoDeUsuario;
    }

    if(!input.eof()){
        input.close();
        throw new logic_error("Arquivo com formatacao inesperada");
    }

    input.close();
    return usuarios;
}