#ifndef PACOTE_FINAL_DE_SEMANA_H
#define PACOTE_FINAL_DE_SEMANA_H

// Faca os includes necessarios
#include <string>
#include "Reserva.h"

using namespace std;

class PacoteDeFinalDeSemana: public Reserva {
private:
public:
    PacoteDeFinalDeSemana(Quarto* quarto, int inicio, bool temCafe);
    virtual ~PacoteDeFinalDeSemana();
};
#endif

