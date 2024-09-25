#include "Catraca.h"
#include <iostream>

using namespace std;

int printInicio(){
    int opcao;
    cout <<"Acesso ao Predio" <<endl;
    cout <<"1) Entrada " <<endl;
    cout <<"2) Saida " <<endl;
    cout <<"3) Registro manual" <<endl;
    cout <<"4) Cadastro de usuario" <<endl;
    cout <<"5) Relatorio " <<endl;
    cout <<"0) Sair" <<endl;
    cout <<"Escolha uma opcao: " <<endl;
    cin >> opcao;
    return opcao;
}

Data* getData(){
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

void menu(){
    GerenciadorDeUsuario *gerenciador = new GerenciadorDeUsuario(10);
    Catraca *catraca0 = new Catraca(gerenciador);
    Catraca *catraca1 = new Catraca(gerenciador);

    int opcao,
        id;
    bool sair = 0;
    while(!sair){
        opcao = printInicio();
        
        if(opcao == 1){
            int catraca, id;
            bool abriu;
            Data *data = nullptr;
            cout << "Catraca: ";
            cin >> catraca;
            cout << "Id: ";
            cin >> id;
            data = getData();
            if(!catraca)
                abriu = catraca0->entrar(id, data);
            else
                abriu = catraca1->entrar(id, data);

            if(abriu)
                cout << "[Entrada] Catraca " << catraca << " abriu: id " << id << endl;
            else
                cout << "[Entrada] Catraca " << catraca << " travada" << endl;
            delete data;
        }

        if(opcao == 2){
            int catraca, id;
            bool abriu;
            Data *data = nullptr;
            cout << "Catraca: ";
            cin >> catraca;
            cout << "Id: ";
            cin >> id;
            data = getData();
            if(!catraca)
                abriu = catraca0->sair(id, data);
            else
                abriu = catraca1->sair(id, data);

            if(abriu)
                cout << "[Saida] Catraca " << catraca << " abriu: id " << id << endl;
            else
                cout << "[Saida] Catraca " << catraca << " travada" << endl;

            delete data;
        }

        if(opcao == 3){
            char modo;
            int id;
            bool passou;
            Data *data = nullptr;
            cout << "Entrada (e) ou Saida (s)? ";
            cin >> modo;
            cout << "Id: ";
            cin >> id;
            data = getData();

            if(modo == 'e'){
                passou = gerenciador->getUsuario(id)->registrarEntradaManual(data);
                if(passou)
                    cout << "Entrada manual registrada: id " << id << endl;
                else
                    cout << "Erro ao registrar entrada manual" << endl;
            }
            else{
                passou = gerenciador->getUsuario(id)->registrarSaidaManual(data);
                if(passou)
                    cout << "Saida manual registrada: id " << id << endl;
                else
                    cout << "Erro ao registrar saida manual" << endl;
            }
            
            delete data;    
        } 
        
        if(opcao == 4){
            string nome;
            cout <<"Id: " <<endl;
            cin >> id;
            cout <<"Nome: " <<endl;
            cin >> nome;
            Usuario *usuario = new Usuario(id, nome, 10);
            gerenciador -> adicionar(usuario);
            cout <<"Usuario cadastrado com sucesso" <<endl;
        }
        
        if(opcao == 5){
            int ano, mes;
            Usuario *usuario = nullptr;
            cout<< "Mes: " <<endl;
            cin >> mes;
            cout <<"Ano: " <<endl;
            cin >> ano;
            cout <<"Relatorio de horas trabalhadas" <<endl;
            for(int j=0;j<gerenciador->getQuantidade();j++){
                usuario = gerenciador->getUsuarios()[j];
                cout << usuario->getNome() << ": " << usuario->getHorasTrabalhadas(mes, ano) << endl;
            }
            delete usuario;
        }
        
        if(opcao == 0)
            sair = 1;
    }    
}