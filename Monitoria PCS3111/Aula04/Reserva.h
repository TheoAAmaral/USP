/*
 * Coloque a definicao da classe aqui. Use as diretivas adequadas e
 * inclua os arquivos e/ou bibliotecas necessarios para a classe.
 *
 *  Os atributos devem ser acessiveis somente internamente ao escopo
 *  da classe
 */
#ifndef RESERVA_H
#define RESERVA_H


class Reserva{
private:
    int quantidadeDeAlunos = 0;
    int numeroDaSala = 0;
    int horaDeInicio = 0;
public:
    void setNumeroDaSala(int numeroDaSala);
    void setQuantidadeDeAlunos(int quantidadeDeAlunos);
    void setHoraDeInicio(int horaDeInicio);
    int getNumeroDaSala();
    int getQuantidadeDeAlunos();
    int getHoraDeInicio();
    int calcularDuracao();
    void imprimir();
};

#endif