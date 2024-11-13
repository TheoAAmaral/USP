#ifndef SEMESPACO_H
#define SEMESPACO_H
#include <stdexcept>
using namespace std;

class SemEspaco: public logic_error{
    public:
        SemEspaco(string mensagem);
        ~SemEspaco();
};

#endif