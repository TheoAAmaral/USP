#ifndef PERSISTENCIADEUSUARIO_H
#define PERSISTENCIADEUSUARIO_H

#include "Usuario.h"
#include <vector>

class PersistenciaDeUsuario{
    public:
        PersistenciaDeUsuario();
        virtual ~PersistenciaDeUsuario();

        vector<Usuario*>* carregar(string arquivo);
        void salvar(string arquivo, vector<Usuario*>* v);
};
#endif