#include "Catraca.h"
#include "PersistenciaDeUsuario.h"
#include "Visitante.h"
#include "Funcionario.h"
#include "Aluno.h"
#include <iostream>

using namespace std;

int printInicio()
{
    int opcao;
    cout << "Acesso ao Predio" << endl;
    cout << "1) Entrada " << endl;
    cout << "2) Saida " << endl;
    cout << "3) Registro manual" << endl;
    cout << "4) Cadastro de usuario" << endl;
    cout << "5) Relatorio " << endl;
    cout << "6) Configuracao " << endl;
    cout << "0) Sair" << endl;
    cout << "Escolha uma opcao: " << endl;
    cin >> opcao;
    return opcao;
}

Data *pegaData()
{
    int hora, minuto, segundo, dia, mes, ano;
    cout << "Hora: ";
    cin >> hora;
    cout << "Minuto: ";
    cin >> minuto;
    cout << "Segundo: ";
    cin >> segundo;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Ano: ";
    cin >> ano;

    Data *data = new Data(hora, minuto, segundo, dia, mes, ano);
    return data;
}

void abreCatraca(bool entrada, Catraca *catraca0, Catraca *catraca1)
{
    int id, catraca;
    bool abriu;
    Data *data = nullptr;
    cout << "Catraca: ";
    cin >> catraca;
    cout << "Id: ";
    cin >> id;
    data = pegaData();

    if (entrada)
    {
        if (!catraca)
            abriu = catraca0->entrar(id, data);
        else
            abriu = catraca1->entrar(id, data);
        cout << "[Entrada] ";
    }
    else
    {
        if (!catraca)
        {
            abriu = catraca0->sair(id, data);
        }
        else
            abriu = catraca1->sair(id, data);
        cout << "[Saida] ";
    }
    data = nullptr;
    delete data;
    if (abriu)
        cout << "Catraca " << catraca << " abriu: id " << id << endl;
    else
        cout << "Catraca " << catraca << " travada" << endl;
}

void menu()
{
    char carregar;

    PersistenciaDeUsuario *persist = new PersistenciaDeUsuario();
    cout << "Deseja carregar os usuarios (s/n): ";
    cin >> carregar;
    GerenciadorDeUsuario *gerenciador = nullptr;
    if (carregar == 's')
    {
        gerenciador = new GerenciadorDeUsuario(persist->carregar("dados.txt"));
    }
    else
        gerenciador = new GerenciadorDeUsuario;

    Catraca *catraca0 = new Catraca(gerenciador);
    Catraca *catraca1 = new Catraca(gerenciador);

    int opcao,
        id;
    bool sair = 0;
    while (!sair)
    {
        opcao = printInicio();

        if (opcao == 1)
        {
            abreCatraca(true, catraca0, catraca1);
        }

        if (opcao == 2)
        {
            abreCatraca(false, catraca0, catraca1);
        }

        if (opcao == 3)
        {
            char modo;
            int id;
            bool passou;
            Data *data = nullptr;
            cout << "Entrada (e) ou Saida (s)? ";
            cin >> modo;
            cout << "Id: ";
            cin >> id;
            data = pegaData();

            if (modo == 'e')
            {
                passou = gerenciador->getUsuario(id)->registrarEntradaManual(data);
                if (passou)
                    cout << "Entrada manual registrada: id " << id << endl;
                else
                    cout << "Erro ao registrar entrada manual" << endl;
            }
            else
            {
                passou = gerenciador->getUsuario(id)->registrarSaidaManual(data);
                if (passou)
                    cout << "Saida manual registrada: id " << id << endl;
                else
                    cout << "Erro ao registrar saida manual" << endl;
            }

            delete data;
        }

        if (opcao == 4)
        {
            string nome;
            char tipo;

            cout << "Tipo (v, a ou f): ";
            cin >> tipo;

            cout << "Id: " << endl;
            cin >> id;
            cout << "Nome: " << endl;
            cin >> nome;
            if (tipo == 'v')
            {
                cout << "Data de inicio";
                Data *dataInicio = pegaData();
                cout << "Data de fim";
                Data *dataFim = pegaData();
                gerenciador->adicionar(new Visitante(id, nome, dataInicio, dataFim));
                dataInicio = nullptr;
                delete dataInicio;
                dataFim = nullptr;
                delete dataFim;
            }
            else
            {
                if (tipo == 'a')
                    gerenciador->adicionar(new Aluno(id, nome));
                else
                    gerenciador->adicionar(new Funcionario(id, nome));
            }
            cout << "Usuario cadastrado com sucesso" << endl;
        }

        if (opcao == 5)
        {
            int ano, mes;
            Funcionario *usuario = nullptr;
            cout << "Mes: " << endl;
            cin >> mes;
            cout << "Ano: " << endl;
            cin >> ano;
            cout << "Relatorio de horas trabalhadas" << endl;
            for (int j = 0; j < gerenciador->getUsuarios()->size(); j++)
            {
                if (usuario = dynamic_cast<Funcionario *>((*gerenciador->getUsuarios())[j]))
                    cout << usuario->getNome() << ": " << usuario->getHorasTrabalhadas(mes, ano) << endl;
            }
            usuario = nullptr;
            delete usuario;
        }

        if (opcao == 6)
        {
            int hora, minuto;
            cout << "Horario de fim da janela dos Alunos" << endl;
            cout << "Hora: ";
            cin >> hora;
            cout << "Minuto: ";
            cin >> minuto;
            Aluno::setHorarioFim(hora, minuto);
        }

        if (opcao == 0){
            char salvar;
            cout << "Deseja salvar os usuarios (s/n): ";
            cin >> salvar;
            if(salvar == 's')
                persist->salvar("exemplo.txt", gerenciador->getUsuarios());
            sair = 1;
        }
    }
}